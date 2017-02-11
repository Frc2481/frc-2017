/*
 * AutoOneGearLeftCommand.h
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_AUTOONEGEARLEFTCOMMAND_H_
#define SRC_COMMANDS_AUTOONEGEARLEFTCOMMAND_H_

#include "Commands/CommandGroup.h"

class AutoOneGearLeftCommand : public CommandGroup {
	AutoOneGearLeftCommand() : CommandGroup("AutoOneGearLeftCommand") {
		AddSequential(new AutoDriveGearLeftCommand());
		AddSequential(new GearFlickCommand());
		AddSequential(new AutoBackUpFromGearsCommand());
	}
};

#endif /* SRC_COMMANDS_AUTOONEGEARLEFTCOMMAND_H_ */
