#ifndef SetHPBeamCommand_H
#define SetHPBeamCommand_H

#include "../CommandBase.h"

class SetHPBeamCommand : public CommandBase {
public:
	SetHPBeamCommand() : CommandBase("SetHPBeamCommand"){}
	void Initialize(){
		m_gearIntake->SetHPBeamBroken(true);
	}
	void Execute(){}
	bool IsFinished(){
		return false;
	}
	void End(){
		m_gearIntake->SetHPBeamBroken(false);
	}
};

#endif  // SetHPBeamCommand_H
