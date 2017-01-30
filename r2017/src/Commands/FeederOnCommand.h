/*
 * FeederOnCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_FEEDERONCOMMAND_H_
#define SRC_COMMANDS_FEEDERONCOMMAND_H_

#include "Commands/InstantCommand.h"

class FeederOnCommand : public InstantCommand {
	FeederOnCommand() : InstantCommand("Feeder On Command") {
		Requires(CommandBase::m_shooter.get());
	}
	void Initialize() {
		CommandBase::m_shooter->TurnFeederOn();
	}
};

#endif /* SRC_COMMANDS_FEEDERONCOMMAND_H_ */
