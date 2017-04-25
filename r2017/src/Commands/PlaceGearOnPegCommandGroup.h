#ifndef PlaceGearOnPegCommandGroup_H
#define PlaceGearOnPegCommandGroup_H

#include <Commands/CommandGroup.h>
#include "IntakeSetPosCommand.h"
#include "Commands/PlaceGearOnPegCommand.h"
#include "Commands/WaitForNoGearCommand.h"
#include "Commands/IntakeSetPosCommand.h"
#include "Commands/WaitCommand.h"
#include "Commands/GearOpenLidCommand.h"
#include "Commands/UnlockGearIntakeCommand.h"

class PlaceGearOnPegCommandGroup : public CommandGroup {
public:
	PlaceGearOnPegCommandGroup() : CommandGroup("PlaceGearOnPegCommandGroup"){
		AddSequential(new UnlockGearIntakeCommand());
		AddSequential(new IntakeSetPosCommand(700.0,0.4));
		AddParallel(new PlaceGearOnPegCommand());
		AddSequential(new WaitForNoGearCommand(), 1.0);
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeSetPosCommand(0.0,2.0));
		AddSequential(new GearOpenLidCommand());
	}
};

#endif  // PlaceGearOnPegCommandGroup_H
