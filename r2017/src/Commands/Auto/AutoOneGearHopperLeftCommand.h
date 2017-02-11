/*
 * AutoOneGearHopperLeftCommand.h
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_AUTO_AUTOONEGEARHOPPERLEFTCOMMAND_H_
#define SRC_COMMANDS_AUTO_AUTOONEGEARHOPPERLEFTCOMMAND_H_

#include "Commands/CommandGroup.h"

class AutoOneGearLeftCommand : public CommandGroup {
	AutoOneGearLeftCommand() : CommandGroup("AutoOneGearLeftCommand") {
		AddSequential(new AutoDriveGearLeftCommand());
		AddSequential(new GearFlickCommand());
		AddSequential(new AutoBackUpFromGearsCommand());
		AddSequential(new AutoLeftHopperFromLeftGearCommand(), 5);
		AddSequential(new WaitCommand(2));
		AddSequential(new AutoBackUpFromHopperCommand());
	}
};

#endif /* SRC_COMMANDS_AUTO_AUTOONEGEARHOPPERLEFTCOMMAND_H_ */
