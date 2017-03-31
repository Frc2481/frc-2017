/*
 * MotionProfileConverter.h
 *
 *  Created on: Mar 30, 2017
 *      Author: Team2481
 */

#ifndef SRC_COMPONENTS_MOTIONPROFILECONVERTER_H_
#define SRC_COMPONENTS_MOTIONPROFILECONVERTER_H_

class MotionProfileConverter {
private:
	double m_timeSegment;
public:
	MotionProfileConverter(double interval);
	virtual ~MotionProfileConverter();
	void ConvertDrive(double input[][3], double output[][3], int size);
	void ConvertSteer(double input[][3], double output[][3], int size);
};

#endif /* SRC_COMPONENTS_MOTIONPROFILECONVERTER_H_ */
