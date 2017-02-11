/*
 * ClimberOn.h
 *
 *  Created on: Feb 3, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_CLIMBERON_H_
#define SRC_COMMANDS_CLIMBERON_H_

class ClimberOn : public CommandBase {
	ClimberOn() : CommandBase("ClimberOn"){
		Requires(CommandBase::m_climber.get());
	}
	void Initialize(){
		m_climber->StartClimbing();
	}
	void Execute(){}
	bool IsFinished(){
		return true;
	}
	void End(){}
	void Interrupted(){
		End();
	}
};

#endif /* SRC_COMMANDS_CLIMBERON_H_ */
