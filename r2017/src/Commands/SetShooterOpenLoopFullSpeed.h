#ifndef SetShooterOpenLoopFullSpeed_H
#define SetShooterOpenLoopFullSpeed_H

#include "../CommandBase.h"

class SetShooterOpenLoopFullSpeed : public CommandBase {
public:
	SetShooterOpenLoopFullSpeed() : CommandBase("SetShooterOpenLoopFullSpeed"){}
	void Initialize(){
		CommandBase::m_superStructure->SetShooterSpeedOpenLoop(-1);
	}
	void Execute(){}
	bool IsFinished(){
		return false;
	}
	void End(){
		CommandBase::m_superStructure->SetShooterSpeedOpenLoop(0);
		CommandBase::m_superStructure->SetShooterControlMode(CANTalon::kSpeed);
	}
	void Interrupted(){
		End();
	}
};

#endif  // SetShooterOpenLoopFullSpeed_H
