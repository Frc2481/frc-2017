/*
 * HeartbeatMessage.cpp
 *
 *  Created on: Jan 27, 2017
 *      Author: FIRSTMentor
 */

#include <string>
#include <Vision/Messages/HeartbeatMessage.h>

HeartbeatMessage::HeartbeatMessage() {}

HeartbeatMessage::~HeartbeatMessage() {}

const std::string HeartbeatMessage::getType(){
	return std::string("heartbeat");
}

const std::string HeartbeatMessage::getMessage(){
	return std::string("{}");
}
