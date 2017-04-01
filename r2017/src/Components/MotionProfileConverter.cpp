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
#include "CANTalon.h"

MotionProfileConverter::MotionProfileConverter(double interval) {
	// TODO Auto-generated constructor stub
	m_timeSegment = interval;
}

MotionProfileConverter::~MotionProfileConverter() {
	// TODO Auto-generated destructor stub
}

void MotionProfileConverter::ConvertDrive(std::vector<double*>* input, CANTalon::TrajectoryPoint* output, int size) {
	double distance = 0;
	for(int i=0; i<size-1; i++){
		double deltaDistance = Translation2D(input->at(i+1)[0] - input->at(i)[0], input->at(i+1)[1] - input->at(i)[1]).norm();
		distance += deltaDistance;
		output[i].position = distance;
		output[i].velocity = (deltaDistance / m_timeSegment) * 60;
		output[i].timeDurMs = m_timeSegment * 1000;
		//printf("%f\t%f\t%f\t%f\t%f\n", input->at(i)[0], input->at(i)[1], input->at(i+1)[0], input->at(i+1)[1], deltaDistance);
	}
}

void MotionProfileConverter::ConvertSteer(std::vector<double*>* input, CANTalon::TrajectoryPoint* output, int size) {
	for(int i=0; i<size-1; i++){
		//TODO: Rotate deltaAngle by RobotAngle
		Rotation2D deltaAngle = Rotation2D(input->at(i+1)[0] - input->at(i)[0], input->at(i+1)[1] - input->at(i)[1], false);
		output[i].position = (deltaAngle.getDegrees() - input->at(i)[2]) / 360.0;
		output[i].velocity = 0;//deltaAngle.getDegrees() / m_timeSegment;
		output[i].timeDurMs = m_timeSegment * 1000;
		//printf("%f\t%f\t%f\t%f\t%f\t%f\n", input->at(i)[0], input->at(i)[1], input->at(i+1)[0], input->at(i+1)[1], deltaAngle.getDegrees(), output[i].position);

	}
}
