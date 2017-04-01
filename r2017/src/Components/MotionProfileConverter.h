/*
 * MotionProfileConverter.h
 *
 *  Created on: Mar 30, 2017
 *      Author: Team2481
 */

#ifndef SRC_COMPONENTS_MOTIONPROFILECONVERTER_H_
#define SRC_COMPONENTS_MOTIONPROFILECONVERTER_H_

#include <vector>
#include "CANTalon.h"

class MotionProfileConverter {
private:
	double m_timeSegment;
public:
	MotionProfileConverter(double interval);
	virtual ~MotionProfileConverter();
	void ConvertDrive(std::vector<double*>* input, CANTalon::TrajectoryPoint* output, int size);
	void ConvertSteer(std::vector<double*>* input, CANTalon::TrajectoryPoint* output, int size);
};

#endif /* SRC_COMPONENTS_MOTIONPROFILECONVERTER_H_ */
