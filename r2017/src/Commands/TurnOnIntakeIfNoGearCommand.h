#ifndef TurnOnIntakeIfNoGearCommand_H
#define TurnOnIntakeIfNoGearCommand_H

#include "../CommandBase.h"

class TurnOnIntakeIfNoGearCommand : public CommandBase {
private:
	double m_speed;
public:
	TurnOnIntakeIfNoGearCommand(double speed) : CommandBase("TurnOnIntakeIfNoGearCommand"){
		Requires(m_gearIntakeRoller.get());
		m_speed = speed;
	}
	void Initialize(){
		if(m_gearIntake->GetHasGear() == false){
			m_gearIntakeRoller->IntakeGear(m_speed);
		}
	}
	void Execute(){}
	bool IsFinished(){
		return m_gearIntake->GetHasGear();
	}
	void End(){
		m_gearIntakeRoller->StopIntake();
	}
};

#endif  // TurnOnIntakeIfNoGearCommand_H
