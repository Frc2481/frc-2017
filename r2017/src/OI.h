#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "ControllerMap.h"

class OI
{
private:
	static const int DRIVE_STICK_PORT = 0;
	static const int OPERATOR_STICK_PORT = 1;
	Joystick* m_driverStick;
	Joystick* m_operatorStick;
	Button* m_shifterButton;
	Button* m_flickerGearButton;
	Button* m_hopperButton;
	Button* m_loaderButton;
	Button* m_shooterToggleButton;
	Button* m_incShooterButton;
	Button* m_decShooterButton;
	Button* m_climberButton;
	Button* m_gearLidButton;
	Button* m_shooterHoodToggleButton;
	AnalogJoystickButton* m_fireTrigger;
public:
	OI();
	Joystick* GetDriverStick();
};

#endif
