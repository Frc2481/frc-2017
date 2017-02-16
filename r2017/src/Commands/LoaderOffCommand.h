/*
 * LoaderOffCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_LOADEROFFCOMMAND_H_
#define SRC_COMMANDS_LOADEROFFCOMMAND_H_

#include "Commands/InstantCommand.h"

class LoaderOffCommand : public InstantCommand {
public:
	LoaderOffCommand() : InstantCommand("Loader Off Command") {
		Requires(CommandBase::m_superStructure.get());
	}
	void Initialize() {
		CommandBase::m_superStructure->TurnLoaderOff();
	}
};

#endif /* SRC_COMMANDS_LOADEROFFCOMMAND_H_ */
