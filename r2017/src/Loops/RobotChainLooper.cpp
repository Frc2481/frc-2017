/*
 * RobotStateLooper.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: Team2481
 */

#include <Loops/RobotChainLooper.h>
#include <utils/RobotChains.h>

RobotChainLooper::RobotChainLooper(int interval) : Looper(interval) {
}

RobotChainLooper::~RobotChainLooper() {
	// TODO Auto-generated destructor stub
}

void RobotChainLooper::OnLoop() {
	double start;
	while (true){
		start = frc::GetFPGATime();

		double frDistance = frModule->GetDistance();
		double flDistance = flModule->GetDistance();
		double brDistance = brModule->GetDistance();
		double blDistance = blModule->GetDistance();
		double frRotation = frModule->GetAngle();
		double flRotation = flModule->GetAngle();
		double brRotation = brModule->GetAngle();
		double blRotation = blModule->GetAngle();
		Rotation2D frAngle = Rotation2D::fromDegrees(frModule->GetAngle());
		Rotation2D flAngle = Rotation2D::fromDegrees(flModule->GetAngle());
		Rotation2D brAngle = Rotation2D::fromDegrees(brModule->GetAngle());
		Rotation2D blAngle = Rotation2D::fromDegrees(blModule->GetAngle());

		RigidTransform2D odometry = RobotChains::getInstance()->generateOdometryFromSensors(frDistance - m_frPrevDistance,
				flDistance - m_flPrevDistance, brDistance - m_brPrevDistance, blDistance - m_blPrevDistance,
				frRotation - m_frPrevRotation,flRotation - m_frPrevRotation, brRotation - m_brPrevRotation, blRotation - m_blPrevRotation,
				CommandBase::m_driveTrain->GetAngle());

		RigidTransform2D::Delta velocity = Kinematics::forwardKinematics(CommandBase::m_driveTrain->GetFRVelocityInchesPerSec(), CommandBase::m_driveTrain->GetFLVelocityInchesPerSec(),
				CommandBase::m_driveTrain->GetBRVelocityInchesPerSec(), CommandBase::m_driveTrain->GetBLVelocityInchesPerSec(),
				frRotation - m_frPrevRotation,flRotation - m_frPrevRotation, brRotation - m_brPrevRotation, blRotation - m_blPrevRotation);

		RobotChains::getInstance()->addObservations(start, odometry, velocity);

		m_frPrevDistance = frDistance;
		m_flPrevDistance = flDistance;
		m_brPrevDistance = brDistance;
		m_blPrevDistance = blDistance;

		m_frPrevRotation = frRotation;
		m_flPrevRotation = flRotation;
		m_brPrevRotation = brRotation;
		m_blPrevRotation = blRotation;
	}
}

void RobotChainLooper::OnStart() {
	if(!Looper::m_started){
		m_flPrevDistance = flModule->GetDistance();
		m_frPrevDistance = frModule->GetDistance();
		m_blPrevDistance = blModule->GetDistance();
		m_brPrevDistance = brModule->GetDistance();
		m_flPrevRotation = flModule->GetAngle();
		m_frPrevRotation = frModule->GetAngle();
		m_blPrevRotation = blModule->GetAngle();
		m_brPrevRotation = brModule->GetAngle();
		Looper::m_thread = std::thread(&RobotChainLooper::OnLoop, this);
		m_started = true;
	}
}

void RobotChainLooper::OnStop() {
}

RobotChainLooper* RobotChainLooper::GetInstance() {
	if(!m_instance){
		m_instance = new RobotChainLooper(10000);
	}
	return m_instance;
}
