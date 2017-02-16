
#ifndef DriveTrainZeroYawCommand_H
#define DriveTrainZeroYawCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveTrainZeroYawCommand: public CommandBase
{
public:
	DriveTrainZeroYawCommand() : CommandBase("DriveTrainZeroYawCommand"){}
	void Initialize(){
		CommandBase::m_driveTrain->ZeroYaw();
	}
	void Execute(){}
	bool IsFinished(){
		return true;
	}
	void End(){}
	void Interrupted(){}
};

#endif
