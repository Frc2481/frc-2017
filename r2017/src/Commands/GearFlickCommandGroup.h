#ifndef SRC_COMMANDS_GEARFLICKCOMMANDGROUP_H_
#define SRC_COMMANDS_GEARFLICKCOMMANDGROUP_H_

#include "Commands/CommandGroup.h"
#include "RobotParameters.h"
#include "Commands/GearFlickCommand.h"
#include "Commands/GearResetCommand.h"

class GearFlickCommandGroup : public CommandGroup {
public:
	GearFlickCommandGroup() : CommandGroup("GearFlickCommandGroup") {
		AddSequential(new GearFlickCommand());
		AddSequential(new WaitCommand(GEAR_FLICK_DELAY));
		AddSequential(new GearResetCommand());
	}
};

#endif
