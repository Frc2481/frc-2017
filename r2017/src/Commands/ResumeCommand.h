#ifndef ResumeCommand_H
#define ResumeCommand_H

#include "../CommandBase.h"

class ResumeCommand : public CommandBase {
private:

public:
	ResumeCommand() : CommandBase("ResumeCommand"){}
	void Initialize(){
		CommandBase::m_pause = true;
	}
	bool IsFinished(){
		return false;
	}
	void End(){
		CommandBase::m_pause = false;
	}
};

#endif  // ResumeCommand_H
