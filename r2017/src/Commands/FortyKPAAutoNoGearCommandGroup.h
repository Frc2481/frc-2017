#ifndef FortyKPAAutoNoGearCommandGroup_H
#define FortyKPAAutoNoGearCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/ToggleCoastToBrakeCommand.h"
#include "Commands/DriveMotionMagicDistanceCommand.h"
#include "Commands/DriveTrainDisableGyroCorrectionCommand.h"
#include "Commands/DriveTrainEnableGyroCorrectionCommand.h"
#include "Commands/DriveTrainZeroDriveEncodersCommand.h"
#include "Commands/DriveTrainZeroYawCommand.h"
#include "Commands/TurnShooterOnCommand.h"
#include "Commands/SetAngleOptimizedCommand.h"
#include "Commands/SwerveModuleRotateToAngleCommand.h"
#include "Commands/LoaderOnCommand.h"
#include "Commands/WaitCommand.h"
#include "Commands/HopperOnCommand.h"
#include "Commands/ShooterOffCommand.h"

class FortyKPAAutoNoGearCommandGroup : public CommandGroup {
public:
	FortyKPAAutoNoGearCommandGroup() : CommandGroup("FortyKPAAutoNoGearCommandGroup"){
		AddSequential(new ToggleCoastToBrakeCommand(false));
		AddSequential(new DriveTrainZeroYawCommand());
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		//AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new SetAngleOptimizedCommand(false));
		AddSequential(new SwerveModuleRotateToAngleCommand(0,false));
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(-(100-24)), false), 3.0);
		AddSequential(new DriveTrainDisableGyroCorrectionCommand());
		AddSequential(new SwerveModuleRotateToAngleCommand(270,false));
		AddSequential(new TurnShooterOnCommand(4275));
		AddSequential(new WaitCommand(.3));
		//AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations((62)-(6)-(22)),true), 2.5);
		AddSequential(new LoaderOnCommand());
		AddSequential(new WaitCommand(.1));
		AddSequential(new HopperOnCommand());
		AddParallel(new SetAngleOptimizedCommand(true));
		AddSequential(new ToggleCoastToBrakeCommand(true));
		//AddSequential(new ShooterOffCommand());

	}
};

#endif  // FortyKPAAutoNoGearCommandGroup_H
