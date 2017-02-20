#ifndef GenerateGearRotationPathCommand_H
#define GenerateGearRotationPathCommand_H

#include <cmath>
#include "../CommandBase.h"
#include "DriveTrainFollowPathCommand.h"
#include "Commands/InstantCommand.h"
#include "AimingParameters.h"
#include "utils/RigidTransform2D.h"
#include "utils/RobotChains.h"
#include "utils/Rotation2D.h"

class GenerateGearRotationPathCommand : public DriveTrainFollowPathCommand {
private:
	SwerveModule* m_blWheel;
	SwerveModule* m_brWheel;
	SwerveModule* m_flWheel;
	SwerveModule* m_frWheel;
	double m_distance;
public:
	GenerateGearRotationPathCommand(double distance): DriveTrainFollowPathCommand("GenerateGearRotationPathCommand"){
		Requires(CommandBase::m_driveTrain.get());
		m_distance = distance;
		m_blWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE);
		m_brWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE);
		m_flWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE);
		m_frWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE);
	}
	void Initialize(){
		//double timeStamp = frc::GetFPGATime();
		//AimingParameters params = RobotChains::getInstance()->getGearAimingParameters(timeStamp).begin();
//
//		Waypoint initial = {0,0,params.getAngle()};
//		Waypoint middle = {params.getDistance() * params.getAngle().getCos(),
//				params.getDistance() - 18, 0};
//		Waypoint final = {params.getDistance() * params.getAngle().getCos(),
//				params.getDistance() * params.getAngle().getSin(), 0};
//
//		Waypoint path[3] = {initial, middle, final};
//		GeneratePath(path, 3);
		//CommandBase::m_driveTrain->PerformMotionMagic(1000/*params.getDistance()*/);
		//CommandBase::m_driveTrain->Drive(0.0,0.0,0.1);
		double arcLength = (60.0/*params.getTargetAngle().getDegrees()*/ / 360.0) * (CIRCUMFERENCE_OF_ROTATION);
		double convertedLength = CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(arcLength);
		CommandBase::m_driveTrain->PerformMotionMagic(m_distance);//convertedLength);
	}
	void Execute(){}
	bool IsFinished(){
		bool blIsOnTarget = fabs(m_blWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		bool brIsOnTarget = fabs(m_brWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		bool flIsOnTarget = fabs(m_flWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		bool frIsOnTarget = fabs(m_frWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		if(flIsOnTarget){ //Add the other ontargets later
			return true;
		}
		else{
			return false;
		}
	}
	void End(){
		//Reset other modules and enc pos laters
		m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetControlMode(CANTalon::kPercentVbus);
		m_frWheel->SetMagicBool(false);
		m_flWheel->SetMagicBool(false);
		m_blWheel->SetMagicBool(false);
		m_brWheel->SetMagicBool(false);
		m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		//printf("drive set to percentVbus\n");
	}
	void Interrupted(){
		End();
	}
};

#endif  // GenerateOptimalPathToLiftCommand_H
