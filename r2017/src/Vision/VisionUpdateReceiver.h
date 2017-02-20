/*
 * VisionUpdateReceiver.h
 *
 *  Created on: Feb 3, 2017
 *      Author: kyle
 */

#ifndef SRC_VISION_VISIONUPDATERECEIVER_H_
#define SRC_VISION_VISIONUPDATERECEIVER_H_

#include "VisionUpdate.h"

class VisionUpdateReceiver {
public:
	VisionUpdateReceiver() {}
	virtual ~VisionUpdateReceiver() {}
	virtual void gotUpdate(VisionUpdate update) = 0;
};

#endif /* SRC_VISION_VISIONUPDATERECEIVER_H_ */
