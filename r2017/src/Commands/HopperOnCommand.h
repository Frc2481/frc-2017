/*
 * HopperOnCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_HOPPERONCOMMAND_H_
#define SRC_COMMANDS_HOPPERONCOMMAND_H_

#include "CommandBase.h"
#include "Commands/InstantCommand.h"

class HopperOnCommand : public InstantCommand {
public:
	HopperOnCommand() : InstantCommand("Hopper On Command"){
		//Requires(CommandBase::m_superStructure.get());
	}

	void Initialize(){
		CommandBase::m_superStructure->StartFeeding();
	}
};



#endif /* SRC_COMMANDS_HOPPERONCOMMAND_H_ */
