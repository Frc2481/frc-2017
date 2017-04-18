#ifndef RotateToCameraAngleCommandGroup_H
#define RotateToCameraAngleCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/SetAngleOptimizedCommand.h"
#include "Commands/SetModulesForSpinInPlaceCommand.h"
#include "Commands/DriveTrainZeroDriveEncodersCommand.h"
#include "Commands/MotionMagicRotateToAngleCommand.h"

class RotateToCameraAngleCommandGroup : public CommandGroup {
public:
	RotateToCameraAngleCommandGroup() : CommandGroup("RotateToCameraAngleCommandGroup"){
		AddSequential(new SetAngleOptimizedCommand(true));
		AddSequential(new SetModulesForSpinInPlaceCommand(),.2);
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new MotionMagicCameraRotationCommand());
	}
};

#endif  // RotateToCameraAngleCommand_H
