/*
 * SetCameraModeMessage.cpp
 *
 *  Created on: Jan 27, 2017
 *      Author: FIRSTMentor
 */

#include <Vision/Messages/SetCameraModeMessage.h>

std::string SetCameraModeMessage::kVisionMode = "vision";
std::string SetCameraModeMessage::kIntakeMode = "intake";

SetCameraModeMessage::~SetCameraModeMessage() {
	// TODO Auto-generated destructor stub
}

SetCameraModeMessage SetCameraModeMessage::getVisionModeMessage() {
	return SetCameraModeMessage(kVisionMode);
}

SetCameraModeMessage SetCameraModeMessage::getIntakeModeMessage() {
	return SetCameraModeMessage(kIntakeMode);
}

const char* SetCameraModeMessage::getType() {
	return "camera_mode";
}

const char* SetCameraModeMessage::getMessage() {
	return m_message.c_str();
}

SetCameraModeMessage::SetCameraModeMessage(std::string message)
	: m_message(message) {

}
