/*
 * VisionMessage.cpp
 *
 *  Created on: Jan 27, 2017
 *      Author: FIRSTMentor
 */

#include "json.h"
#include <Vision/Messages/VisionMessage.h>
using namespace nlohmann;

VisionMessage::VisionMessage() {}

VisionMessage::~VisionMessage() {}

const std::string VisionMessage::toJson(){
	json obj;
	obj["type"] = getType();
	obj["message"] = getMessage();
	return std::string(obj.dump()).append("\n");
}
