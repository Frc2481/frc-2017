/*
 * IntakeOffCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_INTAKEOFFCOMMAND_H_
#define SRC_COMMANDS_INTAKEOFFCOMMAND_H_

#include "Commands/InstantCommand.h"

class IntakeOffCommand : public frc::InstantCommand {
public:
	IntakeOffCommand() : InstantCommand("IntakeOffCommand"){
	}

	void Initialize() {
		CommandBase::m_gearIntake->StopIntake();
	}
};

#endif /* SRC_COMMANDS_INTAKEOFFCOMMAND_H_ */
