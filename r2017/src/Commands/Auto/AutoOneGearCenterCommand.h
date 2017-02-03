/*
 * AutoOneGearCenterCommand.h
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_AUTOONEGEARCENTERCOMMAND_H_
#define SRC_COMMANDS_AUTOONEGEARCENTERCOMMAND_H_

#include "Commands/CommandGroup.h"

class AutoOneGearCenterCommand : public CommandGroup {
	AutoOneGearCenterCommand() : CommandGroup("AutoOneGearCenterCommand") {
		AddSequential(new AutoDriveGearCenterCommand());
		AddSequential(new GearUnloadCommand());
		AddSequential(new AutoBackUpFromGearsCommand());
	}
};

#endif /* SRC_COMMANDS_AUTOONEGEARCENTERCOMMAND_H_ */
