#ifndef SetAngleOptimizedCommand_H
#define SetAngleOptimizedCommand_H

#include "../CommandBase.h"

class SetAngleOptimizedCommand : public CommandBase {
private:
	bool m_optimized;
public:
	SetAngleOptimizedCommand(bool optimized) : CommandBase("SetAngleOptimizedCommand"){
		m_optimized = optimized;
	}
	void Initialize(){
		CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->SetOptimized(m_optimized);
		CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE)->SetOptimized(m_optimized);
		CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->SetOptimized(m_optimized);
		CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE)->SetOptimized(m_optimized);
	}
	void Execute(){}
	bool IsFinished(){
		return true;
	}
	void End(){}
	void Interrupted(){}
};

#endif  // SetAngleOptimizedCommand_H
