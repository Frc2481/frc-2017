/*
 * ShooterFireCommand.h
 *
 *  Created on: Feb 2, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SHOOTERFIRECOMMAND_H_
#define SRC_COMMANDS_SHOOTERFIRECOMMAND_H_

class ShooterFireCommand : public CommandBase {
public:
	ShooterFireCommand() : CommandBase("ShooterFireCommand") {

	}

	void Initialize(){}
	void Execute(){
		if(m_shooter->IsOnTarget()){
			m_shooter->TurnFeederOn();
			m_hopper->StartFeeding();
		}

		else {
			m_shooter->TurnFeederOff();
			m_hopper->StopFeeding();
		}
	}

	bool IsFinished(){}
	void End(){
		m_shooter->TurnFeederOff();
		m_hopper->StopFeeding();
	}

	void Interrupted(){
		End();
	}
};



#endif /* SRC_COMMANDS_SHOOTERFIRECOMMAND_H_ */
