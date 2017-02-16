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

#define SHIFTER_BUTTON    				new JoystickButton(m_driverStick, XB_RIGHT_BUMPER)
#define FLICKER_GEAR_BUTTON				new JoystickButton(m_driverStick, XB_B_BUTTON)
#define CLIMBER_BUTTON					new JoystickButton(m_driverStick, XB_RIGHT_TRIGGER)
#define GEAR_LID_BUTTON					new JoystickButton(m_driverStick, XB_X_BUTTON)
#define SHOOTER_MAX_SPEED				new JoystickButton(m_driverStick, XB_Y_BUTTON)

#define HOPPER_BUTTON					new JoystickButton(m_operatorStick, XB_X_BUTTON)
#define LOADER_BUTTON					new JoystickButton(m_operatorStick, XB_B_BUTTON)
#define SHOOTER_TOGGLE_BUTTON			new JoystickButton(m_operatorStick, XB_A_BUTTON)
#define INC_SHOOTER_BUTTON				new JoystickButton(m_operatorStick, XB_RIGHT_BUMPER)
#define DEC_SHOOTER_BUTTON				new JoystickButton(m_operatorStick, XB_LEFT_BUMPER)
#define SHOOTER_HOOD_TOOGLE_BUTTON		new JoystickButton(m_operatorStick, XB_LEFT_TRIGGER)
//#define FIRE_TRIGGER					new AnalogJoystickButton(m_operatorStick, XB_RIGHT_TRIGGER, 0.5)

#endif /* CONTROLLERMAP_H_ */
