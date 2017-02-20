#ifndef TurnShooterOnCommand_H
#define TurnShooterOnCommand_H

#include "../CommandBase.h"

class TurnShooterOnCommand : public CommandBase {
private:
	double m_setpoint;
public:
	TurnShooterOnCommand() : CommandBase("TurnShooterOnCommand"){}
	void Initialize(){
		m_setpoint = SmartDashboard::GetNumber("Shooter Setpoint", 0.0);
		m_superStructure->SetShooterSpeed(m_setpoint);
	}
	void Execute(){}
	bool IsFinished(){}
	void End(){
		m_superStructure->TurnShooterOff();
	}
	void Interrupted(){
		End();
	}
};

#endif  // TurnShooterOnCommand_H
