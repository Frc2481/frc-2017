#ifndef SetModulesForSpinInPlaceCommand_H
#define SetModulesForSpinInPlaceCommand_H

#include "../CommandBase.h"

class SetModulesForSpinInPlaceCommand : public CommandBase {
private:
	SwerveModule* m_flWheel;
	SwerveModule* m_frWheel;
	SwerveModule* m_blWheel;
	SwerveModule* m_brWheel;
public:
	SetModulesForSpinInPlaceCommand() : CommandBase("SetModulesForSpinInPlaceCommand"){
		//Requires(CommandBase::m_driveTrain.get());
		m_flWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE);
		m_frWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE);
		m_blWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE);
		m_brWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE);
	}
	void Initialize(){
		m_flWheel->SetAngle(42.5, true);
		m_frWheel->SetAngle(137.5, true);
		m_blWheel->SetAngle(317.5, true);
		m_brWheel->SetAngle(222.5, true);
	}
	void Execute(){}
	bool IsFinished(){
		return m_flWheel->IsOnTarget(42.5) && m_frWheel->IsOnTarget(137.5) && m_blWheel->IsOnTarget(317.5) && m_brWheel->IsOnTarget(222.5);
	}
	void End(){}
	void Interrupted(){}
};

#endif  // SetModulesForSpinInPlaceCommand_H
