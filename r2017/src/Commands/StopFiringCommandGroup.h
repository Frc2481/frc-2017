#ifndef StopFiringCommandGroup_H
#define StopFiringCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/ShooterOffCommand.h"
#include "Commands/LoaderOffCommand.h"
#include "Commands/HopperOffCommand.h"

class StopFiringCommandGroup : public CommandGroup {
public:
	StopFiringCommandGroup() : CommandGroup("StopFiringCommandGroup"){
		AddSequential(new HopperOffCommand());
		AddSequential(new LoaderOffCommand());
	}
};

#endif  // StopFiringCommandGroup_H
