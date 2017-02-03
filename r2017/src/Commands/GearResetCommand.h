/*
 * GearResetCommand.h
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_GEARRESETCOMMAND_H_
#define SRC_COMMANDS_GEARRESETCOMMAND_H_

#include <Subsystems/GearFlicker.h>

class GearResetCommand : public InstantCommand{
public:
	GearResetCommand() : InstantCommand("GearResetCommand"){

	}

	void Initialize(){
		CommandBase::m_gearFlicker->ResetGear();
	}
};



#endif /* SRC_COMMANDS_GEARRESETCOMMAND_H_ */
