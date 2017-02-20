#ifndef DriveTrainEnableGyroCorrectionCommand_H
#define DriveTrainEnableGyroCorrectionCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveTrainEnableGyroCorrectionCommand: public CommandBase
{
private:
	double m_angle;
public:
	DriveTrainEnableGyroCorrectionCommand(double angle) : CommandBase("DriveTrainEnableGyroCorrectionCommand") {
		m_angle = angle;
	}
	void Initialize() {
		//CommandBase::m_driveTrain->ZeroYaw();
		CommandBase::m_driveTrain->SetGyroCorrectionOffset(m_angle);
		CommandBase::m_driveTrain->SetGyroCorrection(true);
	}
	void Execute() {}
	bool IsFinished() { return true; }
	void End() {}
	void Interrupted() {}
};

#endif
