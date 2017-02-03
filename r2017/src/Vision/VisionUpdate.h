/*
 * VisionUpdate.h
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_VISION_VISIONUPDATE_H_
#define SRC_VISION_VISIONUPDATE_H_

#include <list>
#include "json.h"
using namespace nlohmann;
#include "Vision/TargetInfo.h"

class VisionUpdate {
public:
	VisionUpdate();
	bool m_valid;
	long m_capturedAgoMs;
	std::list<TargetInfo> m_targets;
	double m_capturedAtTimestamp;
	static double parseDouble(json j, std::string key);
	static VisionUpdate generateFromJsonString(double currentTime, std::string updateString);
	std::list<TargetInfo> getTargets();
	bool isValid();
	long getCapturedAgoMs();
	double getCapturedAtTimestamp();
};

#endif /* SRC_VISION_VISIONUPDATE_H_ */
