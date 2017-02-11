/*
 * ClimberOff.h
 *
 *  Created on: Feb 3, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_CLIMBEROFF_H_
#define SRC_COMMANDS_CLIMBEROFF_H_

#include "Commands/InstantCommand.h"
#include "CommandBase.h"

class ClimberOff : public InstantCommand {
	ClimberOff() : InstantCommand("ClimberOff"){
		Requires(CommandBase::m_climber.get());
	}
	void Initialize(){
		CommandBase::m_climber->StopClimbing();
	}
};

#endif /* SRC_COMMANDS_CLIMBEROFF_H_ */
