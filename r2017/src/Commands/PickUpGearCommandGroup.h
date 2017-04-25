#ifndef PickUpGearCommandGroup_H
#define PickUpGearCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/IntakeOnCommand.h"
#include "Commands/IntakeSetPosCommand.h"
#include "Commands/PickUpGearUninterruptibleCommandGroup.h"
#include "Commands/TurnOnIntakeIfNoGearCommand.h"
#include "Commands/WaitForPivotPositionCommand.h"
#include "Commands/UnlockGearIntakeCommand.h"
#include "Commands/WaitCommand.h"

class PickUpGearCommandGroup : public CommandGroup {
public:
	PickUpGearCommandGroup() : CommandGroup("PickUpGearCommandGroup"){
		AddSequential(new UnlockGearIntakeCommand());
		AddParallel(new IntakeSetPosCommand(1325.0, 1.5));
		AddSequential(new TurnOnIntakeIfNoGearCommand(-1));
		AddParallel(new IntakeSetPosCommand(250.0, 1.5));
		AddSequential(new WaitForPivotPositionCommand(300.0));
		AddSequential(new IntakeOnCommand(-1.0, 0.25));
	}
};

#endif  // PickUpGearCommandGroup_H
