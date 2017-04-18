#ifndef IntakeOutCommand_H
#define IntakeOutCommand_H

#include "../CommandBase.h"
#include "Commands/InstantCommand.h"

class IntakeOutCommand : public InstantCommand{
public:
	IntakeOutCommand() : InstantCommand("IntakeOutCommand"){}
	void Initialize(){
		printf("IntakeOutCommand");
		CommandBase::m_gearIntake->SpitGear();
	}
};

#endif  // IntakeOutCommand_H
