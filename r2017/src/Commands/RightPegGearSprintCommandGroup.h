#ifndef RightPegGearSprintCommandGroup_H
#define RightPegGearSprintCommandGroup_H

#include <Commands/CommandGroup.h>
#include "../CommandBase.h"
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
#include "Commands/RotateToAngleMotionMagicCommandGroup.h"
#include "Commands/PlaceGearOnPegCommandGroup.h"

class RightPegGearSprintCommandGroup : public CommandGroup {
public:
	RightPegGearSprintCommandGroup() : CommandGroup("RightPegGearSprintCommandGroup"){
		AddSequential(new ToggleCoastToBrakeCommand(false));
		AddSequential(new DriveTrainZeroYawCommand());
		AddSequential(new SetAngleOptimizedCommand(false));
		AddSequential(new SwerveModuleRotateToAngleCommand(90, false), .5);
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(87), false), 4);

		AddSequential(new DriveTrainDisableGyroCorrectionCommand());
		AddSequential(new SetAngleOptimizedCommand(true));
		AddSequential(new RotateToAngleMotionMagicCommandGroup(30));
		AddSequential(new SetAngleOptimizedCommand(false));

		AddSequential(new SwerveModuleRotateToAngleCommand(0,false), .5);
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(30));
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(33), false), 2);
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new PlaceGearOnPegCommandGroup());
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(-12),false),2);
		AddSequential(new DriveTrainDisableGyroCorrectionCommand());
		AddSequential(new SetAngleOptimizedCommand(true));
		AddSequential(new RotateToAngleMotionMagicCommandGroup(0));
		AddSequential(new SetAngleOptimizedCommand(false));
		AddSequential(new SwerveModuleRotateToAngleCommand(90, false), .5);
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(277.5),false),6);
		AddSequential(new SetAngleOptimizedCommand(true));
		AddSequential(new RotateToAngleMotionMagicCommandGroup(270));
	}
};

#endif  // RightPegGearSprintCommandGroup_H
