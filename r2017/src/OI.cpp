#include "OI.h"

OI::OI()
{
	driverStick = new Joystick(DRIVE_STICK_PORT);
}

Joystick* OI::GetDriverStick(){
	return driverStick;
}
