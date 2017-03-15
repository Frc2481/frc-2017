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
		if(!m_superStructure->IsRaised()){
			m_setpoint = 4350;//RED
		}
		else{
			m_setpoint = 4600;//BLUE
		}
		m_superStructure->SetShooterSpeed(m_setpoint);
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
