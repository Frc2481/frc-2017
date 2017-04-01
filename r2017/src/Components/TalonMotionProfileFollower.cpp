/*
 * TalonMotionProfileFollower.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: Team2481
 */

#include "Components/TalonMotionProfileFollower.h"
#include "Instrumentation.h"
#include <fstream>
#include <cstring>
#include <strstream>

TalonMotionProfileFollower::TalonMotionProfileFollower(CANTalon *talon, const std::string talonName, int pidSlot) {
	m_talon = talon;
	m_talon->ChangeMotionControlFramePeriod(5);
	m_pidSlot = pidSlot;
	m_loopTimeout = 0;
	m_debug = false;
	m_started = false;
	m_talonName = talonName;
	m_writeCSV = false;
}

TalonMotionProfileFollower::~TalonMotionProfileFollower() {
	// TODO Auto-generated destructor stub
}

void TalonMotionProfileFollower::Periodic() {
	m_talon->GetMotionProfileStatus(m_status);
	if(m_loopTimeout < 0){}
	else if(m_loopTimeout == 0){
		if(m_debug){
			instrumentation::OnNoProgress();
		}
	}
	else{
		m_loopTimeout--;
	}

	if(m_started){
		SmartDashboard::PutNumber("TalonError", m_status.activePoint.velocity - m_talon->GetSpeed());
		if(m_writeCSV) {
			m_outFile << frc::GetFPGATime() << ","
				<< m_talon->GetClosedLoopError() << ","
				<< m_talon->GetPosition() << ","
				<< m_status.activePoint.position << ","
				<< m_talon->GetSpeed() << ","
				<< m_status.activePoint.velocity << "\n";
		}

		if(m_status.isUnderrun == false){
			m_loopTimeout = kNumLoopsTimeout;
		}
		if(m_status.activePointValid && m_status.activePoint.isLastPoint){
			m_loopTimeout = -1;
			m_started = false;
			m_talon->Set(CANTalon::SetValueMotionProfileHold);
			if(m_writeCSV)
				m_outFile.close();
			m_talon->SetEncPosition(0);
			m_talon->ChangeMotionControlFramePeriod(100);
		}
	}
	if(m_debug){
		instrumentation::Process(m_status);
	}
}

void TalonMotionProfileFollower::LoadPath(const double profile[][3], int count) {
	if(m_writeCSV)
	{
		std::stringstream ss;
		ss << "/home/lvuser/MP" << m_talonName << frc::GetFPGATime() << ".csv";
		m_outFile.open(ss.str().c_str());
		m_outFile << "Current Time" << ","
				<< "ClosedLoopError" << ","
				<< "Current Pos" << ","
				<< "Target Pos" << ","
				<< "Current Speed" << ","
				<< "Target Speed" << ",\n";
	}
	CANTalon::TrajectoryPoint point;
	if(m_status.hasUnderrun){
		if(m_debug){
			instrumentation::OnUnderrun();
		}
		m_talon->ClearMotionProfileHasUnderrun();
	}
	m_talon->ClearMotionProfileTrajectories();
	m_talon->SetControlMode(CANSpeedController::kMotionProfile);
	m_talon->Set(CANTalon::SetValueMotionProfileDisable);
	for(int i = 0; i < count; i++) {
		point.position = profile[i][0];
		point.velocity = profile[i][1];
		point.timeDurMs = (int)profile[i][2];
		point.profileSlotSelect = m_pidSlot;
		point.velocityOnly = false;
		point.zeroPos = i == 0;
		point.isLastPoint = i + 1 == count;
		m_talon->PushMotionProfileTrajectory(point);
	}
	m_loopTimeout = kNumLoopsTimeout;
	m_talon->SetEncPosition(0);
}

void TalonMotionProfileFollower::LoadPath(CANTalon::TrajectoryPoint* profile, int count) {
	if(m_writeCSV)
	{
		std::stringstream ss;
		ss << "/home/lvuser/MP" << m_talonName << frc::GetFPGATime() << ".csv";
		m_outFile.open(ss.str().c_str());
		m_outFile << "Current Time" << ","
				<< "ClosedLoopError" << ","
				<< "Current Pos" << ","
				<< "Target Pos" << ","
				<< "Current Speed" << ","
				<< "Target Speed" << ",\n";
	}
	if(m_status.hasUnderrun){
		if(m_debug){
			instrumentation::OnUnderrun();
		}
		m_talon->ClearMotionProfileHasUnderrun();
	}
	m_talon->ClearMotionProfileTrajectories();
	m_talon->SetControlMode(CANSpeedController::kMotionProfile);
	m_talon->Set(CANTalon::SetValueMotionProfileDisable);
	for(int i = 0; i < count; i++) {
		//printf("%f\t %f\n", profile[i].position, profile[i].velocity);
		profile[i].profileSlotSelect = m_pidSlot;
		profile[i].velocityOnly = false;
		profile[i].zeroPos = i == 0;
		profile[i].isLastPoint = i + 1 == count;
		m_talon->PushMotionProfileTrajectory(profile[i]);
	}
	m_loopTimeout = kNumLoopsTimeout;
}

bool TalonMotionProfileFollower::IsReady() {
	return m_status.btmBufferCnt > kMinPointsInTalon;
}

void TalonMotionProfileFollower::RunPath() {
	m_talon->Set(CANTalon::SetValueMotionProfileEnable);
	m_started = true;
	m_loopTimeout = kNumLoopsTimeout;
}

bool TalonMotionProfileFollower::IsTimedOut() {
	return m_loopTimeout == 0;
}

bool TalonMotionProfileFollower::IsFinished() {
	printf("%d %d %d\n", m_loopTimeout, m_status.activePointValid, m_status.activePoint.isLastPoint);
	return m_loopTimeout == -1 && m_status.activePointValid && m_status.activePoint.isLastPoint;
}
