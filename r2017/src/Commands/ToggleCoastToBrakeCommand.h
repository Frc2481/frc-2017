#ifndef ToggleCoastToBrakeCommand_H
#define ToggleCoastToBrakeCommand_H

#include "../CommandBase.h"

class ToggleCoastToBrakeCommand : public CommandBase {
	bool m_coast;
public:
	ToggleCoastToBrakeCommand(bool coast) : CommandBase("ToggleCoastToBrakeCommand"){
		m_coast = coast;
	}
	void Initialize(){
		if(m_coast){
			CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
			CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
			CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
			CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
		}
		else{
			CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
			CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
			CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
			CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
		}
	}
	void Execute(){}
	bool IsFinished(){
		return true;
	}
	void End(){}
	void Interrupted(){}
};

#endif  // ToggleCoastToBrakeCommand_H
