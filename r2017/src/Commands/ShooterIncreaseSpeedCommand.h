/*
 * ShooterIncreaseSpeedCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SHOOTERINCREASESPEEDCOMMAND_H_
#define SRC_COMMANDS_SHOOTERINCREASESPEEDCOMMAND_H_

#include "Commands/InstantCommand.h"

class ShooterIncreaseSpeedCommand : public InstantCommand {
public:
	ShooterIncreaseSpeedCommand() : InstantCommand("Shooter Increase Speed Command") {
		Requires(CommandBase::m_superStructure.get());
	}

	void Initialize(){
		CommandBase::m_superStructure->IncShooterOffset();
	}
};


#endif /* SRC_COMMANDS_SHOOTERINCREASESPEEDCOMMAND_H_ */
