#ifndef FireBallsCommandGroup_H
#define FireBallsCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/TurnShooterOnCommand.h"
#include "Commands/WaitCommand.h"
#include "Commands/LoaderOnCommand.h"
#include "Commands/HopperOnCommand.h"

class FireBallsCommandGroup : public CommandGroup {
public:
	FireBallsCommandGroup() : CommandGroup("FireBallsCommandGroup"){
		AddSequential(new LoaderOnCommand());
		AddSequential(new HopperOnCommand());
	}
};

#endif  // FireBallsCommandGroup_H
