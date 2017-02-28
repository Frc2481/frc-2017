/*
 * SendSerialCharCommand.h
 *
 *  Created on: Feb 20, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SENDSERIALCHARCOMMAND_H_
#define SRC_COMMANDS_SENDSERIALCHARCOMMAND_H_

#include "Commands/InstantCommand.h"
#include "Components/SerialRemote.h"

class SendSerialCharCommand : public InstantCommand {
private:
	char m_command;
public:
	SendSerialCharCommand(char c) : InstantCommand("SendSerialCharCommand"){
		SetRunWhenDisabled(true);
		m_command = c;

	}
	void Initialize(){
		SerialRemote::GetInstance()->SendSerialChar(m_command);
	}
};


#endif /* SRC_COMMANDS_SENDSERIALCHARCOMMAND_H_ */
