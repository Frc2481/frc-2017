#ifndef WaitForGearCommand_H
#define WaitForGearCommand_H

#include "../CommandBase.h"

class WaitForGearCommand : public CommandBase {
public:
	WaitForGearCommand() : CommandBase("WaitForGearCommand"){}
	void Initialize(){}
	bool IsFinished(){
		return m_gearIntake->GetHasGear();
	}
	void End(){}
};

#endif  // WaitForGearCommand_H
