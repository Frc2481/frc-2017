#ifndef CalibrateMotionMagicRotationCommand_H
#define CalibrateMotionMagicRotationCommand_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../RobotParameters.h"
#include "Components/PersistedSettings.h"
#include "Components/SwerveModule.h"

class CalibrateMotionMagicRotationCommand : public CommandBase {
private:
	SwerveModule* m_blWheel;
	SwerveModule* m_brWheel;
	SwerveModule* m_flWheel;
	SwerveModule* m_frWheel;
public:
	CalibrateMotionMagicRotationCommand() : CommandBase("CalibrateMotionMagicRotationCommand"){
		m_blWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE);
		m_brWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE);
		m_flWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE);
		m_frWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE);
	}
	void Initialize(){
		m_driveTrain->ZeroYaw();
		m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		m_frWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		m_blWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		m_brWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
	}
	void Execute(){}
	bool IsFinished(){
		return false;
	}
	void End(){
		int errorCnt = 0;
//		if(fabs(fabs(m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition()) -
//				fabs(m_frWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition())) > 5.0){
//			printf("FRWheel Calibration Error: Did Not Save");
//			errorCnt++;
//		}
//		else if(fabs(fabs(m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition()) -
//				fabs(m_blWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition())) > 5.0){
//			printf("BLWheel Calibration Error: Did Not Save");
//			errorCnt++;
//		}
//		else if(fabs(fabs(m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition()) -
//				fabs(m_brWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition())) > 5.0){
//			printf("BRWheel Calibration Error: Did Not Save");
//			errorCnt++;
//		}
//		else if(errorCnt >= 3){
//			printf("FLWheel Calibration Error: Did Not Save");
//		}
//		else{
			double averageDistance = (fabs(m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition()) +
					fabs(m_frWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition()) +
					fabs(m_blWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition()) +
					fabs(m_brWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition())) / 4.0;
			double ratio = averageDistance / 3600.0;
			printf("ENC_ROTATION_TO_DEG %f\n", ratio);
			const std::string& key = "ENCODER_ROTATIONS_PER_DEGREE";
			PersistedSettings::GetInstance().Set(key.c_str(), ratio);
		//}
	}
	void Interrupted(){
		End();
	}
};

#endif  // CalibrateMotionMagicRotationCommand_H
