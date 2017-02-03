/*
 * GearLoadCommand.h
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_GEARLOADCOMMAND_H_
#define SRC_COMMANDS_GEARLOADCOMMAND_H_

#include "Commands/InstantCommand.h"
#include "Subsystems/GearLoader.h"

class GearLoadCommand : public Command {
public:
	GearLoadCommand() : Command("GearLoadCommand"){
	}

	void Initialize(){
		CommandBase::m_gearLoader->LoadGear();
	}
	void Execute(){}
	bool IsFinished(){
		return false;
	}
	void End(){
		CommandBase::m_gearLoader->ResetGear();
	}
	void Interrupted(){
		CommandBase::m_gearLoader->ResetGear();
	}
};

#endif /* SRC_COMMANDS_GEARLOADCOMMAND_H_ */
