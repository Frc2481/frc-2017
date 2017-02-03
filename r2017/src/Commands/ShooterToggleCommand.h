#ifndef SRC_COMMANDS_SHOOTERTOGGLECOMMAND_H_
#define SRC_COMMANDS_SHOOTERTOGGLECOMMAND_H_

#include "Commands/InstantCommand.h"

class ShooterToggleCommand : public InstantCommand{
public:
	ShooterToggleCommand() : InstantCommand("ShooterToggleCommand"){}

	void Initialize() {
		if (CommandBase::m_shooter->IsShooterOn()) {
			CommandBase::m_shooter->TurnShooterOff();
		} else {
			CommandBase::m_shooter->TurnShooterOn();
		}
	};
};



#endif
