#ifndef BLUEFortyBeforeCIR_H
#define BLUEFortyBeforeCIR_H

#include <Commands/CommandGroup.h>
#include "Commands/ToggleCoastToBrakeCommand.h"
#include "Commands/DriveMotionMagicDistanceCommand.h"
#include "Commands/DriveTrainZeroYawCommand.h"
#include "Commands/SetAngleOptimizedCommand.h"
#include "Commands/SwerveModuleRotateToAngleCommand.h"
#include "Commands/WaitCommand.h"
#include "Commands/TurnShooterOnCommand.h"
#include "Commands/LoaderOnCommand.h"
#include "Commands/HopperOnCommand.h"
#include "Commands/ShooterSetHoodCommand.h"
#include "Commands/DriveTrainSetAccelCommand.h"
#include "Commands/PauseCommand.h"
#include "Commands/DriveTrainWaitForEncoderDistanceCommand.h"
#include "Commands/GearCloseLidCommand.h"
#include "Commands/ShooterRampSpeedCommand.h"
#include "Commands/FireBallsAtSpeedCommand.h"
#include "Commands/SetClosedLoopErrorCommand.h"
#include "Commands/SetShooterSpeedCommand.h"

class BLUEFortyBeforeCIR : public CommandGroup {
public:
	BLUEFortyBeforeCIR() : CommandGroup("BLUEFortyBeforeCIR"){
		AddSequential(new ToggleCoastToBrakeCommand(false));
		AddSequential(new DriveTrainZeroYawCommand());
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new SetClosedLoopErrorCommand());
		AddSequential(new GearCloseLidCommand());
		AddSequential(new ShooterSetHoodCommand(true));
		AddSequential(new SetShooterSpeedCommand(Preferences::GetInstance()->GetDouble("BLUE_AUTO_SHOOTER_SPD", 4100))); //4100
		AddSequential(new TurnShooterOnCommand());
		//AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new SetAngleOptimizedCommand(false));
		//AddSequential(new SwerveModuleRotateToAngleCommand(-17,false), .6);
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddParallel(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(
				Preferences::GetInstance()->GetDouble("BLUE_AUTO_DRIVE_DIST", 100)), false), 3); //100
		AddSequential(new DriveTrainWaitForEncoderDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(
				Preferences::GetInstance()->GetDouble("BLUE_AUTO_TURN_POS", 72))), 5); //72
		AddSequential(new SwerveModuleRotateToAngleCommand(270,false), .6);
		AddSequential(new DriveTrainDisableGyroCorrectionCommand());
		AddSequential(new SetAngleOptimizedCommand(true));
		AddSequential(new FireBallsAtSpeedCommand());
	}
};

#endif  // BLUEFortyBeforeCIR_H
