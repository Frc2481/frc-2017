/*
 * IntakeOffCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_INTAKEOFFCOMMAND_H_
#define SRC_COMMANDS_INTAKEOFFCOMMAND_H_

#include "Commands/InstantCommand.h"

class IntakeOffCommand : public InstantCommand {
public:
	IntakeOffCommand() : InstantCommand("Intake Off Command"){
		Requires(CommandBase::m_intake.get());
	}

	void Initialize() {
		CommandBase::m_intake->TurnIntakeOff();
	}
};

#endif /* SRC_COMMANDS_INTAKEOFFCOMMAND_H_ */
