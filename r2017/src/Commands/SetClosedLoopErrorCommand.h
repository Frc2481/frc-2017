#ifndef SetClosedLoopErrorCommand_H
#define SetClosedLoopErrorCommand_H

#include "../CommandBase.h"

class SetClosedLoopErrorCommand : public InstantCommand {
public:
	SetClosedLoopErrorCommand() : InstantCommand("SetClosedLoopErrorCommand"){}
	void Initialize(){
		CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->GetMotor(SwerveModule::STEER_MOTOR)->SetAllowableClosedLoopErr(20);
		CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE)->GetMotor(SwerveModule::STEER_MOTOR)->SetAllowableClosedLoopErr(20);
		CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->GetMotor(SwerveModule::STEER_MOTOR)->SetAllowableClosedLoopErr(20);
		CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE)->GetMotor(SwerveModule::STEER_MOTOR)->SetAllowableClosedLoopErr(20);
	}
};

#endif  // SetClosedLoopErrorCommand_H
