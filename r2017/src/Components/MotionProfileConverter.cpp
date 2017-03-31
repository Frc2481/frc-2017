/*
 * MotionProfileConverter.cpp
 *
 *  Created on: Mar 30, 2017
 *      Author: Team2481
 */

#include <Components/MotionProfileConverter.h>
#include "utils/Translation2D.h"
#include "utils/Rotation2D.h"
#include <math.h>

MotionProfileConverter::MotionProfileConverter(double interval) {
	// TODO Auto-generated constructor stub
	m_timeSegment = interval;
}

MotionProfileConverter::~MotionProfileConverter() {
	// TODO Auto-generated destructor stub
}

void MotionProfileConverter::ConvertDrive(double input[][3], double output[][3], int size) {
	for(int i=0; i<size; i++){
		double distance = Translation2D(input[i][0], input[i][1]).norm();
		output[i][0] = distance;
		output[i][1] = distance / m_timeSegment;
		output[i][2] = m_timeSegment;
	}
}

void MotionProfileConverter::ConvertSteer(double input[][3], double output[][3], int size) {
	for(int i=0; i<size; i++){
		//TODO: Rotate deltaAngle by RobotAngle
		Rotation2D deltaAngle = Rotation2D(input[i+1][0] - input[i][0], input[i+1][1] - input[i][1], false);
		output[i][0] = deltaAngle.getDegrees() - input[i][3];
		output[i][1] = 0;//deltaAngle.getDegrees() / m_timeSegment;
		output[i][2] = m_timeSegment;
	}
}
