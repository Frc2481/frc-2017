/*
 * AdaptivePathPlanner.h
 *
 *  Created on: Feb 24, 2017
 *      Author: Team2481
 */

#ifndef SRC_COMPONENTS_ADAPTIVEPATHPLANNER_H_
#define SRC_COMPONENTS_ADAPTIVEPATHPLANNER_H_
#include "Subsystems/DriveTrain.h"

class AdaptivePathPlanner {
private:
	double m_velocity;
	double m_accel;
	const double m_dt = .01;
	double m_maxS;
	double m_minS;
public:
	AdaptivePathPlanner();
	virtual ~AdaptivePathPlanner();
	double GetConstrainedSpeed(double speed, double newSpeed);
	void GenerateNextPoint(double x, double y, double speed, double distance, double targetAngle);
};

#endif /* SRC_COMPONENTS_ADAPTIVEPATHPLANNER_H_ */
