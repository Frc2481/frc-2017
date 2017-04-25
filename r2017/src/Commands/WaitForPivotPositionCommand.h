#ifndef WaitForPivotPositionCommand_H
#define WaitForPivotPositionCommand_H

#include "../CommandBase.h"

class WaitForPivotPositionCommand : public CommandBase {
private:
	double m_setpoint;
	bool m_direction;
public:
	WaitForPivotPositionCommand(double setpoint){
		m_setpoint = setpoint;
	}
	void Initialize(){
		if(m_gearIntake->GetPivotPos() < m_setpoint){
			m_direction = false;
		}
		else if(m_gearIntake->GetPivotPos() > m_setpoint){
			m_direction = true;
		}
	}
	void Execute(){}
	bool IsFinished(){
		return (m_direction == true && m_gearIntake->GetPivotPos() < m_setpoint)
				|| (m_direction == false && m_gearIntake->GetPivotPos() > m_setpoint);
	}
	void End(){}
};

#endif  // WaitForPivotPositionCommand_H
