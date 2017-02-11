/*
 * ShooterLowerHoodCommand.h
 *
 *  Created on: Feb 11, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SHOOTERLOWERHOODCOMMAND_H_
#define SRC_COMMANDS_SHOOTERLOWERHOODCOMMAND_H_

#include "Commands/InstantCommand.h"
#include "CommandBase.h"

class ShooterLowerHoodCommand : public InstantCommand{
public:
	ShooterLowerHoodCommand() : InstantCommand("ShooterLowerHoodCommand") {
		Requires(CommandBase::m_superStructure.get());
	}

	void Initialize(){
		CommandBase::m_superStructure->LowerHood();
	}
};

#endif /* SRC_COMMANDS_SHOOTERLOWERHOODCOMMAND_H_ */
