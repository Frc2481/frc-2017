/*
 * ShooterOnCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SHOOTERONCOMMAND_H_
#define SRC_COMMANDS_SHOOTERONCOMMAND_H_

#include "Commands/InstantCommand.h"

class ShooterOnCommand : public InstantCommand {
public:
	ShooterOnCommand() : InstantCommand("Shooter On Command") {
		Requires(CommandBase::m_shooter.get());
	}

	void Initialize() {
		CommandBase::m_shooter->TurnShooterOn();
	}
};



#endif /* SRC_COMMANDS_SHOOTERONCOMMAND_H_ */
