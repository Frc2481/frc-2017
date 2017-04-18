#ifndef RotateToAngleMotionMagicCommandGroup_H
#define RotateToAngleMotionMagicCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/AutoDriveCommand.h"
#include "Commands/MotionMagicRotateToAngleCommand.h"
#include "Commands/SetModulesForSpinInPlaceCommand.h"

class RotateToAngleMotionMagicCommandGroup : public CommandGroup {
public:
	RotateToAngleMotionMagicCommandGroup(double angle) : CommandGroup("RotateToAngleMotionMagicCommandGroup"){
		//Takes angles on -180 to 180 spectrum with 0 being front of the robot
		AddSequential(new SetAngleOptimizedCommand(true));
		AddSequential(new SetModulesForSpinInPlaceCommand(), .2);
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new MotionMagicRotateToAngleCommand(angle));
	}
};

#endif  // RotateToAngleMotionMagicCommandGroup_H
