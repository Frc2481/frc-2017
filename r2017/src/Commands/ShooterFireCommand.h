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
		if(m_superStructure->IsOnTarget()){
			m_superStructure->TurnLoaderOn();
			m_superStructure->StartFeeding();
		}

		else {
			m_superStructure->TurnLoaderOff();
			m_superStructure->StopFeeding();
		}
	}

	bool IsFinished(){
		return true;
	}
	void End(){
		m_superStructure->TurnLoaderOff();
		m_superStructure->StopFeeding();
	}

	void Interrupted(){
		End();
	}
};



#endif /* SRC_COMMANDS_SHOOTERFIRECOMMAND_H_ */
