/*
 * ShooterOffCommand.h
 *
 *  Created off: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SHOOTEROFFCOMMAND_H_
#define SRC_COMMANDS_SHOOTEROFFCOMMAND_H_

#include "Commands/InstantCommand.h"

class ShooterOffCommand : public InstantCommand {
public:
	ShooterOffCommand() : InstantCommand("Shooter Off Command") {
		Requires(CommandBase::m_shooter.get());
	}

	void Initialize() {
		CommandBase::m_shooter->TurnShooterOff();
	}
};



#endif /* SRC_COMMANDS_SHOOTEROFFCOMMAND_H_ */
