#ifndef AutoDriveToGearCommand_H
#define AutoDriveToGearCommand_H

#include <Commands/CommandGroup.h>
#include "Commands/DriveTrainZeroYawCommand.h"
#include "Commands/DriveTrainEnableGyroCorrectionCommand.h"
#include "Commands/SetAngleOptimizedCommand.h"
#include "Commands/DriveTrainSetGyroOffsetCommand.h"
#include "Commands/DriveTrainWaitForHeadingCommand.h"
#include "Commands/AutoDriveCommand.h"
#include "Commands/SetDriveTalonToSlaveCommand.h"
#include "Commands/GeneratePathToTargetCommand.h"
#include "Commands/ToggleCoastToBrakeCommand.h"
#include "Commands/GearFlickCommandGroup.h"
#include "Commands/DriveToDistanceEncoderCommand.h"
#include "Commands/DriveTrainDisableGyroCorrectionCommand.h"

class AutoDriveToGearCommandGroup : public CommandGroup {
public:
	AutoDriveToGearCommandGroup() : CommandGroup("AutoDriveToGearCommandGroup"){
		AddSequential(new ToggleCoastToBrakeCommand(false));
		AddSequential(new DriveTrainZeroYawCommand());
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new SetAngleOptimizedCommand(false));
//		AddSequential(new DriveTrainSetGyroOffsetCommand(30));
//		AddSequential(new DriveTrainWaitForHeadingCommand(30));
		//AddSequential(new AutoDriveCommand(.1,0,0,.11));
		//AddSequential(new SwerveModuleRotateToAngleCommand(270,false));
		//AddSequential(new SetDriveTalonToSlaveCommand(true));
		//AddSequential(new GeneratePathToTargetCommand());
		AddSequential(new DriveToDistanceEncoderCommand());
		AddSequential(new GearFlickCommandGroup());
		AddSequential(new AutoDriveCommand(0,0.5,0,.5));
		AddSequential(new ToggleCoastToBrakeCommand(true));
		AddSequential(new DriveTrainDisableGyroCorrectionCommand());
		AddSequential(new SetAngleOptimizedCommand(true));
	}
};

#endif  // AutoDriveToGearCommand_H
