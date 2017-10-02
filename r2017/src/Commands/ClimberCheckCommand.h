/*
 * ClimberCheckCommand.h
 *
 *  Created on: Sep 18, 2017
 *      Author: Team2481
 */

#ifndef SRC_COMMANDS_CLIMBERCHECKCOMMAND_H_
#define SRC_COMMANDS_CLIMBERCHECKCOMMAND_H_

#include "Commands/InstantCommand.h"
#include "WPILib.h"
#include "CommandBase.h"

class ClimberCheckCommand : public InstantCommand {
public:
	void Initialize() {
		bool present = false;
		double current = CommandBase::m_climber->GetCurrent();
		const double MIN_CURRENT_FOR_MOTOR_TO_BE_PRESENT = .5;
		if(current > MIN_CURRENT_FOR_MOTOR_TO_BE_PRESENT) {
			present = true;
		}
		SmartDashboard::PutBoolean("Climber Motor Present", present);
	}
};

#endif /* SRC_COMMANDS_CLIMBERCHECKCOMMAND_H_ */
