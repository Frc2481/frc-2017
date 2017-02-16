#ifndef TimeAccelAndDecelCommandGroup_H
#define TimeAccelAndDecelCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/TimeAccelerationCommand.h"
#include "Commands/TimeDeaccelerationCommand.h"
#include "Commands/ToggleCoastToBrakeCommand.h"

class TimeAccelAndDecelCommandGroup : public CommandGroup {
public:
	TimeAccelAndDecelCommandGroup() : CommandGroup("TimeAccelAndDecelCommandGroup"){
		AddSequential(new ToggleCoastToBrakeCommand(false));
		AddSequential(new TimeAccelerationCommand());
		AddSequential(new TimeDeaccelerationCommand());
		AddSequential(new ToggleCoastToBrakeCommand(true));
	}
};

#endif  // TimeAccelAndDecelCommandGroup_H
