/*
 * ShooterSetPIDCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SHOOTERSETPIDCOMMAND_H_
#define SRC_COMMANDS_SHOOTERSETPIDCOMMAND_H_
#include "CommandBase.h"

class ShooterSetPIDCommand : public CommandBase {
public:
	ShooterSetPIDCommand() : CommandBase("Shooter Set PID Command") {

	}

	void Initialize() {
		m_shooter->SetPID(SmartDashboard::GetNumber("Shooter P", 0),
				SmartDashboard::GetNumber("Shooter I", 0),
				SmartDashboard::GetNumber("Shooter D", 0));
	}

	void Execute() {

	}

	bool IsFinished() {
		return true;
	}

	void End() {

	}

	void Interrupt() {
		End();
	}
};



#endif /* SRC_COMMANDS_SHOOTERSETPIDCOMMAND_H_ */