#ifndef TestPathPlannerProfilesCommand_H
#define TestPathPlannerProfilesCommand_H

#include "../CommandBase.h"
#include "Components/PathPlanner.h"

class TestPathPlannerProfilesCommand : public CommandBase {
public:
	TestPathPlannerProfilesCommand() : CommandBase("TestPathPlannerProfilesCommand"){}
	void Initialize(){
		double prevTime = frc::GetFPGATime();
		PathPlanner p;
		p.addWaypoint(0.0, 0.0, 0.0);
		p.addWaypoint(50.0, 50.0, 30.0);
		double totalTime = 1.5;//p.estimateTime(60, 45);
		p.calculate(totalTime, MP_TIMESTEP, ROBOT_TRACK_WIDTH, ROBOT_TRACK_LENGTH, MP_MAX_ACCEL);
		double curTime = frc::GetFPGATime();
		printf("Process Time %f\n", prevTime - curTime);
		printf("Size of Path %d\n", p.leftUpperPath->size());
	}
	void Execute(){}
	bool IsFinished(){
		return true;
	}
	void End(){}
	void Interrupted(){}
};

#endif  // TestPathPlannerProfilesCommand_H
