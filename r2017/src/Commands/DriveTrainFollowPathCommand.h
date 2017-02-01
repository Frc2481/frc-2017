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
	DriveTrainFollowPathCommand(std::string name) : CommandBase(name) {
		TrajectoryFollowerLooper::GetInstance()->Start();
	}

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
		m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->ResetDriveEncoders();
		m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE)->ResetDriveEncoders();
		m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->ResetDriveEncoders();
		m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE)->ResetDriveEncoders();
		TrajectoryFollower::GetInstance()->Reset();
		TrajectoryFollower::GetInstance()->SetTrajectories(m_frTrajectory, m_flTrajectory, m_brTrajectory, m_blTrajectory);
		TrajectoryFollowerLooper::GetInstance()->SetActive(true);
	}
	void Execute(){}
	bool IsFinished(){
		return TrajectoryFollower::GetInstance()->TrajectoryFinished();
	}
	void End(){
		TrajectoryFollowerLooper::GetInstance()->SetActive(false);
	}
	void Interrupted(){
		End();
	}
};




#endif /* SRC_COMMANDS_DRIVETRAINFOLLOWPATHCOMMAND_H_ */
