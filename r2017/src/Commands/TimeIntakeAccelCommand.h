#ifndef TimeIntakeAccelCommand_H
#define TimeIntakeAccelCommand_H

#include "../CommandBase.h"

class TimeIntakeAccelCommand : public CommandBase {
private:
	double m_curSpeed;
	double m_prevSpeed;
	int m_loopCount;
public:
	TimeIntakeAccelCommand() : CommandBase("TimeIntakeAccelCommand"){
		//Requires(m_gearIntake.get());
		m_loopCount = 0;
	}
	void Initialize(){
		m_prevSpeed = 0;
		m_curSpeed = 0;
		m_loopCount = 0;
		m_gearIntake->SetIntakePos(1);
	}
	void Execute(){
		m_curSpeed = m_gearIntake->GetPivotSpeed();
		if(fabs(m_curSpeed - m_prevSpeed) <= 1.0){
			m_loopCount++;
		}
		else{
			m_loopCount = 0;
		}
		m_prevSpeed = m_curSpeed;
	}
	bool IsFinished(){
		return m_loopCount >= 5;
	}
	void End(){
		printf("Intake Max Speed %f\n", m_curSpeed);
		printf("Intake Accel Time %f\n", TimeSinceInitialized());
	}
	void Interrupted(){}
};

#endif  // TimeIntakeAccelCommand_H
