/*
 * PathGenerator.h
 *
 *  Created on: Jan 28, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMPONENTS_PATHGENERATOR_H_
#define SRC_COMPONENTS_PATHGENERATOR_H_
#include "pathfinder.h"
#include <vector>


class PathGenerator {
private:
	static PathGenerator* m_pathGenerator;
	std::vector<Waypoint> m_dynamicPath;
	const int m_sampleCount = PATHFINDER_SAMPLES_HIGH;
	const double m_timeStep = 0.001;
	const double m_maxVelocity = 15;
	const double m_maxAcceleration = 10;
	const double m_maxJerk = 60;
	PathGenerator();
	virtual ~PathGenerator();
public:
	static PathGenerator* GetInstance();
	void GeneratePath(TrajectoryCandidate* candidate, Segment *flWheel, Segment *frWheel, Segment *blWheel, Segment *brWheel);
	void PreparePath(Waypoint* path, int pathLength, TrajectoryCandidate *candidate);
	void AddDynamicWaypoint(double x, double y, double angle);
	std::vector<Waypoint>* GetDynamicPath();
};

PathGenerator* PathGenerator::m_pathGenerator = 0;


#endif /* SRC_COMPONENTS_PATHGENERATOR_H_ */
