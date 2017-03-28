/*
 * TrajectoryFollowerLooper.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: Team2481
 */

#include <Loops/TrajectoryFollowerLooper.h>
#include "Components/TrajectoryFollower.h"
#include "Subsystems/DriveTrain.h"

TrajectoryFollowerLooper::TrajectoryFollowerLooper(int interval, DriveTrain *driveTrain) : Looper(interval){
	m_flSteer = driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->GetMotor(SwerveModule::STEER_MOTOR);
	m_frSteer = driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE)->GetMotor(SwerveModule::STEER_MOTOR);
	m_blSteer = driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->GetMotor(SwerveModule::STEER_MOTOR);
	m_brSteer = driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE)->GetMotor(SwerveModule::STEER_MOTOR);
	m_flDrive = driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR);
	m_frDrive = driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR);
	m_blDrive = driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR);
	m_brDrive = driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR);
}

TrajectoryFollowerLooper::~TrajectoryFollowerLooper() {
	// TODO Auto-generated destructor stub
}

void TrajectoryFollowerLooper::OnLoop() {
	m_flSteer->ProcessMotionProfileBuffer();
	m_frSteer->ProcessMotionProfileBuffer();
	m_blSteer->ProcessMotionProfileBuffer();
	m_brSteer->ProcessMotionProfileBuffer();
	m_flDrive->ProcessMotionProfileBuffer();
	m_frDrive->ProcessMotionProfileBuffer();
	m_blDrive->ProcessMotionProfileBuffer();
	m_brDrive->ProcessMotionProfileBuffer();
}

void TrajectoryFollowerLooper::OnStart() {
}

void TrajectoryFollowerLooper::OnStop() {
}

void TrajectoryFollowerLooper::SetActive(bool active) {
	Looper::SetActive(active);
}
