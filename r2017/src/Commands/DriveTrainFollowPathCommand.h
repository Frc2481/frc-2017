/*
 * DriveTrainFollowPathCommand.h
 *
 *  Created on: Jan 28, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_DRIVETRAINFOLLOWPATHCOMMAND_H_
#define SRC_COMMANDS_DRIVETRAINFOLLOWPATHCOMMAND_H_

#include "PathGenerator.h"

class DriveTrainFollowPathCommand : public CommandBase {
public:
	Waypoint* m_path;
	int m_length;
	TrajectoryCandidate m_candidate;
	Segment* m_flTrajectory;
	Segment* m_frTrajectory;
	Segment* m_blTrajectory;
	Segment* m_brTrajectory;
	DriveTrainFollowPathCommand(std::string name) : CommandBase(name) {}

	void GeneratePath(Waypoint* path, int length) {
		m_path = path;
		m_length = length;
		m_flTrajectory = (Segment*) malloc(length * sizeof(Segment));
		m_frTrajectory = (Segment*) malloc(length * sizeof(Segment));
		m_blTrajectory = (Segment*) malloc(length * sizeof(Segment));
		m_brTrajectory = (Segment*) malloc(length * sizeof(Segment));
		PathGenerator::GetInstance()->PreparePath(m_path, 2, &m_candidate);
		PathGenerator::GetInstance()->GeneratePath(&m_candidate, m_flTrajectory, m_frTrajectory, m_blTrajectory, m_brTrajectory);
	}

	void Initialize(){

	}
	void Execute(){}
	bool IsFinished(){}
	void End(){}
	void Interrupted(){}
};




#endif /* SRC_COMMANDS_DRIVETRAINFOLLOWPATHCOMMAND_H_ */
