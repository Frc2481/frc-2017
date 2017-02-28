/*
 * AdaptivePathPlanner.cpp
 *
 *  Created on: Feb 24, 2017
 *      Author: Team2481
 */

#include <Components/AdaptivePathPlanner.h>
#include "RobotParameters.h"
#include "../CommandBase.h"

AdaptivePathPlanner::AdaptivePathPlanner() {
	// TODO Auto-generated constructor stub
	m_velocity = (RPM * ENCODER_REV_PER_WHEEL_REV) * .9;
	m_accel = m_velocity / 1.233;
}

AdaptivePathPlanner::~AdaptivePathPlanner() {
	// TODO Auto-generated destructor stub
}

double AdaptivePathPlanner::GetConstrainedSpeed(double speed, double newSpeed) {
	m_maxS = std::min(m_velocity, speed + (m_accel * m_dt));
	m_minS = std::max(0.0, speed - (m_accel*m_dt));
	double constrainedSpeed = std::min(std::max(m_minS, newSpeed), m_maxS);
	return constrainedSpeed;
}

void AdaptivePathPlanner::GenerateNextPoint(double x, double y, double speed, double distance, double targetAngle) {
	double newAccel = m_accel * m_dt;
	double newSpeed = speed + newAccel;
	double constrainedSpeed = GetConstrainedSpeed(speed, newSpeed);
	double newDistance = distance - (newSpeed / m_dt);
	double deltaDistance = distance - newDistance;
	double newX = (newDistance/distance) * x;
	double newY = (newDistance/distance) * y;
	if(constrainedSpeed == m_maxS){

	}

}
