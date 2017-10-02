/*
 * ClimberStopCommand.h
 *
 *  Created on: Sep 18, 2017
 *      Author: Team2481
 */

#ifndef SRC_COMMANDS_CLIMBERSTOPCOMMAND_H_
#define SRC_COMMANDS_CLIMBERSTOPCOMMAND_H_

#include "CommandBase.h"

class ClimberStopCommand : public InstantCommand{
public:
	ClimberStopCommand() : InstantCommand("ClimberStopCommand") {
		Requires(CommandBase::m_climber.get());
	}

	void Initialize() {
		CommandBase::m_climber->StopClimbing();
	}
};

#endif /* SRC_COMMANDS_CLIMBERSTOPCOMMAND_H_ */
