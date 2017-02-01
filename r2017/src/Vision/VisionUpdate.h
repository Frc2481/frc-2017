/*
 * VisionUpdate.h
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_VISION_VISIONUPDATE_H_
#define SRC_VISION_VISIONUPDATE_H_

#include "json.h"
using namespace nlohmann;

class VisionUpdate {
public:
	VisionUpdate();
	bool m_valid;
	long m_capturedAgoMs;
	std::list<TargetInfo> m_targets;
	double m_capturedAtTimestamp;
	static long m_getOptLong( n, long defaultValue);

};

#endif /* SRC_VISION_VISIONUPDATE_H_ */
