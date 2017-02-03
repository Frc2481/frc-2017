/*
 * GearLoadCommand.h
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_GEARFLICKCOMMAND_H_
#define SRC_COMMANDS_GEARFLICKCOMMAND_H_

#include "Commands/InstantCommand.h"
#include "Subsystems/GearFlicker.h"
#include "CommandBase.h"

class GearFlickCommand : public Command {
public:
	GearFlickCommand() : Command("GearFlickCommand"){
	}

	void Initialize(){
		CommandBase::m_gearFlicker->FlickGear();
	}
	void Execute(){}
	bool IsFinished(){
		return false;
	}
	void End(){

	}
	void Interrupted(){

	}
};

#endif /* SRC_COMMANDS_GEARFLICKCOMMAND_H_ */
