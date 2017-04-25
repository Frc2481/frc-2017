#ifndef PickUpGearUninterruptibleCommandGroup_H
#define PickUpGearUninterruptibleCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/IntakeOnCommand.h"
#include "Commands/IntakeSetPosCommand.h"
#include "Commands/WaitCommand.h"

class PickUpGearUninterruptibleCommandGroup : public CommandGroup {
public:
	PickUpGearUninterruptibleCommandGroup() : CommandGroup("PickUpGearUninterruptedCommandGroup"){
		CommandGroup::SetInterruptible(false);
		AddSequential(new IntakeSetPosCommand(200.0, 1));
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeOnCommand(-1.0, 0.5));
	}
};

#endif  // PickUpGearUninterruptibleCommandGroup_H
