/*
 * RobotParameters.h
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */
#ifndef ROBOT_PARAMETERS_H
#define ROBOT_PARAMETERS_H
#include "Components/PersistedSettings.h"
#define DEBUGGING 1
#define ROBOT_SETTING_PATH "settings.cfg"
#define ENCODER_OFFSET_FILENAME "/home/lvuser/Encoder_Offsets"

//Robot Base
	#define ROBOT_LENGTH 22
	#define ROBOT_WIDTH 25

#define INCHES_PER_REV 3.25 * 3.14159265 //inches
#define WHEEL_DIAMETER_INCHES 3.25
#define ENCODER_TICKS_PER_REV 21.75 * 128
#define MM_PER_REV 25.4 * INCHES_PER_REV
//#define ENCODER_TICKS_PER_INCH 8725.56317
//#define ENCODER_TICKS_PER_MM 343.526109

#define GEAR_FLICK_DELAY 1.0
#define HOPPER_SPEED 0.2

#endif
