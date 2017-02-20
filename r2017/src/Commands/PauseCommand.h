#ifndef PauseCommand_H
#define PauseCommand_H

#include "../CommandBase.h"

class PauseCommand : public CommandBase {
public:
	PauseCommand() : CommandBase("PauseCommand"){}
	bool IsFinished(){
		return !CommandBase::m_pause;
	}
};

#endif  // PauseCommand_H
