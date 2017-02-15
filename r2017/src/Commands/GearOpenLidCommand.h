/*
 * GearOpenLidCommand.h
 *
 *  Created on: Feb 11, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_GEAROPENLIDCOMMAND_H_
#define SRC_COMMANDS_GEAROPENLIDCOMMAND_H_

#include "Commands/InstantCommand.h"
#include "CommandBase.h"

class GearOpenLidCommand : public InstantCommand {
public:
	GearOpenLidCommand() : InstantCommand("GearOpenLidCommand"){
		Requires (CommandBase::m_gearFlicker.get());
	}

	void Initialize(){
		CommandBase::m_gearFlicker->OpenLid();
	}
};
#endif /* SRC_COMMANDS_GEAROPENLIDCOMMAND_H_ */
