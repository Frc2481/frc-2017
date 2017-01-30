/*
 * SetCameraModeMessage.h
 *
 *  Created on: Jan 27, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_VISION_MESSAGES_SETCAMERAMODEMESSAGE_H_
#define SRC_VISION_MESSAGES_SETCAMERAMODEMESSAGE_H_

#include <string>

class SetCameraModeMessage {
public:
	virtual ~SetCameraModeMessage();
	static SetCameraModeMessage getVisionModeMessage();
	static SetCameraModeMessage getIntakeModeMessage();
	const char* getType();
	const char* getMessage();

private:
	static std::string kVisionMode;
	static std::string kIntakeMode;
	std::string m_message;
	SetCameraModeMessage(std::string message);
};

#endif /* SRC_VISION_MESSAGES_SETCAMERAMODEMESSAGE_H_ */
