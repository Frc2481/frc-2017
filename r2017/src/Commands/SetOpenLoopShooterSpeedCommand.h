#ifndef SetOpenLoopShooterSpeedCommand_H
#define SetOpenLoopShooterSpeedCommand_H

#include "../CommandBase.h"

class SetOpenLoopShooterSpeedCommand : public CommandBase {
private:
	double m_speed;
public:
	SetOpenLoopShooterSpeedCommand(double speed) : CommandBase("SetOpenLoopShooterSpeedCommand"){
		m_speed = speed;
	}
	void Initialize(){
		m_superStructure->SetShooterSpeedOpenLoop(m_speed);
	}
	void Execute(){}
	bool IsFinished(){
		return false;
	}
	void End(){
		m_superStructure->SetShooterSpeedOpenLoop(0);
	}
	void Interrupted(){
		End();
	}
};

#endif  // SetOpenLoopShooterSpeedCommand_H
