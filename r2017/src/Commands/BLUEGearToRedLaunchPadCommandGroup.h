#ifndef BLUEGearToRedLaunchPadCommandGroup_H
#define BLUEGearToRedLaunchPadCommandGroup_H

#include <Commands/CommandGroup.h>
#include "../CommandBase.h"
#include "Commands/AutoDriveCommand.h"
#include "Commands/SwerveModuleRotateToAngleCommand.h"
#include "Commands/SetAngleOptimizedCommand.h"
#include "Commands/DriveTrainDisableGyroCorrectionCommand.h"
#include "Commands/DriveTrainEnableGyroCorrectionCommand.h"
#include "Commands/DriveTrainZeroYawCommand.h"
#include "Commands/ToggleCoastToBrakeCommand.h"
#include "Commands/DriveMotionMagicDistanceCommand.h"
#include "Commands/GearFlickCommandGroup.h"
#include "Commands/RotateToAngleGyroCommand.h"
#include "Commands/DriveTrainZeroDriveEncodersCommand.h"
#include "Commands/GearFlickCommand.h"
#include "Commands/GearResetCommand.h"
#include "Commands/PrintCommand.h"
#include "Commands/WaitCommand.h"
#include "Commands/LoaderOffCommand.h"
#include "Commands/HopperOffCommand.h"
#include "Commands/PauseCommand.h"
#include "Commands/ShooterSetHoodCommand.h"
#include "Commands/DriveTrainWaitForHeadingCommand.h"
#include "Commands/DriveTrainSetOriginCommand.h"

class BLUEGearToRedLaunchPadCommandGroup : public CommandGroup {
public:
	BLUEGearToRedLaunchPadCommandGroup() : CommandGroup("BLUEGearToRedLaunchPadCommandGroup"){
		AddSequential(new ToggleCoastToBrakeCommand(false));
		AddSequential(new DriveTrainZeroYawCommand());
		AddSequential(new SetAngleOptimizedCommand(false));
		AddSequential(new ShooterSetHoodCommand(true));
		AddSequential(new SwerveModuleRotateToAngleCommand(270, false), .5);
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(94), false), 4);

		AddSequential(new DriveTrainDisableGyroCorrectionCommand());
		AddSequential(new SetAngleOptimizedCommand(true));
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(-30));
		AddSequential(new DriveTrainWaitForHeadingCommand(-30), 1.25);
		AddSequential(new SetAngleOptimizedCommand(false));

		AddSequential(new SwerveModuleRotateToAngleCommand(0,false));
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(27), false), 2);
		AddSequential(new GearFlickCommand());
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(-30), false), 2);
		AddSequential(new DriveTrainDisableGyroCorrectionCommand());
		AddSequential(new SetAngleOptimizedCommand(true));
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new DriveTrainWaitForHeadingCommand(0));
		AddSequential(new SetAngleOptimizedCommand(false));
		AddSequential(new DriveTrainDisableGyroCorrectionCommand());
		AddSequential(new SwerveModuleRotateToAngleCommand(270, false), .5);
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new GearResetCommand());
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(277.4),false),6);
		AddSequential(new RotateToAngleGyroCommand(-120));
	}
};

#endif  // BLUEGearToRedLaunchPadCommandGroup_H
