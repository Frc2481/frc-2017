#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "ControllerMap.h"

class OI
{
private:
	static const int DRIVE_STICK_PORT = 0;
	static const int OPERATOR_STICK_PORT = 1;
	Joystick2481* m_driverStick;
	Joystick* m_operatorStick;

	Button* m_shifterButton;
	Button* m_fieldCentricButton;
	Button* m_flickerGearButton;
	AnalogJoystickButton* m_climberButton;
	Button* m_gearLidButton;
	Button* m_frontCameraButton;
	Button* m_backCameraButton;
	Button* m_leftCameraButton;
	Button* m_rightCameraButton;
	Button* m_cameraMenuButton;

	Button* m_shooterOnButton;
	Button* m_shooterOffButton;
	Button* m_incShooterButton;
	Button* m_decShooterButton;
	Button* m_shooterHoodToggleButton;
	Button* m_gearLidButtonOP;
	Button* m_flickerGearButtonOP;
	AnalogJoystickButton* m_fireTrigger;
	AnalogJoystickButton* m_incOurGear;
	AnalogJoystickButton* m_decOurGear;
	AnalogJoystickButton* m_incTheirGear;
	AnalogJoystickButton* m_decTheirGear;

public:
	OI();
	Joystick2481* GetDriverStick();
};

#endif
