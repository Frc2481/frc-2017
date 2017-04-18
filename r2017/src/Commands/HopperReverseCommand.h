#ifndef HopperReverseCommand_H
#define HopperReverseCommand_H

#include "../CommandBase.h"
#include "Commands/InstantCommand.h"

class HopperReverseCommand : public InstantCommand {
public:
	HopperReverseCommand() : InstantCommand("HopperReverseCommand"){}
	void Initialize(){
		CommandBase::m_superStructure->ReverseHopper();
	}
};

#endif  // HopperReverseCommand_H
