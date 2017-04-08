/*
 * VisionProcessor.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: Team2481
 */

#include <Loops/VisionProcessor.h>
#include "Vision/TargetInfo.h"

VisionProcessor::VisionProcessor() : Looper(10000), m_processed(false), m_eligible(false){
	// TODO Auto-generated constructor stub

}

VisionProcessor::~VisionProcessor() {
	// TODO Auto-generated destructor stub
}

void VisionProcessor::OnStart() {}

void VisionProcessor::OnLoop() {
	if(!m_processed){
		m_onLoopCounter++;
		SmartDashboard::PutNumber("Vision OnLoop Counter", m_onLoopCounter);
		VisionUpdate update;
		{
			std::lock_guard<std::mutex> lk(m_mutex);
			m_processed = true;
			update = m_update;
		}
		std::list<TargetInfo> infos = update.getTargets();
		SmartDashboard::PutNumber("Info Size", infos.size());
		for(auto iit = infos.begin(); iit != infos.end(); iit++){
			for(auto jit = iit; jit != infos.end(); jit++){
				if(iit != jit){
					double deltaY = fabs(iit->getY() - jit->getY());
					double deltaZ = fabs(iit->getZ() - jit->getZ());

					//Check for two targets of relatively equal height in image using Y value for gearTarget
					if(deltaY < Constants::kGearYPosThreshold &&
						deltaZ < Constants::kGearCameraWidth / 2.0){
						TargetInfo &leftTarget = *iit;
						TargetInfo &rightTarget = *jit;
						if (leftTarget.getY() > rightTarget.getY()){
							leftTarget = *jit;
							rightTarget = *iit;
						}
						LiftTarget gearTarget(leftTarget, rightTarget);
						RobotChains::getInstance()->addVisionUpdateGear(update.getCapturedAtTimestamp(), gearTarget);
					}
					else if(fabs(deltaY) < Constants::kBoilerYPosThreshold){
						TargetInfo &boilerTarget = *iit;
						if(jit->getZ() > iit->getZ()){
							boilerTarget = *jit;
						}
						RobotChains::getInstance()->addVisionUpdateBoiler(update.getCapturedAtTimestamp(), boilerTarget);
					}
				}
			}
		}
		std::list<AimingParameters> params = RobotChains::getInstance()->getGearAimingParameters(frc::GetFPGATime());
	}
	else{
		return;
	}
}

void VisionProcessor::OnStop() {
}

VisionProcessor* VisionProcessor::GetInstance() {
	static VisionProcessor instance;
	return &instance;
}

void VisionProcessor::gotUpdate(VisionUpdate update) {
	std::lock_guard<std::mutex> lk(m_mutex);
	m_updatecounter++;
	SmartDashboard::PutNumber("GotUpdate Counter", m_updatecounter);
	m_update = update;
	m_processed = false;
}

void VisionProcessor::ProcessGearTarget(TargetInfo& left, TargetInfo& right) {
}

void VisionProcessor::LoopMe() {
	Looper::Loop();
}
