#ifndef DriveTrainWaitForHeadingCommand_H
#define DriveTrainWaitForHeadingCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveTrainWaitForHeadingCommand: public CommandBase
{
private:
	int m_loopCounter;
	double mAngle;
public:
	DriveTrainWaitForHeadingCommand(double angle)
		: mAngle(angle), CommandBase("DriveTrainWaitForHeadingCommand") {
		m_loopCounter = 0;
	}
	void Initialize(){}
	void Execute(){
		m_driveTrain->Drive(0,0,0);
		if(fabs(CommandBase::m_driveTrain->GetHeading() - mAngle) < 2){
			m_loopCounter++;
		}
		else{
			m_loopCounter = 0;
		}
	}
	bool IsFinished(){
		return m_loopCounter == 5;

	}
	void End(){}
	void Interrupted(){}
};

#endif
