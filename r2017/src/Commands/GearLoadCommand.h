/*
 * GearLoadCommand.h
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_GEARLOADCOMMAND_H_
#define SRC_COMMANDS_GEARLOADCOMMAND_H_

#include "Commands/InstantCommand.h"
#include "GearLoader.h"

class GearLoadCommand : public InstantCommand {
public:
	GearLoadCommand() : InstantCommand("GearLoadCommand"){
	}

	void Initialize(){
		CommandBase::m_gearLoader->LoadGear();
	}
};

#endif /* SRC_COMMANDS_GEARLOADCOMMAND_H_ */
