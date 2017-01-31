/*
 * OffWireMessage.cpp
 *
 *  Created on: Jan 27, 2017
 *      Author: FIRSTMentor
 */

#include "json.h"
#include <Vision/Messages/OffWireMessage.h>
using namespace nlohmann;

OffWireMessage::OffWireMessage(std::string message) {
	json obj;
	obj = json::parse(message);

	if(obj.find("type") == obj.end()){
		m_valid = false;
		return;
	}

	m_type = obj["type"];

	if(obj.find("message") == obj.end()){
		m_valid = false;
		return;
	}

	m_message = obj["message"];
	m_valid = true;
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
