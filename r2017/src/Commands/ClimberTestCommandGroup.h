/*
 * ClimberTestCommandGroup.h
 *
 *  Created on: Sep 18, 2017
 *      Author: Team2481
 */

#ifndef SRC_COMMANDS_CLIMBERTESTCOMMANDGROUP_H_
#define SRC_COMMANDS_CLIMBERTESTCOMMANDGROUP_H_

#include "WPILib.h"
#include "ClimberUpCommand.h"
#include "ClimberCheckCommand.h"
#include "ClimberStopCommand.h"

class ClimberTestCommandGroup : public CommandGroup{
public:
	ClimberTestCommandGroup() : CommandGroup("ClimberTestCommandGroup") {
		AddParallel(new ClimberUpCommand());
		AddSequential(new WaitCommand(1));
		AddSequential(new ClimberCheckCommand());
		AddSequential(new ClimberStopCommand());
	}
};

#endif /* SRC_COMMANDS_CLIMBERTESTCOMMANDGROUP_H_ */
