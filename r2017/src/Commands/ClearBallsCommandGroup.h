#ifndef ClearBallsCommandGroup_H
#define ClearBallsCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/GearOpenLidCommand.h"
#include "Commands/GearCloseLidCommand.h"
#include "Commands/IntakeSetPosCommand.h"
#include "Commands/WaitCommand.h"

class ClearBallsCommandGroup : public CommandGroup {
public:
	ClearBallsCommandGroup() : CommandGroup("ClearBallsCommandGroup"){
		CommandGroup::SetInterruptible(false);
		AddSequential(new GearOpenLidCommand());
		AddSequential(new WaitCommand(0.3));
		AddSequential(new GearCloseLidCommand());
		AddSequential(new WaitCommand(0.3));
		AddSequential(new GearOpenLidCommand());
		AddSequential(new WaitCommand(0.3));
		AddSequential(new GearCloseLidCommand());
		AddSequential(new WaitCommand(0.3));
		AddSequential(new GearOpenLidCommand());
		AddSequential(new WaitCommand(0.3));
		AddSequential(new GearCloseLidCommand());
		AddSequential(new WaitCommand(0.3));
		AddSequential(new GearOpenLidCommand());
		AddSequential(new IntakeSetPosCommand(450.0,1.0));
		AddSequential(new WaitCommand(0.3));
		AddSequential(new IntakeSetPosCommand(0.0,1.0));
	}
};

#endif  // ClearBallsCommandGroup_H
