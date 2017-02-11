/*
 * ShooterToggleCommand.h
 *
 *  Created on: Feb 3, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SHOOTERTOGGLECOMMAND_H_
#define SRC_COMMANDS_SHOOTERTOGGLECOMMAND_H_

#include "Commands/InstantCommand.h"

class ShooterToggleCommand : public InstantCommand{
public:
	ShooterToggleCommand() : InstantCommand("ShooterToggleCommand"){}

	void Initialize() {
		if (CommandBase::m_superStructure->IsShooterOn()) {
			CommandBase::m_superStructure->TurnShooterOff();
		} else {
			CommandBase::m_superStructure->TurnShooterOn();
		}
	};
};



#endif
