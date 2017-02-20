/*
 * HeartbeatMessage.h
 *
 *  Created on: Jan 27, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_VISION_MESSAGES_HEARTBEATMESSAGE_H_
#define SRC_VISION_MESSAGES_HEARTBEATMESSAGE_H_

#include <string>
#include "VisionMessage.h"

class HeartbeatMessage : public VisionMessage {
public:
	HeartbeatMessage();
	virtual ~HeartbeatMessage();
	const std::string getType();
	const std::string getMessage();
};

#endif /* SRC_VISION_MESSAGES_HEARTBEATMESSAGE_H_ */
