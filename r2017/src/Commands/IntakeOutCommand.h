#ifndef IntakeOutCommand_H
#define IntakeOutCommand_H

#include "../CommandBase.h"
#include "Commands/InstantCommand.h"

class IntakeOutCommand : public CommandBase{
public:
	IntakeOutCommand(double timeout = 1.0) : CommandBase("IntakeOutCommand"){
		SetTimeout(timeout);
	}
	void Initialize(){
//		printf("IntakeOutCommand");
		CommandBase::m_gearIntakeRoller->SpitGear();
	}
	bool IsFinished(){
		return IsTimedOut();
	}
	void End(){
		CommandBase::m_gearIntakeRoller->StopIntake();
	}
};

#endif  // IntakeOutCommand_H
