#ifndef StopGearIntakeCommand_H
#define StopGearIntakeCommand_H

#include "../CommandBase.h"
#include "Commands/InstantCommand.h"

class StopGearIntakeCommand : public InstantCommand {
public:
	StopGearIntakeCommand() : InstantCommand("StopGearIntakeCommand"){
		Requires(CommandBase::m_gearIntakeRoller.get());
		Requires(CommandBase::m_gearIntake.get());
	}
	void Initialize(){
		CommandBase::m_gearIntake->StopIntakePivot();
		CommandBase::m_gearIntakeRoller->StopIntake();
	}
};

#endif  // StopGearIntakeCommand_H
