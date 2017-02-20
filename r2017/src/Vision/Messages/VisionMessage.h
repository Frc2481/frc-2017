/*
 * VisionMessage.h
 *
 *  Created on: Jan 27, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_VISION_MESSAGES_VISIONMESSAGE_H_
#define SRC_VISION_MESSAGES_VISIONMESSAGE_H_

#include <string>

class VisionMessage {
public:
	VisionMessage();
	virtual ~VisionMessage();
	virtual const std::string getType() = 0;
	virtual const std::string getMessage() = 0;
	const std::string toJson();
};

#endif /* SRC_VISION_MESSAGES_VISIONMESSAGE_H_ */
