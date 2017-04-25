#ifndef HomeGearIntakeCommandGroup_H
#define HomeGearIntakeCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/IntakeSetPosCommand.h"
#include "Commands/StopGearIntakeCommand.h"
#include "Commands/GearOpenLidCommand.h"

class HomeGearIntakeCommandGroup : public CommandGroup {
public:
	HomeGearIntakeCommandGroup(){
		AddSequential(new IntakeSetPosCommand(0.0,1.5));
		AddSequential(new StopGearIntakeCommand());
		AddSequential(new GearOpenLidCommand());
	}
};

#endif  // HomeGearIntakeCommandGroup_H
