/*
 * ShooterRaiseHoodCommand.h
 *
 *  Created on: Feb 11, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SHOOTERRAISEHOODCOMMAND_H_
#define SRC_COMMANDS_SHOOTERRAISEHOODCOMMAND_H_

#include "Commands/InstantCommand.h"
#include "CommandBase.h"

class ShooterRaiseHoodCommand : public InstantCommand{
public:
	ShooterRaiseHoodCommand() : InstantCommand("ShooterRaiseHoodCommand") {
		Requires(CommandBase::m_superStructure.get());
	}

	void Initialize() {
		CommandBase::m_superStructure->RaiseHood();
	}
};

#endif /* SRC_COMMANDS_SHOOTERRAISEHOODCOMMAND_H_ */
