#ifndef DriveTrainZeroDriveEncodersCommand_H
#define DriveTrainZeroDriveEncodersCommand_H

#include "../CommandBase.h"

class DriveTrainZeroDriveEncodersCommand : public CommandBase {
public:
	DriveTrainZeroDriveEncodersCommand() : CommandBase("DriveTrainZeroDriveEncodersCommand"){}
	void Initialize(){
		m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
	}
	void Execute(){}
	bool IsFinished(){
		return true;
	}
	void End(){}
	void Interrupted(){}
};

#endif  // DriveTrainZeroDriveEncodersCommand_H
