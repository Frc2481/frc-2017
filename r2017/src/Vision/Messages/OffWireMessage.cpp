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
	try {
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
	catch (...) {
		m_valid = false;
	}
}

OffWireMessage::~OffWireMessage() {
	// TODO Auto-generated destructor stub
}

bool OffWireMessage::isValid() const {
	return m_valid;
}

const std::string OffWireMessage::getType() {
	return m_type;
}

const std::string OffWireMessage::getMessage() {
	return m_message;
}
