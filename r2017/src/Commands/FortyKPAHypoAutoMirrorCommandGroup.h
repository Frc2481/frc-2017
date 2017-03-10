#ifndef FortyKPAHypoAutoMirrorCommandGroup_H
#define FortyKPAHypoAutoMirrorCommandGroup_H

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

class FortyKPAHypoAutoMirrorCommandGroup : public CommandGroup {
public:
	FortyKPAHypoAutoMirrorCommandGroup() : CommandGroup("FortyKPAHypoAutoMirrorCommandGroup"){
		AddSequential(new ToggleCoastToBrakeCommand(false));
		AddSequential(new DriveTrainZeroYawCommand());
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new ShooterSetHoodCommand(true));
		AddSequential(new TurnShooterOnCommand());
		//AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new SetAngleOptimizedCommand(false));
		AddSequential(new SwerveModuleRotateToAngleCommand(-17,false), 3);
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(84), false), 3.0);
		AddSequential(new DriveTrainSetAccelCommand(3));
		AddSequential(new DriveTrainDisableGyroCorrectionCommand());
		AddSequential(new SwerveModuleRotateToAngleCommand(270,false), .5);
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(120),true),2.5);
		AddSequential(new LoaderOnCommand());
		AddSequential(new HopperOnCommand());
		AddParallel(new SetAngleOptimizedCommand(true));
		AddSequential(new ToggleCoastToBrakeCommand(true));
	}
};

#endif  // FortyKPAHypoAutoMirrorCommandGroup_H
