#ifndef IntakeFromHPAndSetToReadyCommandGroup_H
#define IntakeFromHPAndSetToReadyCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/TurnOnIntakeIfNoGearCommand.h"
#include "Commands/IntakeSetPosCommand.h"
#include "Commands/WaitForGearCommand.h"
#include "Commands/GearCloseLidCommand.h"
#include "Commands/IntakeFromHPCommand.h"
#include "Commands/IntakeOffCommand.h"

class IntakeFromHPAndSetToReadyCommandGroup : public CommandGroup {
public:
	IntakeFromHPAndSetToReadyCommandGroup() : CommandGroup("IntakeFromHPAndSetToReadyCommandGroup"){
		AddSequential(new IntakeFromHPCommand(-1.0));
		AddSequential(new WaitForGearCommand());
		AddSequential(new WaitCommand(0.2));
		AddSequential(new IntakeOffCommand());
		AddSequential(new GearCloseLidCommand());
		AddSequential(new IntakeSetPosCommand(250.0, 2.0));
	}
};

#endif  // IntakeFromHPAndSetToReadyCommandGroup_H
