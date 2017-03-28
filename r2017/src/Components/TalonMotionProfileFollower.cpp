/*
 * TalonMotionProfileFollower.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: Team2481
 */

#include "Components/TalonMotionProfileFollower.h"
#include "Instrumentation.h"

TalonMotionProfileFollower::TalonMotionProfileFollower(CANTalon *talon) {
	m_talon = talon;
	m_talon->ChangeMotionControlFramePeriod(5);
	m_loopTimeout = 0;
	m_debug = false;
	m_started = false;
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
		if(m_status.isUnderrun == false){
			m_loopTimeout = kNumLoopsTimeout;
		}
		if(m_status.activePointValid && m_status.activePoint.isLastPoint){
			m_loopTimeout = -1;
			m_started = false;
			m_talon->Set(CANTalon::SetValueMotionProfileHold);
		}
	}
	if(m_debug){
		instrumentation::Process(m_status);
	}
}

void TalonMotionProfileFollower::LoadPath(const double profile[][3], int count) {
	CANTalon::TrajectoryPoint point;
	if(m_status.hasUnderrun){
		if(m_debug){
			instrumentation::OnUnderrun();
			m_talon->ClearMotionProfileHasUnderrun();
		}
	}
	m_talon->ClearMotionProfileTrajectories();
	m_talon->SetControlMode(CANSpeedController::kMotionProfile);
	m_talon->Set(CANTalon::SetValueMotionProfileDisable);
	for(int i = 0; i < count; i++) {
		point.position = profile[i][0];
		point.velocity = profile[i][1];
		point.timeDurMs = (int)profile[i][2];
		point.profileSlotSelect = 0;
		point.velocityOnly = false;
		point.zeroPos = i == 0;
		point.isLastPoint = i + 1 == count;
		m_talon->PushMotionProfileTrajectory(point);
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
	return m_loopTimeout == -1 && m_status.activePointValid && m_status.activePoint.isLastPoint;
}
