#ifndef OneGearTenBallAuto_H
#define OneGearTenBallAuto_H

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
#include "Commands/DriveTrainWaitForHeadingCommand.h"

class OneGearTenBallAuto : public CommandGroup {
public:
	OneGearTenBallAuto() : CommandGroup("OneGearTenBallAutoCommandGroup"){
		AddSequential(new SetAngleOptimizedCommand(false));
		AddSequential(new ToggleCoastToBrakeCommand(false));
		AddSequential(new DriveTrainZeroYawCommand());
		AddSequential(new TurnShooterOnCommand());

		AddSequential(new SwerveModuleRotateToAngleCommand(270, false));
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(10), false), 2);
		AddSequential(new SetAngleOptimizedCommand(true));
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(-23.5));
		AddSequential(new DriveTrainWaitForHeadingCommand(-23.5), 1.25);
		AddSequential(new SetAngleOptimizedCommand(false));

		AddSequential(new LoaderOnCommand());
		AddSequential(new HopperOnCommand());
		AddSequential(new WaitCommand(3));
		AddSequential(new ShooterOffCommand());
		AddSequential(new LoaderOffCommand());
		AddSequential(new HopperOffCommand());

//		AddSequential(new SetAngleOptimizedCommand(true));
//		AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
//		AddSequential(new DriveTrainWaitForHeadingCommand(0), 3);
//		AddSequential(new SetAngleOptimizedCommand(false));
//
//		AddSequential(new SwerveModuleRotateToAngleCommand(270, false));
//		AddSequential(new WaitCommand(.1));
//		AddSequential(new DriveTrainZeroDriveEncodersCommand());
//		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(6), false),2);

		AddSequential(new SetAngleOptimizedCommand(true));
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(-30));
		AddSequential(new DriveTrainWaitForHeadingCommand(-30), 1.25);
		AddSequential(new SetAngleOptimizedCommand(false));
		AddSequential(new PauseCommand());

		AddSequential(new SwerveModuleRotateToAngleCommand(270, false));
		AddSequential(new WaitCommand(.2));
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(-30));
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(70), true),3);
		AddSequential(new DriveTrainDisableGyroCorrectionCommand());
		AddSequential(new SwerveModuleRotateToAngleCommand(0,false));
		AddSequential(new WaitCommand(.3));
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(-30));
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(50),false),2);
		AddSequential(new GearFlickCommandGroup());
		AddSequential(new DriveTrainDisableGyroCorrectionCommand());
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(-24),false),2);

		AddSequential(new SetAngleOptimizedCommand(true));
		AddSequential(new ToggleCoastToBrakeCommand(true));
	}
};

#endif  // OneGearTenBallAuto_H
