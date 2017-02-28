#ifndef IncTheirGearCounterCommand_H
#define IncTheirGearCounterCommand_H

#include "../CommandBase.h"

class IncTheirGearCounterCommand : public InstantCommand {
public:
	IncTheirGearCounterCommand() : InstantCommand("IncTheirGearCounterCommand"){}
	void Initialize(){
		CommandBase::m_gearFlicker->IncTheirGear();
	}
};

#endif  // IncTheirGearCounterCommand_H
