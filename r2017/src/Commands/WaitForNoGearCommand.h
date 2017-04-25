#ifndef WaitForNoGearCommand_H
#define WaitForNoGearCommand_H

#include "../CommandBase.h"

class WaitForNoGearCommand : public CommandBase {
public:
	WaitForNoGearCommand() : CommandBase("WaitForNoGearCommand"){
	}
	void Initialize(){}
	void Execute(){}
	bool IsFinished(){
		return !m_gearIntake->GetHasGear();
	}
	void End(){}
	void Interrupted(){}
};

#endif  // WaitForNoGearCommand_H
