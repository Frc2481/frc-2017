#ifndef DecTheirGearCounterCommand_H
#define DecTheirGearCounterCommand_H

#include "../CommandBase.h"

class DecTheirGearCounterCommand : public InstantCommand {
public:
	DecTheirGearCounterCommand() : InstantCommand("DecTheirGearCounterCommand"){}
	void Initialize(){
		CommandBase::m_gearFlicker->DecTheirGear();
	}
};

#endif  // DecTheirGearCounterCommand_H
