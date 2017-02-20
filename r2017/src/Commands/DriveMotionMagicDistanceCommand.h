#ifndef DriveMotionMagicDistanceCommand_H
#define DriveMotionMagicDistanceCommand_H

#include "../CommandBase.h"

class DriveMotionMagicDistanceCommand : public CommandBase {
private:
	double m_distance;
	bool m_sideways;
	SwerveModule* m_blWheel;
	SwerveModule* m_brWheel;
	SwerveModule* m_flWheel;
	SwerveModule* m_frWheel;
public:
	DriveMotionMagicDistanceCommand(double distance, bool sideways) : CommandBase("DriveMotionMagicDistance"){
		m_distance = distance;
		m_sideways = sideways;
		Requires(CommandBase::m_driveTrain.get());
		m_blWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE);
		m_brWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE);
		m_flWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE);
		m_frWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE);
	}
	void Initialize(){
		m_driveTrain->PerformMotionMagic(m_distance);
	}
	void Execute(){
		if(m_sideways){
			CommandBase::m_driveTrain->Drive(-1,0,0);
		}
		else{
			CommandBase::m_driveTrain->Drive(0,-1,0);
		}
	}
	bool IsFinished(){
		bool blIsOnTarget = fabs(m_blWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		bool brIsOnTarget = fabs(m_brWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		bool flIsOnTarget = fabs(m_flWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		bool frIsOnTarget = fabs(m_frWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		return flIsOnTarget;
	}
	void End(){
		m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetControlMode(CANTalon::kPercentVbus);
		m_flWheel->SetMagicBool(false);
		m_frWheel->SetMagicBool(false);
		m_blWheel->SetMagicBool(false);
		m_brWheel->SetMagicBool(false);
		m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
	}
	void Interrupted(){
		End();
	}
};

#endif  // DriveMotionMagicDistanceCommand_H
