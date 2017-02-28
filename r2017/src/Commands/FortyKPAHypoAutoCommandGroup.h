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

class FortyKPAHypoAutoCommandGroup : public CommandGroup {
public:
	FortyKPAHypoAutoCommandGroup() : CommandGroup("FortyKPAHypoAutoCommandGroup"){
		AddSequential(new ToggleCoastToBrakeCommand(false));
		AddSequential(new DriveTrainZeroYawCommand());
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		//AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new SetAngleOptimizedCommand(false));
		AddSequential(new SwerveModuleRotateToAngleCommand(18,false));
		AddSequential(new WaitCommand(.2));
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(-(82)), false), 3.0);
		AddSequential(new SwerveModuleRotateToAngleCommand(270,false));
		AddSequential(new WaitCommand(.2));
		AddSequential(new TurnShooterOnCommand());
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(9),true),.5);
		AddSequential(new LoaderOnCommand());
		AddSequential(new WaitCommand(.1));
		AddSequential(new HopperOnCommand());
		AddParallel(new SetAngleOptimizedCommand(true));
		AddSequential(new ToggleCoastToBrakeCommand(true));
	}
};

#endif  // FortyKPAHypoAutoCommandGroup_H
