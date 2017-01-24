#pragma once
#include "Constants.h"
#include "GoalTracker.h"
#include "InterpolatingDouble.h"
#include "InterpolatingMap.h"
#include "RigidTransform2D.h"
#include "Rotation2D.h"
#include "Translation2D.h"
#include "Kinematics.h"

class RobotState {
private:
	//static RobotState m_instance;
	RigidTransform2D kVehicleToTurretFixed;
	RigidTransform2D kTurretRotatingToCamera;
protected:
	InterpolatingMap<InterpolatingDouble, RigidTransform2D> m_fieldToVehicle;
	RigidTransform2D::Delta m_vehicleVelocity;
	InterpolatingMap<InterpolatingDouble, Rotation2D> m_turretRotation;
	GoalTracker m_goalTracker;
	Rotation2D m_cameraPitchCorrection;
	Rotation2D m_cameraYawCorrection;
	double m_differentialHeight;

	RobotState();
public:
	//static RobotState getInstance();
	const int kObservationBufferSize = 100;
	const double kMaxTargetAge = 0.4;
	//const RigidTransform2D kVehicleToTurretFixed = RigidTransform2D(Translation2D(Constants::kTurretXOffset, Constants::kTurretYOffset), Rotation2D::fromDegrees(Constants::kTurretAngleOffsetDegrees));
	//const RigidTransform2D kTurretRotatingToCamera = RigidTransform2D(Translation2D(Constants::kCameraXOffset, Constants::kCameraYOffset), Rotation2D());
	void reset(double startTime, RigidTransform2D initialFieldToVehicle, Rotation2D initialTurretRotation);
	RigidTransform2D getFieldToVehicle(double timeStamp);
	RigidTransform2D getPredictedFieldToVehicle(double lookAheadTime);
	Rotation2D getTurretRotation(double timeStamp);
	RigidTransform2D getFieldToTurretRotated(double timeStamp);
	RigidTransform2D getFieldToCamera(double timeStamp);
	void addFieldToVehicleObservation(double timeStamp, RigidTransform2D observation);
	void addTurretRotationObservation(double timeStamp, Rotation2D observation);
	void addObservations(double timeStamp, RigidTransform2D field_to_vehicle, Rotation2D turret_rotation, RigidTransform2D::Delta velocity);
	void addVisionUpdate(double timeStamp, std::list<TargetInfo> visionUpdate);
	std::list<ShooterAimingParameters> getAimingParameters(double currentTimeStamp); //std::comparator);
	std::list<RigidTransform2D> getCaptureTimeFieldToGoal();
	Rotation2D getLatestTurretRotation();
	RigidTransform2D getLatestFieldToVehicle();
	void resetVision();
	RigidTransform2D generateOdemetryFromSensors(double frEncoderDeltaDistance, double flEncoderDeltaDistance, double brEncoderDeltaDistance,
		double blEncoderDeltaDistance, double frRotationDeltaDistance, double flRotationDeltaDistance, double brRotationDeltaDistance, double blRotationDeltaDistance, Rotation2D currentGyroAngle);
	void outputToSmartDashboard();
	void setVehicleToTurretFixed();
	void setTurretRotatingToCamera();
};