#ifndef SwerveModuleTestClosedLoopVelocityCommand_H
#define SwerveModuleTestClosedLoopVelocityCommand_H

#include "../CommandBase.h"

class SwerveModuleTestClosedLoopVelocityCommand : public CommandBase {
private:
	double m_velocity;
public:
	SwerveModuleTestClosedLoopVelocityCommand() : CommandBase("SwerveModuleTestClosedLoopVelocityCommand"){
		Requires(m_driveTrain.get());
	}
	void Initialize(){
		m_velocity = SmartDashboard::GetNumber("Drive Velocity Setpoint TEST", 0.0);
		m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->SetClosedLoopSpeed(m_velocity);
	}
	void Execute(){}
	bool IsFinished(){
		return false;
	}
	void End(){}
	void Interrupted(){}
};

#endif  // SwerveModuleTestClosedLoopVelocityCommand_H
