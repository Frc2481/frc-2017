/*
 * LoaderOnCommand.h

 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_LOADERONCOMMAND_H_
#define SRC_COMMANDS_LOADERONCOMMAND_H_

#include "Commands/InstantCommand.h"

class LoaderOnCommand : public InstantCommand {
public:
	LoaderOnCommand() : InstantCommand("Loader On Command") {
		Requires(CommandBase::m_superStructure.get());
	}
	void Initialize() {
		CommandBase::m_superStructure->TurnLoaderOn();
	}
};

#endif /* SRC_COMMANDS_LOADERONCOMMAND_H_ */
