#ifndef TimeSteerMotorAccelAndDecelCommandGroup_H
#define TimeSteerMotorAccelAndDecelCommandGroup_H

#include <Commands/CommandGroup.h>
#include "TimeSteerMotorAccelerationCommand.h"
#include "TimeSteerMotorDecelCommand.h"

class TimeSteerMotorAccelAndDecelCommandGroup : public CommandGroup {
public:
	TimeSteerMotorAccelAndDecelCommandGroup() : CommandGroup("TimeSteerMotorAccelAndDecelCommandGroup"){
		AddSequential(new TimeSteerMotorAccelerationCommand());
		AddSequential(new TimeSteerMotorDecelCommand());
	}
};

#endif  // TimeSteerMotorAccelAndDecelCommandGroup_H
