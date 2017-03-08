/*
 * BirdEyeDelayedSetupCommandGroup.h
 *
 *  Created on: Feb 20, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_BIRDEYEDELAYEDSETUPCOMMANDGROUP_H_
#define SRC_COMMANDS_BIRDEYEDELAYEDSETUPCOMMANDGROUP_H_

#include "Commands/CommandGroup.h"
#include "Commands/SendSerialCharCommand.h"

class  BirdEyeDelayedSetupCommandGroup: public CommandGroup {

public:
	BirdEyeDelayedSetupCommandGroup() : CommandGroup("BirdEyeDelayedSetupCommandgroup"){
		SetRunWhenDisabled(true);
		AddSequential(new WaitCommand(20));
		AddSequential(new SendSerialCharCommand('p'));
		AddSequential(new WaitCommand(12));
		AddSequential(new SendSerialCharCommand('r'));
		AddSequential(new SendSerialCharCommand('m'));

	}

};


#endif /* SRC_COMMANDS_BIRDEYEDELAYEDSETUPCOMMANDGROUP_H_ */
