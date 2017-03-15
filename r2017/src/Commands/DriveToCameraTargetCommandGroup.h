#ifndef DriveToCameraTargetCommandGroup_H
#define DriveToCameraTargetCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/RotateToAngleGyroCommand.h"
#include "Commands/DriveMotionMagicDistanceCommand.h"
#include "Commands/WaitCommand.h"


class DriveToCameraTargetCommandGroup : public CommandGroup {
public:
	DriveToCameraTargetCommandGroup() : CommandGroup("DriveToCameraTargetCommandGroup"){
		AddSequential(new CameraRotateToAngle(true));
		AddSequential(new WaitCommand(.5));
		AddSequential(new DriveCameraDistanceCommand());
	}
};

#endif  // DriveToCameraTargetCommandGroup_H
