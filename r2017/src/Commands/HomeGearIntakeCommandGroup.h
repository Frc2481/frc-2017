#ifndef HomeGearIntakeCommandGroup_H
#define HomeGearIntakeCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/IntakeSetPosCommand.h"
#include "Commands/StopGearIntakeCommand.h"

class HomeGearIntakeCommandGroup : public CommandGroup {
public:
	HomeGearIntakeCommandGroup(){
		AddSequential(new IntakeSetPosCommand(0.0,2.5));
		AddSequential(new StopGearIntakeCommand());
	}
};

#endif  // HomeGearIntakeCommandGroup_H
