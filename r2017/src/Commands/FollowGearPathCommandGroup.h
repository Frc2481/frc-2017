#ifndef FollowGearPathCommandGroup_H
#define FollowGearPathCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/GenerateGearRotationPathCommand.h"
#include "Commands/GeneratePathToTargetCommand.h"
#include "Commands/AutoDriveCommand.h"
#include "Commands/SwerveModuleRotateToAngleCommand.h"
#include "Commands/SetDriveTalonToSlaveCommand.h"
#include "Commands/SetAngleOptimizedCommand.h"
#include "Commands/WaitCommand.h"

class FollowGearPathCommandGroup : public CommandGroup {
public:
	FollowGearPathCommandGroup() : CommandGroup("FollowGearPathCommandGroup"){
		AddSequential(new SetAngleOptimizedCommand(false));
		AddSequential(new SwerveModuleRotateToAngleCommand(270.0,false)); //Change to 0, true for vision processing
		AddSequential(new SetDriveTalonToSlaveCommand(true));
		AddSequential(new GeneratePathToTargetCommand());
		AddSequential(new WaitCommand(1));
		AddSequential(new AutoDriveCommand(0,0,.1,.11));
		AddSequential(new SetDriveTalonToSlaveCommand(true));
		AddSequential(new GenerateGearRotationPathCommand());
		AddSequential(new SetAngleOptimizedCommand(true));
	}
};

#endif  // FollowGearPathCommandGroup_H
