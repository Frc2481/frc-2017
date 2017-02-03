/*
 * AutoOneGearHopperRightCommand.h
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_AUTO_AUTOONEGEARHOPPERRIGHTCOMMAND_H_
#define SRC_COMMANDS_AUTO_AUTOONEGEARHOPPERRIGHTCOMMAND_H_

#include "Commands/CommandGroup.h"

class AutoOneGearRightCommand : public CommandGroup {
	AutoOneGearRightCommand() : CommandGroup("AutoOneGearLeftCommand") {
		AddSequential(new AutoDriveGearRightCommand());
		AddSequential(new GearUnloadCommand());
		AddSequential(new AutoBackUpFromGearsCommand());
		AddSequential(new AutoRightHopperFromRightGearCommand(), 5);
		AddSequential(new WaitCommand(2));
		AddSequential(new AutoBackUpFromHopperCommand());
	}
};

#endif /* SRC_COMMANDS_AUTO_AUTOONEGEARHOPPERRIGHTCOMMAND_H_ */
