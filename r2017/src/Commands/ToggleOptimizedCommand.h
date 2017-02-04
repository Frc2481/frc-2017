#ifndef ToggleOptimizedCommand_H
#define ToggleOptimizedCommand_H

#include "../CommandBase.h"
#include "Commands/InstantCommand.h"

class ToggleOptimizedCommand : public Command {
public:
	ToggleOptimizedCommand() : Command("ToggleOptimizedCommand"){}
	void Initialize(){
		CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->SetOptimized(false);
		CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE)->SetOptimized(false);
		CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->SetOptimized(false);
		CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE)->SetOptimized(false);
	}
	bool IsFinished(){
		return false;
	}
	void End(){
		CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->SetOptimized(true);
		CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE)->SetOptimized(true);
		CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->SetOptimized(true);
		CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE)->SetOptimized(true);
	}
};

#endif  // ToggleOptimizedCommand_H
