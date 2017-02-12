/*
 * SetShooterMaxSpeedCommand.h
 *
 *  Created on: Feb 11, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SETSHOOTERMAXSPEEDCOMMAND_H_
#define SRC_COMMANDS_SETSHOOTERMAXSPEEDCOMMAND_H_

#include "Commands/InstantCommand.h"

class SetShooterMaxSpeedCommand : public InstantCommand {
public:
	SetShooterMaxSpeedCommand() : InstantCommand("SetShooterMaxSpeedCommand"){}

	void Initialize() {
		CommandBase::m_superStructure->SetShooterSpeed(1.0);
	}
};

#endif /* SRC_COMMANDS_SETSHOOTERMAXSPEEDCOMMAND_H_ */
