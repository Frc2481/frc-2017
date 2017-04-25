#ifndef SetShooterForBlueCommandGroup_H
#define SetShooterForBlueCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/ShooterSetHoodCommand.h"
#include "Commands/SetShooterSpeedCommand.h"
#include "Preferences.h"

class SetShooterForBlueCommandGroup : public CommandGroup {
public:
	SetShooterForBlueCommandGroup() : CommandGroup("SetShooterForBlueCommandGroup"){
		AddSequential(new ShooterSetHoodCommand(true));
		AddSequential(new SetShooterSpeedCommand(Preferences::GetInstance()->GetDouble("BLUE_AUTO_SHOOTER_SPD", 4100)));
	}
};

#endif  // SetShooterForBlueCommandGroup_H
