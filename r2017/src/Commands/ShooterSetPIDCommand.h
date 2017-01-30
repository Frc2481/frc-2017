/*
 * ShooterSetPIDCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SHOOTERSETPIDCOMMAND_H_
#define SRC_COMMANDS_SHOOTERSETPIDCOMMAND_H_
#include "CommandBase.h"
#include "Commands/InstantCommand.h"

class ShooterSetPIDCommand : public InstantCommand {
public:
	ShooterSetPIDCommand() : InstantCommand("Shooter Set PID Command") {}

	void Initialize() {
		CommandBase::m_shooter->SetPID(SmartDashboard::GetNumber("Shooter P", 0),
				SmartDashboard::GetNumber("Shooter I", 0),
				SmartDashboard::GetNumber("Shooter D", 0));
	}
};



#endif /* SRC_COMMANDS_SHOOTERSETPIDCOMMAND_H_ */
