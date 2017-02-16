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
			printf("Shooter is on, turning off...\n");
			CommandBase::m_superStructure->TurnShooterOff();
		} else {
			CommandBase::m_superStructure->TurnShooterOn();
			printf("Shooter is off, turning on...\n");
		}
	};
};



#endif
