/*
 * VisionProcessor.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: Team2481
 */

#include <Loops/VisionProcessor.h>
#include "Vision/TargetInfo.h"

VisionProcessor::VisionProcessor() : m_processed(false), m_eligible(false){
	// TODO Auto-generated constructor stub

}

VisionProcessor::~VisionProcessor() {
	// TODO Auto-generated destructor stub
}

void VisionProcessor::OnStart() {
	if(!Looper::m_started){
		Looper::m_thread = std::thread(&VisionProcessor::OnLoop);
	}
}

void VisionProcessor::OnLoop() {
	if(!m_processed){
		VisionUpdate update = m_update;
		{
			std::lock_guard<std::mutex> lk(m_mutex);
			m_processed = true;
		}
		std::list<TargetInfo> infos = update.getTargets();
		for(auto iit = infos.begin(); iit != infos.end(); iit++){
			for(auto jit = iit; jit != infos.end(); jit++){
				if(iit != jit){
					double deltaY = fabs(iit->getY()) - fabs(jit->getY());
					double deltaZ = fabs(iit->getZ()) - fabs(jit->getZ());

					//Check for two targets of relatively equal height in image using Y value for gearTarget
					if(fabs(deltaY) < Constants::kGearYPosThreshold &&
						fabs(deltaZ) < Constants::kGearCameraWidth / 2.0){
						LiftTarget gearTarget(*iit, *jit);
						RobotChains::getInstance()->addVisionUpdateGear(update.getCapturedAtTimestamp(), gearTarget);
					}
//					else if(fabs(deltaZ) < Constants::kBoilerZPosThreshold &&
//							fabs(deltaY) < Constants::kBoilerYPosThreshold){
//						TargetInfo boilerTarget(iit, jit);
//						RobotChains::getInstance()->addVisionUpdateBoiler(update.getCapturedAtTimestamp(), boilerTarget);
//					}
				}
			}
		}
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
	m_update = update;
	m_processed = false;
}

void VisionProcessor::ProcessGearTarget(TargetInfo& left, TargetInfo& right) {
}
