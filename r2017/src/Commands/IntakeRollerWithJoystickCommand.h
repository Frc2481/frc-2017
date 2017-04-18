#ifndef IntakeRollerWithJoystickCommand_H
#define IntakeRollerWithJoystickCommand_H

#include "../CommandBase.h"

class IntakeRollerWithJoystickCommand : public CommandBase {
public:
	IntakeRollerWithJoystickCommand() : CommandBase("IntakeRollerWithJoystickCommand"){}
	void Initialize(){}
	void Execute(){
		double speed = oi->GetOperatorStick()->GetRawAxis(XB_RIGHT_Y_AXIS);
		m_gearIntake->IntakeGear(speed);
	}
	bool IsFinished(){
		return false;
	}
	void End(){
		printf("IntakeJoystick StopIntake\n");
		m_gearIntake->StopIntake();
	}
	void Interrupted(){
		End();
	}
};

#endif  // IntakeRollerWithJoystickCommand_H
