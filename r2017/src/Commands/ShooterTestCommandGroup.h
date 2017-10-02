/*
 * ShooterTestCommandGroup.h
 *
 *  Created on: Sep 18, 2017
 *      Author: Team2481
 */

#ifndef SRC_COMMANDS_SHOOTERTESTCOMMANDGROUP_H_
#define SRC_COMMANDS_SHOOTERTESTCOMMANDGROUP_H_

#include "ShooterOnCommand.h"
#include "WPILib.h"
#include "ShooterCheckCommand.h"
#include "ShooterOffCommand.h"

class ShooterTestCommandGroup : public CommandGroup {
public:
	ShooterTestCommandGroup() : CommandGroup("ShooterTestCommandGroup") {
		AddParallel(new ShooterOnCommand());
		AddSequential(new WaitCommand(2));
		AddSequential(new ShooterCheckCommand());
		AddSequential(new ShooterOffCommand());
	}
};

#endif /* SRC_COMMANDS_SHOOTERTESTCOMMANDGROUP_H_ */
