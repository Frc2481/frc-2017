#ifndef AddWaypointsToPathCommand_H
#define AddWaypointsToPathCommand_H

#include "../CommandBase.h"

class AddWaypointsToPathCommand : public CommandBase {
public:
	AddWaypointsToPathCommand(){}
	void Initialize(){
		//PathGenerator::GetInstance()->AddDynamicWaypoint()
	}
	void Execute(){}
	bool IsFinished(){}
	void End(){}
	void Interrupted(){}
};

#endif  // AddWaypointsToPathCommand_H
