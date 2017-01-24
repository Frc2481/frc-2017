#include "pch.h"
#include "RobotState.h"

RobotState::RobotState() {
	reset(0, RigidTransform2D(), Rotation2D());
//	m_instance = RobotState();
}
//
//RobotState RobotState::getInstance() {
//	return m_instance;
//}

void RobotState::reset(double startTime, RigidTransform2D initialFieldToVehicle, Rotation2D initialTurretRotation) {
	m_fieldToVehicle = InterpolatingMap<InterpolatingDouble, RigidTransform2D>(kObservationBufferSize);
	m_fieldToVehicle.put(InterpolatingDouble(startTime), initialFieldToVehicle);
	m_vehicleVelocity = RigidTransform2D::Delta::Delta(0, 0, 0);
	m_turretRotation = InterpolatingMap<InterpolatingDouble, Rotation2D>(kObservationBufferSize);
	m_turretRotation.put(InterpolatingDouble(startTime), initialTurretRotation);
	m_goalTracker = GoalTracker();
	m_cameraPitchCorrection = Rotation2D::fromDegrees(-Constants::kCameraPitchAngleDegrees);
	m_cameraYawCorrection = Rotation2D::fromDegrees(-Constants::kCameraYawAngleDegrees);
	m_differentialHeight = Constants::kCenterOfTargetHeight - Constants::kCameraZOffset;
}

RigidTransform2D RobotState::getFieldToVehicle(double timeStamp) {
	return m_fieldToVehicle.getInterpolated(InterpolatingDouble(timeStamp));
}

RigidTransform2D RobotState::getPredictedFieldToVehicle(double lookAheadTime) {
	return getLatestFieldToVehicle().transformBy(RigidTransform2D::fromVelocity(RigidTransform2D::Delta(m_vehicleVelocity.m_dx * lookAheadTime,
		m_vehicleVelocity.m_dy * lookAheadTime, m_vehicleVelocity.m_dtheta * lookAheadTime)));
}

Rotation2D RobotState::getTurretRotation(double timeStamp) {
	return m_turretRotation.getInterpolated(InterpolatingDouble(timeStamp));
}

RigidTransform2D RobotState::getFieldToTurretRotated(double timeStamp) {
	InterpolatingDouble key = InterpolatingDouble(timeStamp);
	return m_fieldToVehicle.getInterpolated(key).transformBy(kVehicleToTurretFixed).transformBy(RigidTransform2D::fromRotation(m_turretRotation.getInterpolated(key)));
}

RigidTransform2D RobotState::getFieldToCamera(double timeStamp) {
	return getFieldToTurretRotated(timeStamp).transformBy(kTurretRotatingToCamera);
}

void RobotState::addFieldToVehicleObservation(double timeStamp, RigidTransform2D observation) {
	m_fieldToVehicle.put(InterpolatingDouble(timeStamp), observation);
}

void RobotState::addTurretRotationObservation(double timeStamp, Rotation2D observation) {
	m_turretRotation.put(InterpolatingDouble(timeStamp), observation);
}

void RobotState::addObservations(double timeStamp, RigidTransform2D field_to_vehicle, Rotation2D turret_rotation, RigidTransform2D::Delta velocity) {
	addFieldToVehicleObservation(timeStamp, field_to_vehicle);
	addTurretRotationObservation(timeStamp, turret_rotation);
	m_vehicleVelocity = velocity;
}

void RobotState::resetVision() {
	m_goalTracker.reset();
}

RigidTransform2D RobotState::generateOdemetryFromSensors(double frEncoderDeltaDistance, double flEncoderDeltaDistance, double brEncoderDeltaDistance,
	double blEncoderDeltaDistance, double frRotationDeltaDistance, double flRotationDeltaDistance, double brRotationDeltaDistance, double blRotationDeltaDistance, Rotation2D currentGyroAngle) {
	RigidTransform2D lastMeasurement = getLatestFieldToVehicle();
	return Kinematics::integrateForwardKinematics(lastMeasurement, frEncoderDeltaDistance, flEncoderDeltaDistance, brEncoderDeltaDistance, blEncoderDeltaDistance,
		frRotationDeltaDistance, flRotationDeltaDistance, brRotationDeltaDistance, blRotationDeltaDistance, currentGyroAngle);
}

RigidTransform2D RobotState::getLatestFieldToVehicle() {
	return m_fieldToVehicle.rbegin()->second;
}

Rotation2D RobotState::getLatestTurretRotation() {
	return m_turretRotation.rbegin()->second;
}

void RobotState::setVehicleToTurretFixed() {
	kVehicleToTurretFixed = RigidTransform2D(Translation2D(Constants::kTurretXOffset, Constants::kTurretYOffset), Rotation2D::fromDegrees(Constants::kTurretAngleOffsetDegrees));
}

void RobotState::setTurretRotatingToCamera() {
	kTurretRotatingToCamera = RigidTransform2D(Translation2D(Constants::kCameraXOffset, Constants::kCameraYOffset), Rotation2D());
}