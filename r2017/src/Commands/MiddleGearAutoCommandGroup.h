#ifndef MiddleGearAutoCommandGroup_H
#define MiddleGearAutoCommandGroup_H

#include "../CommandBase.h"
#include "Commands/ToggleCoastToBrakeCommand.h"
#include "Commands/DriveMotionMagicDistanceCommand.h"
#include "Commands/DriveTrainEnableGyroCorrectionCommand.h"
#include "Commands/DriveTrainDisableGyroCorrectionCommand.h"
#include "Commands/DriveTrainZeroYawCommand.h"
#include "Commands/SetAngleOptimizedCommand.h"
#include "Commands/SetDriveTalonToSlaveCommand.h"
#include "Commands/GearFlickCommandGroup.h"
#include "Commands/SwerveModuleRotateToAngleCommand.h"
#include "Commands/PauseCommand.h"

class MiddleGearAutoCommandGroup : public CommandGroup {
public:
	MiddleGearAutoCommandGroup() : CommandGroup("MiddleGearAutoCommandGroup"){
		AddSequential(new ToggleCoastToBrakeCommand(false));
		AddSequential(new DriveTrainZeroYawCommand());
		AddSequential(new SetAngleOptimizedCommand(false));
		AddSequential(new DriveTrainEnableGyroCorrectionCommand(0));
		AddSequential(new PauseCommand());
		AddSequential(new DriveMotionMagicDistanceCommand(CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(71), false), 3);
		AddSequential(new GearFlickCommandGroup());
		AddSequential(new DriveMotionMagicDistanceCommand(-CommandBase::m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(30), false));
		AddSequential(new DriveTrainDisableGyroCorrectionCommand());
		AddSequential(new SetAngleOptimizedCommand(true));
		AddSequential(new ToggleCoastToBrakeCommand(true));
	}
};

#endif  // MiddleGearAutoCommandGroup_H
