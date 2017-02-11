/*
 * ClimberOff.h
 *
 *  Created on: Feb 3, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_CLIMBEROFF_H_
#define SRC_COMMANDS_CLIMBEROFF_H_

class ClimberOff : public CommandBase {
	ClimberOff() : CommandBase("ClimberOff"){
		Requires(CommandBase::m_climber.get());
	}
	void Initialize(){
		m_climber->StopClimbing();
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

#endif /* SRC_COMMANDS_CLIMBEROFF_H_ */
