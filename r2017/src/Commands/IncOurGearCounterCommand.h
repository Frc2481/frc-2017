#ifndef IncOurGearCounterCommand_H
#define IncOurGearCounterCommand_H

#include "../CommandBase.h"

class IncOurGearCounterCommand : public InstantCommand {
public:
	IncOurGearCounterCommand() : InstantCommand("IncOurGearCounterCommand"){}
	void Initialize(){
		CommandBase::m_gearFlicker->IncOurGear();
	}
};

#endif  // IncOurGearCounterCommand_H
