#ifndef IntakeFromHPCommand_H
#define IntakeFromHPCommand_H

#include "../CommandBase.h"
#include "Commands/InstantCommand.h"

class IntakeFromHPCommand : public InstantCommand {
private:
	double m_speed;
public:
	IntakeFromHPCommand(double speed = -1) : InstantCommand("IntakeFromHPCommand"){
		m_speed = speed;
	}
	void Initialize(){
		CommandBase::m_gearIntakeRoller->IntakeGear(m_speed);
	}
};

#endif  // IntakeFromHPCommand_H
