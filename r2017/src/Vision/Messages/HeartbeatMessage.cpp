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

const char* HeartbeatMessage::getType(){
	return std::string("heartbeat").c_str();
}

const char* HeartbeatMessage::getMessage(){
	return std::string("{}").c_str();
}
