#ifndef ShooterSetHoodCommand_H
#define ShooterSetHoodCommand_H

#include "../CommandBase.h"

class ShooterSetHoodCommand : public CommandBase {
private:
	bool m_raise;
public:
	ShooterSetHoodCommand(bool raise) : CommandBase("ShooterSetHoodCommand"){
		m_raise = raise;
	}
	void Initialize(){
		if(m_raise){
			CommandBase::m_superStructure->RaiseHood();
		}
		else{
			CommandBase::m_superStructure->LowerHood();
		}
	}
	void Execute(){}
	bool IsFinished(){
		return true;
	}
	void End(){}
	void Interrupted(){}

};
#endif  // ShooterSetHoodCommand_H
