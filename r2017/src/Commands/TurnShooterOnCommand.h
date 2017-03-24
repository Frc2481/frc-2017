#ifndef TurnShooterOnCommand_H
#define TurnShooterOnCommand_H

#include "../CommandBase.h"

class TurnShooterOnCommand : public CommandBase {
private:
	double m_setpoint;
	int m_loopCount;
public:
	TurnShooterOnCommand(double setpoint = 0) : CommandBase("TurnShooterOnCommand"){
		m_setpoint = setpoint;
		m_loopCount = 0;
	}
	void Initialize(){
		double setpoint = m_setpoint;
		if(m_setpoint < 1){
			if(!m_superStructure->IsRaised()){
				setpoint = 4250;
			}
			else{
				setpoint = 4100;
			}
		}
		m_superStructure->SetShooterSpeed(setpoint);
	}
	void Execute(){}
	bool IsFinished(){
		return true;
	}
	void End(){}
	void Interrupted(){
		End();
	}
};

#endif  // TurnShooterOnCommand_H
