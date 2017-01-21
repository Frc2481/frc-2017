/*
 * DriveCommand.h
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */
#ifndef DriveCommand_H
#define DriveCommand_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../XboxController.h"

class DriveCommand: public CommandBase
{
public:
	DriveCommand(){
		Requires(drivetrain.get());
	}
	void Initialize(){}
	void Execute() {
		double x = oi->GetDriverStick()->GetRawAxis(XB_LEFT_X_AXIS);
		double y = oi->GetDriverStick()->GetRawAxis(XB_LEFT_Y_AXIS);
		double z = oi->GetDriverStick()->GetRawAxis(XB_RIGHT_X_AXIS);

//		if (fabs(x) < .2) x = 0;
//		if (fabs(y) < .2) y = 0;
//		if (fabs(z) < .2) z = 0;

		if (!DriverStation::GetInstance().IsAutonomous()) {
			drivetrain->Drive(x,y,z);
		}
	}
	bool IsFinished(){
		return false;
	}
	void End(){}
	void Interrupted(){}
};

#endif
