#ifndef TimeSteerMotorDecelCommand_H
#define TimeSteerMotorDecelCommand_H

#include "../CommandBase.h"

class TimeSteerMotorDecelCommand : public CommandBase {
public:
	TimeSteerMotorDecelCommand() : CommandBase("TimeSteerMotorDecelCommand"){
		Requires(m_driveTrain.get());
	}
	void Initialize(){
		m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->SetOpenLoopSteerSpeed(0);
	}
	bool IsFinished(){
		return fabs(m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->
				GetMotor(SwerveModule::STEER_MOTOR)->GetSpeed()) <= 0;
	}
	void End(){
		printf("Steer Decel Time%f\n", TimeSinceInitialized());
		m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->
						GetMotor(SwerveModule::STEER_MOTOR)->SetControlMode(CANTalon::kPosition);
	}
};


#endif  // TimeSteerMotorDecelCommand_H
