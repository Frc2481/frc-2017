#ifndef IntakePivotWithJoyStickCommand_H
#define IntakePivotWithJoyStickCommand_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../XboxController.h"

class IntakePivotWithJoyStickCommand : public CommandBase {
public:
	IntakePivotWithJoyStickCommand() : CommandBase("IntakePivotWithJoystickCommand"){
		Requires(m_gearIntake.get());
	}
	void Initialize(){}
	void Execute(){
		double speed = oi->GetOperatorStick()->GetRawAxis(XB_LEFT_Y_AXIS);
		if(!DriverStation::GetInstance().IsAutonomous()){
			m_gearIntake->SetIntakeOpenLoop(speed);
		}
	}
	bool IsFinished(){
		return false;
	}
	void End(){
		m_gearIntake->SetIntakeOpenLoop(0);
	}
	void Interrupted(){}
};

#endif  // IntakePivotWithJoyStickCommand_H
