#ifndef PlaceGearOnPegCommandGroup_H
#define PlaceGearOnPegCommandGroup_H

#include <Commands/CommandGroup.h>
#include "IntakeSetPosCommand.h"
#include "Commands/PlaceGearOnPegCommand.h"

class PlaceGearOnPegCommandGroup : public CommandGroup {
public:
	PlaceGearOnPegCommandGroup() : CommandGroup("PlaceGearOnPegCommandGroup"){
		AddSequential(new IntakeSetPosCommand(700.0,0.5));
		AddSequential(new PlaceGearOnPegCommand());
	}
};

#endif  // PlaceGearOnPegCommandGroup_H
