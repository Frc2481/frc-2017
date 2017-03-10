#ifndef FortyKPAHypoAutoCommandGroup_H
#define FortyKPAHypoAutoCommandGroup_H

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

class FortyKPAHypoAutoCommandGroup : public CommandGroup {
public:
	FortyKPAHypoAutoCommandGroup() : CommandGroup("FortyKPAHypoAutoCommandGroup"){
		AddSequential(new ToggleCoastToBrakeCommand(false));
		AddSequential(new DriveTrainZeroYawCommand());
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new ShooterSetHoodCommand(false));
		AddSequential(new TurnShooterOnCommand());
		//AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new SetAngleOptimizedCommand(false));
		AddSequential(new SwerveModuleRotateToAngleCommand(17,false), .5);
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(-(84)), false), 3.0);
		AddSequential(new DriveTrainSetAccelCommand(4));
		AddSequential(new SwerveModuleRotateToAngleCommand(270,false), .5);
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(120),true),2.5);
		AddSequential(new LoaderOnCommand());
		AddSequential(new HopperOnCommand());
		AddSequential(new DriveTrainDisableGyroCorrectionCommand());
		AddParallel(new SetAngleOptimizedCommand(true));
		AddSequential(new ToggleCoastToBrakeCommand(true));
	}
};

#endif  // FortyKPAHypoAutoCommandGroup_H
