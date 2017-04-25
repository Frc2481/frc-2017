#ifndef UnlockGearIntakeCommand_H
#define UnlockGearIntakeCommand_H

#include "../CommandBase.h"
#include "Commands/InstantCommand.h"

class UnlockGearIntakeCommand : public InstantCommand {
public:
	UnlockGearIntakeCommand() : InstantCommand("UnlockGearIntakeCommand"){
		Requires(CommandBase::m_gearIntake.get());
	}
	void Initialize(){
		CommandBase::m_gearIntake->UnlockGearIntake();
	}
};

#endif  // UnlockGearIntakeCommand_H
