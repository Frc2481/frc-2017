#ifndef DriveTrainEnableGyroCorrectionCommand_H
#define DriveTrainEnableGyroCorrectionCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveTrainEnableGyroCorrectionCommand: public CommandBase
{
public:
	DriveTrainEnableGyroCorrectionCommand() : CommandBase("DriveTrainEnableGyroCorrectionCommand") {}
	void Initialize() {
		CommandBase::m_driveTrain->ZeroYaw();
		CommandBase::m_driveTrain->SetGyroCorrection(true);
	}
	void Execute() {}
	bool IsFinished() { return true; }
	void End() {}
	void Interrupted() {}
};

#endif
