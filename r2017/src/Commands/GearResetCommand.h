/*
 * GearLoad.h
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_GEARRESETCOMMAND_H_
#define SRC_COMMANDS_GEARRESETCOMMAND_H_

#include "GearLoader.h"

class GearResetCommand : public InstantCommand{
	GearResetCommand() : InstantCommand("GearResetCommand"){

	}

	void Initialize(){
		CommandBase::m_gearLoader->ResetGear();
	}
};



#endif /* SRC_COMMANDS_GEARRESETCOMMAND_H_ */
