/*
 * HopperSetSpeedCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_HOPPERSETSPEEDCOMMAND_H_
#define SRC_COMMANDS_HOPPERSETSPEEDCOMMAND_H_
#include "CommandBase.h"
#include "Commands/InstantCommand.h"

class HopperSetSpeedCommand : public InstantCommand {
public:
	HopperSetSpeedCommand() : InstantCommand("Hopper Set Speed Command") {}

	void Initialize(){
		CommandBase::m_hopper->SetSpeed(SmartDashboard::GetNumber("Hopper Speed", 0));
	}
};



#endif /* SRC_COMMANDS_HOPPERSETSPEEDCOMMAND_H_ */
