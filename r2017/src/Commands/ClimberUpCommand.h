/*
 * ClimberUpCommand.h
 *
 *  Created on: Feb 6, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_CLIMBERUPCOMMAND_H_
#define SRC_COMMANDS_CLIMBERUPCOMMAND_H_

#include "../CommandBase.h"

class ClimberUpCommand : public CommandBase{
public:
	ClimberUpCommand(): CommandBase("ClimberUpCommand"){
	}
	virtual ~ClimberUpCommand();

	void Initialize(){
		m_climber->StartClimbing();
	}

	bool IsFinished(){
		return false;
	}

	void End(){
		m_climber->StopClimbing();
	}
};

#endif /* SRC_COMMANDS_CLIMBERUPCOMMAND_H_ */
