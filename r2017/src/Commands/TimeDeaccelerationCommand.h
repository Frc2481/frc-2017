#ifndef TimeDeaccelerationCommand_H
#define TimeDeaccelerationCommand_H

#include "../CommandBase.h"

class TimeDeaccelerationCommand : public CommandBase {
public:
	TimeDeaccelerationCommand() : CommandBase("TimeDeaccelerationCommand"){
		Requires(CommandBase::m_driveTrain.get());
	}
	void Initialize(){}
	void Execute(){
		CommandBase::m_driveTrain->Drive(0,0,0);
	}
	bool IsFinished(){
		return fabs(CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->
				GetMotor(SwerveModule::DRIVE_MOTOR)->GetSpeed()) <= 0;
	}
	void End(){
		printf("Time Since Full Speed %f\n", TimeSinceInitialized());
	}
	void Interrupted(){
		End();
	}
};

#endif  // TimeDeaccelerationCommand_H
