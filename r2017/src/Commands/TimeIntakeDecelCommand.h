#ifndef TimeIntakeDecelCommand_H
#define TimeIntakeDecelCommand_H

#include "../CommandBase.h"

class TimeIntakeDecelCommand : public CommandBase {
public:
	TimeIntakeDecelCommand() : CommandBase("TimeIntakeDecelCommand"){
		//Requires(m_gearIntake.get());
	}
	void Initialize(){
		m_gearIntake->SetIntakePos(0);
	}
	void Execute(){}
	bool IsFinished(){
		return m_gearIntake->GetPivotSpeed() <= 0;
	}
	void End(){
		printf("Intake Decel Time %f\n", TimeSinceInitialized());
	}
	void Interrupted(){}
};

#endif  // TimeIntakeDecelCommand_H
