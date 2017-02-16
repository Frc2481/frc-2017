#ifndef DriveTrainSetGyroOffsetCommand_H
#define DriveTrainSetGyroOffsetCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveTrainSetGyroOffsetCommand: public CommandBase
{
private:
	double m_Offset;
public:
	DriveTrainSetGyroOffsetCommand(double offset)
		: m_Offset(offset), CommandBase("DriveTrainSetGyroOffsetCommand"){
	}
	void Initialize(){
		CommandBase::m_driveTrain->SetGyroCorrectionOffset(m_Offset);
	}
	void Execute(){}
	bool IsFinished(){
		return true;
	}
	void End(){}
	void Interrupted(){}
};

#endif
