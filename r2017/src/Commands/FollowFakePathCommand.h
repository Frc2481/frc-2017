#ifndef FollowFakePathCommand_H
#define FollowFakePathCommand_H

#include "../CommandBase.h"
#include "DriveTrainFollowPathCommand.h"

class FollowFakePathCommand : public DriveTrainFollowPathCommand {
public:
	FollowFakePathCommand() : DriveTrainFollowPathCommand("FollowFakePathCommand"){
		Requires(CommandBase::m_driveTrain.get());
	}
	void Initialize(){
//		Waypoint initial = {-4,-1,d2r(45)};
//		Waypoint final = {2, 4, 0};
//		Waypoint middle = {-1, 2, 0};
//		Waypoint path[3] = {initial, middle, final};
//		GeneratePath(path, 3);
//		DriveTrainFollowPathCommand::Initialize();
		double setpoint = SmartDashboard::GetNumber("Drive Velocity Setpoint TEST", 0.0);
		//double convertDistance = CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(setpoint);
		CommandBase::m_driveTrain->PerformMotionMagic(setpoint);
	}
	void Execute(){}
	bool IsFinished(){
		return false;
	}
	void End(){}
	void Interrupted(){}
};

#endif  // FollowFakePathCommand_H
