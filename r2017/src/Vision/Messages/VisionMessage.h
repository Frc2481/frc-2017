/*
 * VisionMessage.h
 *
 *  Created on: Jan 27, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_VISION_MESSAGES_VISIONMESSAGE_H_
#define SRC_VISION_MESSAGES_VISIONMESSAGE_H_

class VisionMessage {
public:
	VisionMessage();
	virtual ~VisionMessage();
	virtual const char* getType() = 0;
	virtual const char* getMessage() = 0;
	char* toJson();
};

#endif /* SRC_VISION_MESSAGES_VISIONMESSAGE_H_ */
