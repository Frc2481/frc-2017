#ifndef TimeAccelerationCommand_H
#define TimeAccelerationCommand_H

#include "../CommandBase.h"

class TimeAccelerationCommand : public CommandBase {
public:
	TimeAccelerationCommand() : CommandBase("TimeAccelerationCommand"){
		Requires(CommandBase::m_driveTrain.get());
	}
	void Initialize(){}
	void Execute(){
		CommandBase::m_driveTrain->Drive(-1,0,0);
	}
	bool IsFinished(){
		return CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->
				GetMotor(SwerveModule::DRIVE_MOTOR)->GetSpeed() >= 8000;
	}
	void End(){
		printf("Time Since 0 Speed %f\n", TimeSinceInitialized());
	}
	void Interrupted(){
		End();
	}
};

#endif  // TimeAccelerationCommand_H
