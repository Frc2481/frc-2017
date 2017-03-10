#ifndef SwerveModuleRotateToAngleCommand_H
#define SwerveModuleRotateToAngleCommand_H

#include "../CommandBase.h"

class SwerveModuleRotateToAngleCommand : public CommandBase {
private:
	SwerveModule* m_flWheel;
	SwerveModule* m_frWheel;
	SwerveModule* m_blWheel;
	SwerveModule* m_brWheel;
	double m_angle;
	bool m_useParams;
public:
	SwerveModuleRotateToAngleCommand(double targetAngle, bool useAimingParams) : CommandBase("SwerveModuleRotateToAngleCommand"){
		Requires(CommandBase::m_driveTrain.get());
		m_angle = targetAngle;
		m_useParams = useAimingParams;
		m_flWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE);
		m_frWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE);
		m_blWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE);
		m_brWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE);
	}
	void Initialize(){
		if(m_useParams){
//			double timeStamp = frc::GetFPGATime();
//			AimingParameters params = RobotChains::getInstance()->getGearAimingParameters(timeStamp).begin();
//			m_flWheel->SetAngle(params.getRobotAngle(), true);
//			m_frWheel->SetAngle(params.getRobotAngle(), true);
//			m_blWheel->SetAngle(params.getRobotAngle(), true);
//			m_brWheel->SetAngle(params.getRobotAngle(), true);
		}
		else {
			m_flWheel->SetAngle(m_angle, true);
			m_frWheel->SetAngle(m_angle, true);
			m_blWheel->SetAngle(m_angle, true);
			m_brWheel->SetAngle(m_angle, true);
		}
	}
	void Execute(){}
	bool IsFinished(){
		return CommandBase::m_driveTrain->IsSteerOnTarget(m_angle);
	}
	void End(){}
	void Interrupted(){}
};

#endif  // SwerveModuleRotateToAngleCommand_H
