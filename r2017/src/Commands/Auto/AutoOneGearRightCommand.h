/*
 * AutoOneGearRightCommand.h
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_AUTO_AUTOONEGEARRIGHTCOMMAND_H_
#define SRC_COMMANDS_AUTO_AUTOONEGEARRIGHTCOMMAND_H_

#include "Commands/CommandGroup.h"

class AutoOneGearRightCommand : public CommandGroup {
	AutoOneGearRightCommand() : CommandGroup("AutoOneGearRightCommand") {
		AddSequential(new AutoDriveGearRightCommand());
		AddSequential(new GearUnloadCommand());
		AddSequential(new AutoBackUpFromGearsCommand());
	}
};

#endif /* SRC_COMMANDS_AUTO_AUTOONEGEARRIGHTCOMMAND_H_ */
