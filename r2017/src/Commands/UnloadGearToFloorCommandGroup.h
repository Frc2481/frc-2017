#ifndef UnloadGearToFloorCommandGroup_H
#define UnloadGearToFloorCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/IntakeOutCommand.h"
#include "Commands/IntakeSetPosCommand.h"
#include "Commands/WaitForPivotPositionCommand.h"
#include "Commands/UnlockGearIntakeCommand.h"

class UnloadGearToFloorCommandGroup : public CommandGroup {
public:
	UnloadGearToFloorCommandGroup() : CommandGroup("UnloadGearToFloorCommandGroup"){
		AddSequential(new UnlockGearIntakeCommand());
		AddParallel(new IntakeSetPosCommand(1325.0, 1.5));
		AddSequential(new WaitForPivotPositionCommand(450.0));
		AddSequential(new IntakeOutCommand(0.1));
		AddSequential(new WaitForPivotPositionCommand(1000.0));
		AddSequential(new IntakeOutCommand(0.5));
	}
};

#endif  // UnloadGearToFloorCommandGroup_H
