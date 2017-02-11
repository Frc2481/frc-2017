/*
 * ClimberOn.h
 *
 *  Created on: Feb 3, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_CLIMBERON_H_
#define SRC_COMMANDS_CLIMBERON_H_

#include "Commands/InstantCommand.h"
#include "CommandBase.h"

class ClimberOn : public InstantCommand {
	ClimberOn() : InstantCommand("ClimberOn"){
		Requires(CommandBase::m_climber.get());
	}
	void Initialize(){
		CommandBase::m_climber->StartClimbing();
	}
};

#endif /* SRC_COMMANDS_CLIMBERON_H_ */
