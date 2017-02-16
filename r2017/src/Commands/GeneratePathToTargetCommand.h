#ifndef GeneratePathToTargetCommand_H
#define GeneratePathToTargetCommand_H

#include "../CommandBase.h"
#include "AimingParameters.h"
#include "utils/RobotChains.h"

class GeneratePathToTargetCommand : public CommandBase {
private:
	SwerveModule* m_blWheel;
	SwerveModule* m_brWheel;
	SwerveModule* m_flWheel;
	SwerveModule* m_frWheel;
public:
	GeneratePathToTargetCommand() : CommandBase("GeneratePathToTargetCommand"){
		Requires(CommandBase::m_driveTrain.get());
		m_blWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE);
		m_brWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE);
		m_flWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE);
		m_frWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE);
	}
	void Initialize(){
		double timeStamp = frc::GetFPGATime();
		CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		//AimingParameters params = RobotChains::getInstance()->getGearAimingParameters(timeStamp).begin();

		double distance = SmartDashboard::GetNumber("Auto Gear Drive Distance", 0.0);
		double convertDistance = CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(distance);
		CommandBase::m_driveTrain->PerformMotionMagic(convertDistance/*paramsdistance*/);
	}
	void Execute(){
		//if(CommandBase)
		//CommandBase::m_driveTrain->Drive(.5,0,0);
	}
	bool IsFinished(){
		bool blIsOnTarget = fabs(m_blWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		bool brIsOnTarget = fabs(m_brWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		bool flIsOnTarget = fabs(m_flWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		bool frIsOnTarget = fabs(m_frWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		if(blIsOnTarget){ //Add the other ontargets later
			return true;
		}
		else{
			return false;
		}
	}
	void End(){
		//Reset the control modes and enc position of all modules later
		m_blWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetControlMode(CANTalon::kPercentVbus);
		m_blWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		//printf("Drive Set to percent vbus\n");
	}
	void Interrupted(){
		End();
	}
};

#endif  // GeneratePathToTargetCommand_H
