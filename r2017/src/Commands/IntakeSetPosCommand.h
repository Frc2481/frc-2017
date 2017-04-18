#ifndef IntakeSetPosCommand_H
#define IntakeSetPosCommand_H

#include "../CommandBase.h"

class IntakeSetPosCommand : public CommandBase {
private:
	double m_setpoint;
	int m_loopCount;
public:
	IntakeSetPosCommand(double targetPos, double timeout) : CommandBase("IntakeSetPosCommand"){
		Requires(m_gearIntake.get());
		m_loopCount = 0;
		SetTimeout(timeout);
		m_setpoint = targetPos;
	}
	void Initialize(){
		//m_setpoint = SmartDashboard::GetNumber("Intake Setpoint", 0);
		m_loopCount = 0;
		m_gearIntake->SetIntakePos(m_setpoint);
	}
	void Execute(){
		if(fabs(m_gearIntake->GetPivotPos() - m_setpoint) <= 20.0){
			m_loopCount++;
		}
		else{
			m_loopCount = 0;
		}
	}

	bool IsFinished(){
		return m_loopCount >= 1 || IsTimedOut(); //|| m_gearIntake->GetPivotCurrent() > 50.0;
	}
	void End(){
		m_gearIntake->StopIntakePivot();
	}
};

#endif  // IntakeSetPosCommand_H
