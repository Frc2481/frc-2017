#ifndef SwerveModuleNominalVoltageCommand_H
#define SwerveModuleNominalVoltageCommand_H

#include "../CommandBase.h"

class SwerveModuleNominalVoltageCommand : public CommandBase {
private:
	double m_counter;
public:
	SwerveModuleNominalVoltageCommand() : CommandBase("SwerveModuleNominalVoltageCommand"){
		m_counter = 0;
	}
	void Initialize(){
		m_counter = 0;
	}
	void Execute(){
		m_counter += 0.01;
		m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->SetOpenLoopSteerSpeed(m_counter);
	}
	bool IsFinished(){
		return fabs(m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->
				GetMotor(SwerveModule::STEER_MOTOR)->GetSpeed()) > 0;
	}
	void End(){
//		printf("Applied Throttle %f\n", m_counter);
		m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->
				GetMotor(SwerveModule::STEER_MOTOR)->SetControlMode(CANTalon::kPosition);
	}
	void Interrupted(){}
};

#endif  // SwerveModuleNominalVoltageCommand_H
