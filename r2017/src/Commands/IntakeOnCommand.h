/*
 * IntakeOnCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_INTAKEONCOMMAND_H_
#define SRC_COMMANDS_INTAKEONCOMMAND_H_

#include "Commands/InstantCommand.h"

class IntakeOnCommand : public InstantCommand {
public:
	IntakeOnCommand() : InstantCommand("Intake On Command"){
		Requires(CommandBase::m_intake.get());
	}

	void Initialize() {
		CommandBase::m_intake->TurnIntakeOn();
	}
};



#endif /* SRC_COMMANDS_INTAKEONCOMMAND_H_ */
