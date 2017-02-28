#ifndef DecOurGearCounterCommand_H
#define DecOurGearCounterCommand_H

#include "../CommandBase.h"

class DecOurGearCounterCommand : public InstantCommand {
public:
	DecOurGearCounterCommand() : InstantCommand("DecOurGearCounterCommand"){}
	void Initialize(){
		CommandBase::m_gearFlicker->DecOurGear();
	}
};

#endif  // DecOurGearCounterCommand_H
