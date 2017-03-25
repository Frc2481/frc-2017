#ifndef SetShooterSpeedCommand_H
#define SetShooterSpeedCommand_H

#include "../CommandBase.h"
#include "Commands/InstantCommand.h"

class SetShooterSpeedCommand : public InstantCommand {
private:
	double m_speed;
public:
	SetShooterSpeedCommand(double speed): InstantCommand("SetShooterSpeedCommand"){
		m_speed = speed;
	}
	void Initialize(){
		CommandBase::m_superStructure->SetShooterSpeed(m_speed);
	}
};

#endif  // SetShooterSpeedCommand_H
