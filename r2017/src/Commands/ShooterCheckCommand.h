/*
 * ShooterCheckCommand.h
 *
 *  Created on: Sep 18, 2017
 *      Author: Team2481
 */

#ifndef SRC_COMMANDS_SHOOTERCHECKCOMMAND_H_
#define SRC_COMMANDS_SHOOTERCHECKCOMMAND_H_

#include "CommandBase.h"
#include "WPILib.h"
#include "Commands/InstantCommand.h"

class ShooterCheckCommand : public InstantCommand{
public:
	ShooterCheckCommand() : InstantCommand("ShooterCheckCommand") {

	}
	void Initialize() {
		bool motorPresent = false;
		double current = CommandBase::m_superStructure->GetShooterCurrent();
		const double MIN_CURRENT_FOR_MOTOR_TO_BE_PRESENT = .5;
		if(current > MIN_CURRENT_FOR_MOTOR_TO_BE_PRESENT) {
			motorPresent = true;
		}
		SmartDashboard::PutBoolean("Shooter Motor Present", motorPresent);

		bool sensorPresent = CommandBase::m_superStructure->IsShooterEncoderPresent();
		SmartDashboard::PutBoolean("Shooter sensor Present", sensorPresent);
	}
};

#endif /* SRC_COMMANDS_SHOOTERCHECKCOMMAND_H_ */
