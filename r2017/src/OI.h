#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "ControllerMap.h"

class OI
{
private:
	static const int DRIVE_STICK_PORT = 1;
	Joystick* driverStick;
public:
	OI();
	Joystick* GetDriverStick();
	Button* m_shifterButton;
};

#endif
