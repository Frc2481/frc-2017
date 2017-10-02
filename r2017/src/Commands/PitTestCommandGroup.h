/*
 * PitTestCommandGroup.h
 *
 *  Created on: Sep 18, 2017
 *      Author: Team2481
 */

#ifndef SRC_COMMANDS_PITTESTCOMMANDGROUP_H_
#define SRC_COMMANDS_PITTESTCOMMANDGROUP_H_

#include "CommandBase.h"

class PitTestCommandGroup : public CommandGroup{
public:
	PitTestCommandGroup() : CommandGroup("PitTestCommandGroup") {
		AddSequential(new ShooterTestCommandGroup());
		AddSequential(new ClimberTestCommandGroup());
	}
};

#endif /* SRC_COMMANDS_PITTESTCOMMANDGROUP_H_ */
