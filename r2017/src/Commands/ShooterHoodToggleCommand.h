/*
 * ShooterHoodToggleCommand.h
 *
 *  Created on: Feb 11, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SHOOTERHOODTOGGLECOMMAND_H_
#define SRC_COMMANDS_SHOOTERHOODTOGGLECOMMAND_H_

#include "Commands/InstantCommand.h"

class ShooterHoodToggleCommand : public InstantCommand{
public:
	ShooterHoodToggleCommand() : InstantCommand("ShooterHoodToggleCommand"){}

	void Initialize() {
		if (CommandBase::m_superStructure->IsRaised()){
			CommandBase::m_superStructure->LowerHood();
		} else {
			CommandBase::m_superStructure->RaiseHood();
		}
	}
};

#endif /* SRC_COMMANDS_SHOOTERHOODTOGGLECOMMAND_H_ */
