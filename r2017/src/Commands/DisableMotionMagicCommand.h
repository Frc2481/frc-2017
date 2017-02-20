#ifndef DisableMotionMagicCommand_H
#define DisableMotionMagicCommand_H

#include "../CommandBase.h"

class DisableMotionMagicCommand : public CommandBase {
public:
	DisableMotionMagicCommand() : CommandBase("DisableMotionMagicCommand"){}
	void Initialize(){
		CommandBase::m_driveTrain
	}
	void Execute(){}
	bool IsFinished(){}
	void End(){}
	void Interrupted(){}
};

#endif  // DisableMotionMagicCommand_H
