/*
 * ControllerMap.h
 *
 *  Created on: Jan 24, 2017
 *      Author: FIRSTMentor
 */

#ifndef CONTROLLERMAP_H_
#define CONTROLLERMAP_H_

#include "XboxController.h"
#include "Components/AnalogJoystickButton.h"
#include "Components/POVJoystickButton.h"
#include "Components/Joystick2481.h"

#define SHIFTER_BUTTON    				new JoystickButton(m_driverStick, XB_RIGHT_BUMPER)
#define FIELD_CENTRIC_BUTTON			new JoystickButton(m_driverStick, XB_LEFT_BUMPER)
#define UNLOAD_GEAR_BUTTON				new JoystickButton(m_driverStick, XB_B_BUTTON)
#define PLACE_ON_GROUND_BUTTON			new JoystickButton(m_driverStick, XB_Y_BUTTON)
#define INTAKE_BUTTON					new AnalogJoystickButton(m_driverStick, XB_RIGHT_TRIGGER, 0.5);
#define CLIMBER_BUTTON					new AnalogJoystickButton(m_driverStick, XB_LEFT_TRIGGER, 0.5)
#define GEAR_LID_BUTTON					new JoystickButton(m_driverStick, XB_X_BUTTON)
#define FRONT_CAMERA_BUTTON				new POVJoystickButton(m_driverStick, 0, XB_DPAD_TOP)
#define RIGHT_CAMERA_BUTTON				new POVJoystickButton(m_driverStick, 0, XB_DPAD_RIGHT)
#define LEFT_CAMERA_BUTTON				new POVJoystickButton(m_driverStick, 0, XB_DPAD_LEFT)
#define BACK_CAMERA_BUTTON				new POVJoystickButton(m_driverStick, 0, XB_DPAD_BOTTOM)
#define CAMERA_MENU_BUTTON				new JoystickButton(m_driverStick, XB_BACK_BUTTON)

//#define SHOOTER_MAX_SPEED				new JoystickButton(m_driverStick, XB_Y_BUTTON)

//#define INC_OUR_GEAR_COUNTER			new AnalogJoystickButton(m_operatorStick, XB_LEFT_Y_AXIS, 0.5)
//#define UNLOAD_GEAR_BUTTON_OP			new AnalogJoystickButton(m_operatorStick, XB_LEFT_TRIGGER, 0.5)
#define SHOOTER_ON_BUTTON				new JoystickButton(m_operatorStick, XB_RIGHT_BUMPER)
#define SHOOTER_OFF_BUTTON				new JoystickButton(m_operatorStick, XB_LEFT_BUMPER)
#define GEAR_LID_BUTTON_OP				new JoystickButton(m_operatorStick, XB_A_BUTTON)
#define FLICKER_GEAR_BUTTON_OP			new JoystickButton(m_operatorStick, XB_X_BUTTON)
//#define LOADER_BUTTON					new JoystickButton(m_operatorStick, XB_B_BUTTON)
//#define SHOOTER_TOGGLE_BUTTON			new JoystickButton(m_operatorStick, XB_A_BUTTON)
#define INC_SHOOTER_BUTTON				new POVJoystickButton(m_operatorStick,0, XB_DPAD_TOP)
#define DEC_SHOOTER_BUTTON				new POVJoystickButton(m_operatorStick,0, XB_DPAD_BOTTOM)
#define SHOOTER_HOOD_TOOGLE_BUTTON		new JoystickButton(m_operatorStick, XB_B_BUTTON)
#define FIRE_TRIGGER					new AnalogJoystickButton(m_operatorStick, XB_RIGHT_TRIGGER, 0.5)
#define MANUAL_INTAKE_UP				new AnalogJoystickButton(m_operatorStick, XB_RIGHT_Y_AXIS, 0.25)
#define MANUAL_INTAKE_DOWN				new AnalogJoystickButton(m_operatorStick, XB_RIGHT_Y_AXIS, -0.25)

//#define INTAKE_BEAM_BUTTON				new AnalogJoystickButton(m_thirdStick, XB_RIGHT_TRIGGER, 0.5)
//#define HP_BEAM_BUTTON					new AnalogJoystickButton(m_thirdStick, XB_LEFT_TRIGGER, 0.5)

#endif /* CONTROLLERMAP_H_ */
