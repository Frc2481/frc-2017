#ifndef DriveTrainDisableGyroCorrectionCommand_H
#define DriveTrainDisableGyroCorrectionCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveTrainDisableGyroCorrectionCommand: public CommandBase
{
public:
	DriveTrainDisableGyroCorrectionCommand() : CommandBase("DriveTrainDisableGyroCorrectionCommand"){}
	void Initialize() {
		CommandBase::m_driveTrain->SetGyroCorrection(false);
	}
	void Execute() {}
	bool IsFinished() { return true; }
	void End() {}
	void Interrupted() {}
};

#endif
