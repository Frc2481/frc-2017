/*
 * FeederOffCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_FEEDEROFFCOMMAND_H_
#define SRC_COMMANDS_FEEDEROFFCOMMAND_H_

#include "Commands/InstantCommand.h"

class FeederOffCommand : public InstantCommand {
	FeederOffCommand() : InstantCommand("Feeder Off Command") {
		Requires(CommandBase::m_shooter.get());
	}
	void Initialize() {
		CommandBase::m_shooter->TurnFeederOff();
	}
};

#endif /* SRC_COMMANDS_FEEDEROFFCOMMAND_H_ */

#endif /* SRC_COMMANDS_FEEDEROFFCOMMAND_H_ */
