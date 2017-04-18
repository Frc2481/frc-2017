#ifndef PickUpGearCommandGroup_H
#define PickUpGearCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/IntakeOnCommand.h"
#include "Commands/IntakeSetPosCommand.h"
#include "Commands/PickUpGearUninterruptibleCommandGroup.h"
#include "Commands/WaitCommand.h"

class PickUpGearCommandGroup : public CommandGroup {
public:
	PickUpGearCommandGroup() : CommandGroup("PickUpGearCommandGroup"){
		AddSequential(new IntakeSetPosCommand(1500.0, 2.5));
		AddSequential(new IntakeOnCommand());
		AddSequential(new PickUpGearUninterruptibleCommandGroup());
	}
};

#endif  // PickUpGearCommandGroup_H
