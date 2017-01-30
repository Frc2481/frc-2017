/*
 * OffWireMessage.cpp
 *
 *  Created on: Jan 27, 2017
 *      Author: FIRSTMentor
 */

//#include "json_c/json_object.h"
//#include "json_c/json_tokener.h"
#include <Vision/Messages/OffWireMessage.h>

OffWireMessage::OffWireMessage(std::string message) {
//	json_object* obj = json_tokener_parse(message.c_str());
//
//	json_object* typeObj;
//	if (json_object_object_get_ex(obj, "type", &typeObj)) {
//		m_valid = false;
//		return;
//	}
//	m_type = json_object_get_string(typeObj);
//
//	json_object* messageObj;
//	if (json_object_object_get_ex(obj, "message", &typeObj)) {
//		m_valid = false;
//		return;
//	}
//	m_message = json_object_get_string(messageObj);
//	m_valid = true;
}

OffWireMessage::~OffWireMessage() {
	// TODO Auto-generated destructor stub
}

bool OffWireMessage::isValid() const {
	return m_valid;
}

const char* OffWireMessage::getType() {
	return m_type.c_str();
}

const char* OffWireMessage::getMessage() {
	return m_message.c_str();
}
