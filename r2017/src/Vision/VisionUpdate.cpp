
/*
 * VisionUpdate.cpp
 *
 *  Created on: Jan 31, 2017
 *      Author: FIRSTMentor
 */

#include "VisionUpdate.h"

VisionUpdate::VisionUpdate()
	: m_valid(false), m_capturedAgoMs(0), m_capturedAtTimestamp(0) {}

static VisionUpdate generateFromJsonString(double currentTime, std::string updateString) {
	VisionUpdate update;
	json obj = json::parse(updateString);
	if(obj.find("capturedAgoMs") == obj.end()){
		update.m_valid = false;
		return update;
	}

	update.m_capturedAgoMs = obj["capturedAgoMs"];
	update.m_capturedAtTimestamp = currentTime - update.m_capturedAgoMs / 1000.0;
	if(obj.find("targets") == obj.end()) {
		update.m_valid = false;
		return update;
	}
	std::list<json> targets =  obj["targets"];
	std::list<TargetInfo> targetInfos;
	for(json targetObj : targets){
		json target = (json) targetObj;
		double y;
		double z;
		if(obj.find("y") == obj.end()){
			update.m_valid = false;
			return update;
		}
		y = obj["y"];

		if(obj.find("z") == obj.end()){
			update.m_valid = false;
			return update;
		}
		z = obj["z"];
		targetInfos.push_back(TargetInfo(y, z));
	}
	update.m_targets = targetInfos;
	update.m_valid = true;
	return update;
}

std::list<TargetInfo> VisionUpdate::getTargets() const {
	return m_targets;
}



bool VisionUpdate::isValid() const {
	return m_valid;
}

long VisionUpdate::getCapturedAgoMs() const {
	return m_capturedAgoMs;

}

double VisionUpdate::getCapturedAtTimestamp() const {
	return m_capturedAtTimestamp;
}
