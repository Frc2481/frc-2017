#ifndef REDFortyKPACIRCommandGroup_H
#define REDFortyKPACIRCommandGroup_H

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

class REDFortyKPACIRCommandGroup : public CommandGroup {
public:
	REDFortyKPACIRCommandGroup() : CommandGroup("REDFortyKPACIRCommandGroup"){
		AddSequential(new ToggleCoastToBrakeCommand(false));
		AddSequential(new DriveTrainZeroYawCommand());
		AddSequential(new SetClosedLoopErrorCommand());
		AddSequential(new DriveTrainZeroDriveEncodersCommand());
		AddSequential(new GearCloseLidCommand());
		AddSequential(new ShooterSetHoodCommand(false));
		AddSequential(new SetShooterSpeedCommand(4275));
		AddSequential(new TurnShooterOnCommand());
		//AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new SetAngleOptimizedCommand(false));
		AddSequential(new SwerveModuleRotateToAngleCommand(-163,false), .6);
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddParallel(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(110), false), 3);
		AddSequential(new DriveTrainWaitForEncoderDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(70)), 3);
		AddSequential(new SwerveModuleRotateToAngleCommand(270,false), .6);
		AddSequential(new DriveTrainDisableGyroCorrectionCommand());
		AddSequential(new SetAngleOptimizedCommand(true));
		AddSequential(new FireBallsAtSpeedCommand());
	}
};

#endif  // REDFortyKPACIRCommandGroup_H
