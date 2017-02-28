#ifndef FollowGearPathCommandGroup_H
#define FollowGearPathCommandGroup_H

#include <Commands/CommandGroup.h>
#include "../CommandBase.h"
#include "Commands/AutoDriveCommand.h"
#include "Commands/SwerveModuleRotateToAngleCommand.h"
#include "Commands/SetDriveTalonToSlaveCommand.h"
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

class FollowGearPathCommandGroup : public CommandGroup {
public:
	FollowGearPathCommandGroup() : CommandGroup("FollowGearPathCommandGroup"){
		AddSequential(new ToggleCoastToBrakeCommand(false));
		AddSequential(new DriveTrainZeroYawCommand());
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new SetAngleOptimizedCommand(false));
		AddSequential(new SwerveModuleRotateToAngleCommand(0,false)); //Change to 0, true for vision processing
		AddSequential(new SetDriveTalonToSlaveCommand(true));
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(110.5-24), false));

		//AddSequential(new GeneratePathToTargetCommand());
		//AddSequential(new WaitCommand(.25));
		AddSequential(new DriveTrainDisableGyroCorrectionCommand());
		//AddSequential(new AutoDriveCommand(0,0,.1,.11));
		AddSequential(new SetDriveTalonToSlaveCommand(true));
		AddSequential(new RotateToAngleGyroCommand(-60), 2);
		//AddSequential(new WaitCommand(.25));
		//AddSequential(new GenerateGearRotationPathCommand(29.5));

		//AddSequential(new AutoDriveCommand(0,0,0,.11));
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new SetDriveTalonToSlaveCommand(true));
		//AddSequential(new DriveTrainEnableGyroCorrectionCommand(-60));
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(30), false), 3.0);
		//AddSequential(new WaitCommand(.5));
		AddSequential(new GearFlickCommand());
		AddSequential(new WaitCommand(1));
		AddSequential(new GearResetCommand());
		//AddSequential(new GearFlickCommandGroup()); //gear on peg

		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(-51.25),false));
		AddSequential(new DriveTrainDisableGyroCorrectionCommand());
		//AddSequential(new AutoDriveCommand(0,0,.1,.5));
		AddSequential(new SetDriveTalonToSlaveCommand(true));
		AddSequential(new RotateToAngleGyroCommand(0), 1.5);
		//AddSequential(new WaitCommand(.25));
		//AddSequential(new GenerateGearRotationPathCommand(-20.4));
		//AddSequential(new AutoDriveCommand(0.1,0,0,.5));
		AddSequential(new SwerveModuleRotateToAngleCommand(270,false));
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new SetDriveTalonToSlaveCommand(true));
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(-180));
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(60.06), true), 5.0);
		AddSequential(new SetAngleOptimizedCommand(true));
		AddSequential(new ToggleCoastToBrakeCommand(true));
	}
};

#endif  // FollowGearPathCommandGroup_H
