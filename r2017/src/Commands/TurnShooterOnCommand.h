#ifndef TurnShooterOnCommand_H
#define TurnShooterOnCommand_H

#include "../CommandBase.h"
#include "Commands/InstantCommand.h"

class TurnShooterOnCommand : public InstantCommand {
public:
	TurnShooterOnCommand() : InstantCommand("TurnShooterOnCommand"){}
	void Initialize(){
		CommandBase::m_airCompressor->Stop();
		CommandBase::m_superStructure->TurnShooterOn();
	}
};

#endif  // TurnShooterOnCommand_H
