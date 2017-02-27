#ifndef DriveTrainEnableGyroCorrectionCommand_H
#define DriveTrainEnableGyroCorrectionCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveTrainEnableGyroCorrectionCommand: public CommandBase
{
private:
	double m_angle;
	bool m_heading;
public:
	DriveTrainEnableGyroCorrectionCommand(double angle, bool heading = false) : CommandBase("DriveTrainEnableGyroCorrectionCommand") {
		m_angle = angle;
		m_heading = heading;
	}
	void Initialize() {
		if(m_heading){
			m_angle = CommandBase::m_driveTrain->GetHeading();
		}
		//CommandBase::m_driveTrain->ZeroYaw();
		SmartDashboard::PutNumber("GyroCorrection Angle", m_angle);
		CommandBase::m_driveTrain->SetGyroCorrectionOffset(m_angle);
		CommandBase::m_driveTrain->SetGyroCorrection(true);
	}
	void Execute() {}
	bool IsFinished() { return true; }
	void End() {}
	void Interrupted() {}
};

#endif
