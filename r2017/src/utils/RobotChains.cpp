#include <utils/RobotChains.h>
#include <cmath>

RobotChains::RobotChains() : m_vehicleVelocity(0,0,0) {
	reset(0, RigidTransform2D(), Rotation2D());
//	m_instance = RobotState();
}
//
//RobotState RobotState::getInstance() {
//	return m_instance;
//}

void RobotChains::reset(double startTime, RigidTransform2D initialFieldToVehicle, Rotation2D initialTurretRotation) {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	m_fieldToVehicle = InterpolatingMap<InterpolatingDouble, RigidTransform2D>(kObservationBufferSize);
	m_fieldToVehicle.put(InterpolatingDouble(startTime), initialFieldToVehicle);
	m_vehicleVelocity = RigidTransform2D::Delta(0, 0, 0);
	m_turretRotation = InterpolatingMap<InterpolatingDouble, Rotation2D>(kObservationBufferSize);
	m_turretRotation.put(InterpolatingDouble(startTime), initialTurretRotation);
	m_goalTracker = GoalTracker();
	m_cameraPitchCorrection = Rotation2D::fromDegrees(-Constants::kCameraPitchAngleDegrees);
	m_cameraYawCorrection = Rotation2D::fromDegrees(-Constants::kCameraYawAngleDegrees);
	m_differentialHeight = Constants::kCenterOfTargetHeight - Constants::kCameraZOffset;
}

RigidTransform2D RobotChains::getFieldToVehicle(double timeStamp) {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	return m_fieldToVehicle.getInterpolated(InterpolatingDouble(timeStamp));
}

RigidTransform2D RobotChains::getPredictedFieldToVehicle(double lookAheadTime) {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	return getLatestFieldToVehicle().transformBy(RigidTransform2D::fromVelocity(RigidTransform2D::Delta(m_vehicleVelocity.m_dx * lookAheadTime,
		m_vehicleVelocity.m_dy * lookAheadTime, m_vehicleVelocity.m_dtheta * lookAheadTime)));
}

Rotation2D RobotChains::getTurretRotation(double timeStamp) {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	return m_turretRotation.getInterpolated(InterpolatingDouble(timeStamp));
}

RigidTransform2D RobotChains::getFieldToTurretRotated(double timeStamp) {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	InterpolatingDouble key = InterpolatingDouble(timeStamp);
	return m_fieldToVehicle.getInterpolated(key).transformBy(kVehicleToTurretFixed).transformBy(RigidTransform2D::fromRotation(m_turretRotation.getInterpolated(key)));
}

RigidTransform2D RobotChains::getFieldToCamera(double timeStamp) {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	return getFieldToTurretRotated(timeStamp).transformBy(kTurretRotatingToCamera);
}

void RobotChains::addFieldToVehicleObservation(double timeStamp, RigidTransform2D observation) {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	m_fieldToVehicle.put(InterpolatingDouble(timeStamp), observation);
}

void RobotChains::addTurretRotationObservation(double timeStamp, Rotation2D observation) {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	m_turretRotation.put(InterpolatingDouble(timeStamp), observation);
}

void RobotChains::addObservations(double timeStamp, RigidTransform2D field_to_vehicle, /*Rotation2D turret_rotation,*/ RigidTransform2D::Delta velocity) {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	addFieldToVehicleObservation(timeStamp, field_to_vehicle);
	//addTurretRotationObservation(timeStamp, turret_rotation);
	m_vehicleVelocity = velocity;
}

void RobotChains::addVisionUpdate(double timeStamp, std::list<TargetInfo> visionUpdate) {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	std::list<Translation2D> fieldToGoals;
	RigidTransform2D fieldToCamera = getFieldToCamera(timeStamp);
	
	if (!(visionUpdate.begin() == visionUpdate.end() || visionUpdate.size() == 0)) {
		for (TargetInfo target : visionUpdate) {
			double yDeadBand = (target.getY() > -Constants::kCameraDeadBand && target.getY() < Constants::kCameraDeadBand) ? 0.0 : target.getY();

			double xYaw = target.getX() * m_cameraYawCorrection.getCos() + yDeadBand * m_cameraYawCorrection.getSin();
			double yYaw = yDeadBand * m_cameraYawCorrection.getCos() - target.getX() * m_cameraYawCorrection.getSin();
			double zYaw = target.getZ();

			double xPitch = zYaw * m_cameraPitchCorrection.getSin() + xYaw * m_cameraPitchCorrection.getCos();
			double yPitch = yYaw;
			double zPitch = zYaw * m_cameraPitchCorrection.getCos() - xYaw * m_cameraPitchCorrection.getSin();

			if (zPitch > 0) {
				double scaling = m_differentialHeight / zPitch;
				double distance = hypot(xPitch, yPitch) * scaling;
				Rotation2D angle = Rotation2D(xPitch, yPitch, true);
				fieldToGoals.push_back(fieldToCamera.transformBy(RigidTransform2D::fromTranslation(
					Translation2D(distance * angle.getCos(), distance * angle.getSin()))).getTranslation());
			}
		}
	}
	m_goalTracker.update(timeStamp, fieldToGoals);
}

std::list<ShooterAimingParameters> RobotChains::getAimingParameters(double currentTimeStamp) {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	std::list<ShooterAimingParameters> rv;
	std::list<GoalTracker::TrackReport> reports = m_goalTracker.getTracks();

	RigidTransform2D latestTurretFixedToField = getPredictedFieldToVehicle(Constants::kAutoAimPredictionTime).transformBy(kVehicleToTurretFixed).inverse();

	for (GoalTracker::TrackReport report : reports) {
		if (currentTimeStamp - report.m_latestTimestamp > kMaxTargetAge) {
			continue;
		}
		RigidTransform2D latestTurretFixedToGoal = latestTurretFixedToField.transformBy(RigidTransform2D::fromTranslation(report.m_fieldToGoal));

		rv.push_back(ShooterAimingParameters(latestTurretFixedToGoal.getTranslation().norm(), Rotation2D(latestTurretFixedToGoal.getTranslation().getX(),
			latestTurretFixedToGoal.getTranslation().getY(),true), report.m_id));
	}
	return rv;
}

std::list<RigidTransform2D> RobotChains::getCaptureTimeFieldToGoal() {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	std::list<RigidTransform2D> rv;
	
	for (GoalTracker::TrackReport report : m_goalTracker.getTracks()) {
		rv.push_back(RigidTransform2D::fromTranslation(report.m_fieldToGoal));
	}
	return rv;
}

void RobotChains::resetVision() {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	m_goalTracker.reset();
}

RigidTransform2D RobotChains::generateOdometryFromSensors(double frEncoderDeltaDistance, double flEncoderDeltaDistance, double brEncoderDeltaDistance,
	double blEncoderDeltaDistance, double frRotationDeltaDistance, double flRotationDeltaDistance, double brRotationDeltaDistance, double blRotationDeltaDistance, Rotation2D currentGyroAngle) {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	RigidTransform2D lastMeasurement = getLatestFieldToVehicle();
	return Kinematics::integrateForwardKinematics(lastMeasurement, frEncoderDeltaDistance, flEncoderDeltaDistance, brEncoderDeltaDistance, blEncoderDeltaDistance,
		frRotationDeltaDistance, flRotationDeltaDistance, brRotationDeltaDistance, blRotationDeltaDistance, currentGyroAngle);
}

RigidTransform2D RobotChains::getLatestFieldToVehicle() {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	return m_fieldToVehicle.rbegin()->second;
}

Rotation2D RobotChains::getLatestTurretRotation() {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	return m_turretRotation.rbegin()->second;
}

void RobotChains::setVehicleToTurretFixed() {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	kVehicleToTurretFixed = RigidTransform2D(Translation2D(Constants::kTurretXOffset, Constants::kTurretYOffset), Rotation2D::fromDegrees(Constants::kTurretAngleOffsetDegrees));
}

void RobotChains::setTurretRotatingToCamera() {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	kTurretRotatingToCamera = RigidTransform2D(Translation2D(Constants::kCameraXOffset, Constants::kCameraYOffset), Rotation2D());
}

GoalTracker RobotChains::getGoalTracker() {
	std::lock_guard<std::recursive_mutex> lk(m_mutex);
	return m_goalTracker;
}

RobotChains* RobotChains::getInstance() {
	static RobotChains instance;
	return &instance;
}
