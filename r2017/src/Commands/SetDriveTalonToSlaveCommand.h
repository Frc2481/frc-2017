#ifndef SetDriveTalonToSlaveCommand_H
#define SetDriveTalonToSlaveCommand_H

#include "../CommandBase.h"

class SetDriveTalonToSlaveCommand : public CommandBase {
private:
	bool m_slave;
public:
	SetDriveTalonToSlaveCommand(bool slave) : CommandBase("SetDriveTalonToSlaveCommand"){
		m_slave = slave;
	}
	void Initialize(){
//		CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->SetOptimized(false);
//		CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE)->SetOptimized(false);
//		CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->SetOptimized(false);
//		CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE)->SetOptimized(false);
		if(m_slave){
			CommandBase::m_driveTrain->SetSlaveTalons();
		}
		else{
			CommandBase::m_driveTrain->ResetSlaveTalons();
		}
		//printf("Talons set to slave\n");
	}
	void Execute(){}
	bool IsFinished(){
		return true;
	}
	void End(){}
	void Interrupted(){}
};

#endif  // SetDriveTalonToSlaveCommand_H
