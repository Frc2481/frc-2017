/*
 * HopperOffCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_HOPPEROFFCOMMAND_H_
#define SRC_COMMANDS_HOPPEROFFCOMMAND_H_

#include "Commands/InstantCommand.h"

class HopperOffCommand : public InstantCommand {
public:
	HopperOffCommand() : InstantCommand("Hopper Off Command"){
		Requires(CommandBase::m_hopper.get());
	}

	void Initialize() {
		CommandBase::m_hopper->StopFeeding();
	}
};

#endif /* SRC_COMMANDS_HOPPEROFFCOMMAND_H_ */
