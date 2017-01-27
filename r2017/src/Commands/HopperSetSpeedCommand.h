/*
 * HopperSetSpeedCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_HOPPERSETSPEEDCOMMAND_H_
#define SRC_COMMANDS_HOPPERSETSPEEDCOMMAND_H_
#include "CommandBase.h"

class HopperSetSpeedCommand : public CommandBase {
public:
	HopperSetSpeedCommand() : CommandBase("Hopper Set Speed Command") {

	}

	void Initialize(){
		m_hopper->SetSpeed(SmartDashboard::GetNumber("Hopper Speed", 0));
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



#endif /* SRC_COMMANDS_HOPPERSETSPEEDCOMMAND_H_ */
