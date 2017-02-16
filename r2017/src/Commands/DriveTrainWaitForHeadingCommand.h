#ifndef DriveTrainWaitForHeadingCommand_H
#define DriveTrainWaitForHeadingCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveTrainWaitForHeadingCommand: public CommandBase
{
private:
	double mAngle;
public:
	DriveTrainWaitForHeadingCommand(double angle)
		: mAngle(angle), CommandBase("DriveTrainWaitForHeadingCommand") {}
	void Initialize(){}
	void Execute(){}
	bool IsFinished(){
		return fabs(CommandBase::m_driveTrain->GetHeading() - mAngle) < 4;

	}
	void End(){}
	void Interrupted(){}
};

#endif
