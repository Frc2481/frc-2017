/*
 * HopperOnCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_HOPPERONCOMMAND_H_
#define SRC_COMMANDS_HOPPERONCOMMAND_H_

#include "CommandBase.h"

class HopperOnCommand : public CommandBase {
public:
	HopperOnCommand() : CommandBase("Hopper On Command"){
		Requires(m_hopper.get());
	}

	void Initialize(){
		m_hopper->StartFeeding();
	}

	void Execute(){

	}

	bool IsFinished(){
		return true;
	}

	void End(){


	}

	void Interrupted(){
		End();
	}
};



#endif /* SRC_COMMANDS_HOPPERONCOMMAND_H_ */
