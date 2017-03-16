#ifndef ShooterRampSpeedCommand_H
#define ShooterRampSpeedCommand_H

#include "../CommandBase.h"

class ShooterRampSpeedCommand : public CommandBase {
private:
	double m_endTime;
	InterpolatingDouble m_endSpeed;
	InterpolatingDouble m_startSpeed;
public:
	ShooterRampSpeedCommand(double startSpeed, double endSpeed, double time) : CommandBase("ShooterRampSpeedCommand"),
	m_startSpeed(startSpeed), m_endSpeed(endSpeed), m_endTime(time){
		SetTimeout(m_endTime);
	}
	void Execute(){
		double speed = m_startSpeed.interpolate(m_endSpeed, TimeSinceInitialized()/m_endTime).m_value;
		SmartDashboard::PutNumber("CommandedShooterRampSpeed", speed);
		m_superStructure->SetShooterSpeed(speed);
	}
	bool IsFinished(){
		return IsTimedOut();
	}
	void End(){
		m_superStructure->SetShooterSpeed(m_endSpeed.m_value);
	}
};

#endif  // ShooterRampSpeedCommand_H
