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
	Joystick2481* m_operatorStick;
//	Joystick2481* m_thirdStick;

	Button* m_shifterButton;
	Button* m_fieldCentricButton;
	//Button* m_flickerGearButton;
	Button* m_unloadGearButton;
	Button* m_placeOnGroundButton;
	AnalogJoystickButton* m_intakeButton;
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
	AnalogJoystickButton* m_unloadGearButtonOP;
	AnalogJoystickButton* m_fireTrigger;
	AnalogJoystickButton* m_incOurGear;
	AnalogJoystickButton* m_decOurGear;
	AnalogJoystickButton* m_incTheirGear;
	AnalogJoystickButton* m_decTheirGear;
	AnalogJoystickButton* m_manualIntakeButtonUp;
	AnalogJoystickButton* m_manualIntakeButtonDown;

//	AnalogJoystickButton* m_hpBeamButton;
//	AnalogJoystickButton* m_intakeBeamButton;

public:
	OI();
	Joystick2481* GetDriverStick();
	Joystick2481* GetOperatorStick();
};

#endif
