#ifndef SetEncoderConfigsCommand_H
#define SetEncoderConfigsCommand_H

#include "../CommandBase.h"
#include "RobotParameters.h"
#include "Components/TrajectoryFollower.h"

class SetEncoderConfigsCommand : public InstantCommand {
private:
	int m_initPos;
	double m_kp, m_ki, m_kd, m_kv, m_ka;
public:
	SetEncoderConfigsCommand(){}
	void Initialize(){
//		m_initPos = SmartDashboard::GetNumber("EncoderConfigs InitPos", 0);
//		m_kp = SmartDashboard::GetNumber("EncoderConfigs P", 0.0);
//		m_ki = SmartDashboard::GetNumber("EncoderConfigs I", 0.0);
//		m_kd = SmartDashboard::GetNumber("EncoderConfigs D", 0.0);
//		m_kv = SmartDashboard::GetNumber("EncoderConfigs V", 0.0);
//		m_ka = SmartDashboard::GetNumber("EncoderConfigs A", 0.0);

//		TrajectoryFollower::GetInstance()->SetEncoderConfig(m_initPos, ENCODER_TICKS_PER_REV, MM_PER_REV, m_kp, m_ki, m_kd, m_kv, m_ka);
	}
};

#endif  // SetEncoderConfigsCommand_H
