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

#define WHEEL_CIRCUMFERENCE 10.21
#define ENCODER_TICKS_PER_REV 89088
#define ENCODER_TICKS_PER_INCH 8725.56317
#define ENCODER_TICKS_PER_MM 343.526109

#endif
