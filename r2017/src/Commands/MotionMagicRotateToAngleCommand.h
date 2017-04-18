#ifndef MotionMagicRotateToAngleCommand_H
#define MotionMagicRotateToAngleCommand_H

#include "../CommandBase.h"
#include "utils/AimingParameters.h"

class MotionMagicRotateToAngleCommand : public CommandBase {
protected:
	double m_targetAngle;
	double m_curAngle;
	SwerveModule* m_blWheel;
	SwerveModule* m_brWheel;
	SwerveModule* m_flWheel;
	SwerveModule* m_frWheel;
	std::ofstream m_outFile;
public:
	MotionMagicRotateToAngleCommand(double angle) : CommandBase("MotionMagicRotateToAngleCommand"){
		Requires(m_driveTrain.get());
		m_targetAngle = angle;
		m_curAngle = 0;
		m_blWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE);
		m_brWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE);
		m_flWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE);
		m_frWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE);
	}
	void Initialize(){
		std::stringstream ss;
		ss << "home/lvuser/MotionMagicTracker" << frc::GetFPGATime() << ".csv";
		m_outFile.open(ss.str().c_str());
		m_outFile << "Current Pos" << ","
				<< "Target Pos" << ","
				<< "Current Speed" << ","
				<< "Target Speed" << ","
				<< "Motor Output" << ","
				<< "ClosedLoopError" << ",\n";
/*		This block is for rotating to a specific angle vs. rotating by a specific angle
		m_curAngle = m_driveTrain->GetHeading();
		double rotateAngle = m_targetAngle - m_curAngle;
		double rotateDistance = m_driveTrain->ComputeDegreesToEncoderRotations(rotateAngle);
*/
		double rotateDistance = m_driveTrain->ComputeDegreesToEncoderRotations(m_targetAngle);
		m_driveTrain->PerformMotionMagic(rotateDistance);

	}
	void Execute(){
		m_outFile << m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition() << ","
				<< m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetMotionMagicActTrajPosition() << ","
				<< m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetSpeed() << ","
				<< m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetMotionMagicActTrajVelocity() << ","
				<< m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetOutputCurrent() << ","
				<< m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetClosedLoopError() << ",\n";
	}
	bool IsFinished(){
		bool blIsOnTarget = fabs(m_blWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		bool brIsOnTarget = fabs(m_brWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		bool flIsOnTarget = fabs(m_flWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		bool frIsOnTarget = fabs(m_frWheel->GetDistance() - CommandBase::m_driveTrain->GetMotionMagicSetpoint()) <= 0.3;
		//bool atAngle = fabs(m_driveTrain->GetHeading() - m_targetAngle) <= 0.5;
		return flIsOnTarget || frIsOnTarget || blIsOnTarget || brIsOnTarget; //|| atAngle;
	}
	void End(){
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
	void Interrupted(){}

};

class MotionMagicCameraRotationCommand : public MotionMagicRotateToAngleCommand {
public:
	MotionMagicCameraRotationCommand() : MotionMagicRotateToAngleCommand(0){}
	void Initialize(){
		std::list<AimingParameters> params = RobotChains::getInstance()->getBoilerAimingParameters(frc::GetFPGATime());
		m_targetAngle = params.begin()->getTargetAngle().getDegrees();
		MotionMagicRotateToAngleCommand::Initialize();
	}
};

#endif  // MotionMagicRotateToAngleCommand_H
