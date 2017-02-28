#ifndef DriveMotionMagicDistanceCommand_H
#define DriveMotionMagicDistanceCommand_H

#include "../CommandBase.h"
#include "RoboUtils.h"

class DriveMotionMagicDistanceCommand : public CommandBase {
protected:
	double m_angle;
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
		m_angle = (RoboUtils::constrainDegNeg180To180(m_flWheel->GetAngle())
				+ RoboUtils::constrainDegNeg180To180(m_frWheel->GetAngle())
				+ RoboUtils::constrainDegNeg180To180(m_blWheel->GetAngle())
				+ RoboUtils::constrainDegNeg180To180(m_brWheel->GetAngle())) / 4.0;
		printf("FL Angle %f\n", RoboUtils::constrainDegNeg180To180(m_flWheel->GetAngle()));
		printf("FR Angle %f\n", RoboUtils::constrainDegNeg180To180(m_frWheel->GetAngle()));
		printf("BL Angle %f\n", RoboUtils::constrainDegNeg180To180(m_blWheel->GetAngle()));
		printf("BR Angle %f\n", RoboUtils::constrainDegNeg180To180(m_brWheel->GetAngle()));
	}
	void Execute(){
		SmartDashboard::PutNumber("Wheel Angle", m_angle);
		if(CommandBase::m_driveTrain->IsGyroCorrection()){
			CommandBase::m_driveTrain->Drive(sin((m_angle) * (M_PI/180)), -cos((m_angle) * (M_PI/180)), 0);
			//CommandBase::m_driveTrain->Drive(-0.3, -0.95, 0);
		}
	}
	bool IsFinished(){
		bool blIsOnTarget = fabs(m_blWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		bool brIsOnTarget = fabs(m_brWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		bool flIsOnTarget = fabs(m_flWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		bool frIsOnTarget = fabs(m_frWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		return flIsOnTarget || frIsOnTarget || blIsOnTarget || brIsOnTarget;
	}
	void End(){
		printf("Target Drive Distance %f\n", m_distance);
		printf("Real Drive Distance %f\n", m_blWheel->GetDistance());
		m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetControlMode(CANTalon::kPercentVbus);
		m_frWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetControlMode(CANTalon::kPercentVbus);
		m_blWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetControlMode(CANTalon::kPercentVbus);
		m_brWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetControlMode(CANTalon::kPercentVbus);
		m_flWheel->SetMagicBool(false);
		m_frWheel->SetMagicBool(false);
		m_blWheel->SetMagicBool(false);
		m_brWheel->SetMagicBool(false);
		m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		m_frWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		m_blWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		m_brWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
	}
	void Interrupted(){
		End();
	}
};

class DriveCameraDistanceCommand : public DriveMotionMagicDistanceCommand {
public:
	DriveCameraDistanceCommand() : DriveMotionMagicDistanceCommand(0,false){}
	void Initialize(){
		double time = frc::GetFPGATime();
		std::list<AimingParameters> params = RobotChains::getInstance()->getGearAimingParameters(time);
		m_distance = params.begin()->getDistance();
		DriveMotionMagicDistanceCommand::Initialize();
	}
	void Execute(){
		DriveMotionMagicDistanceCommand::Execute();
	}
	bool IsFinished(){
		DriveMotionMagicDistanceCommand::IsFinished();
	}
	void End(){
		DriveMotionMagicDistanceCommand::End();
	}
	void Interrupted(){
		End();
	}
};

#endif  // DriveMotionMagicDistanceCommand_H
