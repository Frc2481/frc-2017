/*
 * DriveTrainSetPIDCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_DRIVETRAINSETPIDCOMMAND_H_
#define SRC_COMMANDS_DRIVETRAINSETPIDCOMMAND_H_
#include "CommandBase.h"
#include "Commands/InstantCommand.h"


class DriveTrainSetPIDCommand : public InstantCommand {
public:
	DriveTrainSetPIDCommand() : InstantCommand("DriveTrain Set PID Command"){}

	void Initialize(){
		double speedP = SmartDashboard::GetNumber("Speed P", 0);
		double speedI = SmartDashboard::GetNumber("Speed I", 0);
		double speedD = SmartDashboard::GetNumber("Speed D", 0);
		double steerP = SmartDashboard::GetNumber("Steer P", 0.01);
		double steerI = SmartDashboard::GetNumber("Steer I", 0);
		double steerD = SmartDashboard::GetNumber("Steer D", 0);
		CommandBase::m_driveTrain->SetSpeedPID(speedP, speedI, speedD);
		CommandBase::m_driveTrain->SetSteerPID(steerP, steerI, steerD);
	}

};



#endif /* SRC_COMMANDS_DRIVETRAINSETPIDCOMMAND_H_ */
