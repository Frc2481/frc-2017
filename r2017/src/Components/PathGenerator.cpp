/*
 * PathGenerator.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: FIRSTMentor
 */

#include <Components/PathGenerator.h>
#include <RobotParameters.h>

PathGenerator::PathGenerator() {}

PathGenerator::~PathGenerator() {}

PathGenerator* PathGenerator::GetInstance(){
	if (!m_pathGenerator){
		m_pathGenerator = new PathGenerator();
	}
	return m_pathGenerator;
}

void PathGenerator::GeneratePath(TrajectoryCandidate* candidate, Segment *flWheel, Segment *frWheel, Segment *blWheel, Segment *brWheel){
	int length = candidate->length;
	Segment *trajectory = (Segment*) malloc(length * sizeof(Segment));
	pathfinder_generate(candidate, trajectory);
	pathfinder_modify_swerve(trajectory, length, flWheel, frWheel, blWheel, brWheel, ROBOT_WIDTH, ROBOT_LENGTH, SWERVE_DEFAULT);
}
void PathGenerator::PreparePath(Waypoint* path, int pathLength, TrajectoryCandidate *candidate){
	pathfinder_prepare(path,
			pathLength,
			FIT_HERMITE_CUBIC,
			m_sampleCount,
			m_timeStep,
			m_maxVelocity,
			m_maxAcceleration,
			m_maxJerk,
			candidate);
}

