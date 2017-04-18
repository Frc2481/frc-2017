#ifndef TimeIntakeAccelAndDecelCommandGroup_H
#define TimeIntakeAccelAndDecelCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/TimeIntakeDecelCommand.h"
#include "Commands/TimeIntakeAccelCommand.h"

class TimeIntakeAccelAndDecelCommandGroup : public CommandGroup {
public:
	TimeIntakeAccelAndDecelCommandGroup() : CommandGroup("TimeIntakeAccelAndDecelCommandGroup"){
		AddSequential(new TimeIntakeAccelCommand());
		AddSequential(new TimeIntakeDecelCommand());
	}
};

#endif  // TimeIntakeAccelAndDecelCommandGroup_H
