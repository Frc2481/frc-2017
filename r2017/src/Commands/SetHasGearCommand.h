#ifndef SetHasGearCommand_H
#define SetHasGearCommand_H

#include "../CommandBase.h"

class SetHasGearCommand : public CommandBase {
public:
	SetHasGearCommand() : CommandBase("SetHasGearCommand"){}
	void Initialize(){
		m_gearIntake->SetHasGear(true);
	}
	void Execute(){}
	bool IsFinished(){
		return false;
	}
	void End(){
		m_gearIntake->SetHasGear(false);
	}
};

#endif  // SetHasGearCommand_H
