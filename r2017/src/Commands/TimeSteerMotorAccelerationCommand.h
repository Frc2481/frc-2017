#ifndef TimeSteerMotorAccelerationCommand_H
#define TimeSteerMotorAccelerationCommand_H

#include "../CommandBase.h"

class TimeSteerMotorAccelerationCommand : public CommandBase {
public:
	TimeSteerMotorAccelerationCommand() : CommandBase("TimeSteerMotorAccelerationCommand"){
		Requires(m_driveTrain.get());
	}
	void Initialize(){
		m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->SetOpenLoopSteerSpeed(1);
	}
	bool IsFinished(){
		return fabs(m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->
				GetMotor(SwerveModule::STEER_MOTOR)->GetSpeed()) >= 120;
	}
	void End(){
		printf("Steer Accel Time%f\n", TimeSinceInitialized());
//		m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->
//						GetMotor(SwerveModule::STEER_MOTOR)->SetControlMode(CANTalon::kPosition);
	}
};

#endif  // TimeSteerMotorAccelerationCommand_H
