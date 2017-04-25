/*
 * GearCloseLidCommand.h
 *
 *  Created on: Feb 11, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_GEARCLOSELIDCOMMAND_H_
#define SRC_COMMANDS_GEARCLOSELIDCOMMAND_H_

#include "Commands/InstantCommand.h"
#include "CommandBase.h"

class GearCloseLidCommand : public InstantCommand {
public:
	GearCloseLidCommand() : InstantCommand("GearCloseLidCommand"){
		Requires (CommandBase::m_gearFlicker.get());
	}

	void Initialize(){
		if(CommandBase::m_gearIntake->GetPivotPos() <= 300.0){
			CommandBase::m_gearFlicker->CloseLid();
		}
	}
};

#endif /* SRC_COMMANDS_GEARCLOSELIDCOMMAND_H_ */
