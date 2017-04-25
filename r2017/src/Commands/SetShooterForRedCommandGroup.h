#ifndef SetShooterForRedCommandGroup_H
#define SetShooterForRedCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/ShooterSetHoodCommand.h"
#include "Commands/SetShooterSpeedCommand.h"
#include "Preferences.h"

class SetShooterForRedCommandGroup : public CommandGroup {
public:
	SetShooterForRedCommandGroup() : CommandGroup("SetShooterForRedCommandGroup"){
		AddSequential(new ShooterSetHoodCommand(false));
		AddSequential(new SetShooterSpeedCommand(Preferences::GetInstance()->GetDouble("RED_AUTO_SHOOTER_SPD", 4275)));
	}
};

#endif  // SetShooterForRedCommandGroup_H
