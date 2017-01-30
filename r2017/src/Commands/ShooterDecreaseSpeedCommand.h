/*
 * ShooterDecreaseSpeedCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SHOOTERDECREASESPEEDCOMMAND_H_
#define SRC_COMMANDS_SHOOTERDECREASESPEEDCOMMAND_H_

#include "Commands/InstantCommand.h"

class ShooterDecreaseSpeedCommand : public InstantCommand {
public:
	ShooterDecreaseSpeedCommand() : InstantCommand("Shooter Decrease Speed Command"){
		Requires(CommandBase::m_shooter.get());
	}

	void Initialize(){
		CommandBase::m_shooter->SetShooterSetpoint(CommandBase::m_shooter->GetShooterSetpoint()-100);
	}
};


#endif /* SRC_COMMANDS_SHOOTERDECREASESPEEDCOMMAND_H_ */
