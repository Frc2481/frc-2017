/*
 * OffWireMessage.h
 *
 *  Created on: Jan 27, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_VISION_MESSAGES_OFFWIREMESSAGE_H_
#define SRC_VISION_MESSAGES_OFFWIREMESSAGE_H_

#include <string>
#include "VisionMessage.h"

class OffWireMessage : public VisionMessage {
public:
	OffWireMessage(std::string message);
	virtual ~OffWireMessage();
	bool isValid() const;
	const std::string getType();
	const std::string getMessage();

private:
	bool m_valid;
	std::string m_type;
	std::string m_message;
};

#endif /* SRC_VISION_MESSAGES_OFFWIREMESSAGE_H_ */
