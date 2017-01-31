/*
 * TrajectoryFollower.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Team2481
 */

#ifndef SRC_COMPONENTS_TRAJECTORYFOLLOWER_H_
#define SRC_COMPONENTS_TRAJECTORYFOLLOWER_H_
#include "pathfinder.h"

class TrajectoryFollower {
private:
	TrajectoryFollower();
	EncoderFollower m_flFollower, m_frFollower, m_blFollower, m_brFollower;
	EncoderConfig m_flConfig, m_frConfig, m_blConfig, m_brConfig;
	Segment *m_flTrajectory;
	int m_flLength;
	Segment *m_frTrajectory;
	int m_frLength;
	Segment *m_blTrajectory;
	int m_blLength;
	Segment *m_brTrajectory;
	int m_brLength;
public:
	virtual ~TrajectoryFollower();
	static TrajectoryFollower* GetInstance();
	void PeriodicUpdate();
	void SetTrajectories(Segment *segment1, Segment *segment2, Segment *segment3, Segment *segment4);
	void Reset();
	void SetEncoderConfig(int initPos, int ticksPerRev, double wheelCircum, double p, double i, double d, double v, double a);

};

#endif /* SRC_COMPONENTS_TRAJECTORYFOLLOWER_H_ */
