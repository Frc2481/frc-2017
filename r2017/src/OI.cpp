#include "OI.h"
#include "Commands/DriveTrainShiftButtonCommand.h"

OI::OI()
{
	driverStick = new Joystick(DRIVE_STICK_PORT);

	m_shifterButton = SHIFTER_BUTTON;
	m_shifterButton->WhileHeld(new DriveTrainShiftButtonCommand());
}

Joystick* OI::GetDriverStick(){
	return driverStick;
}

