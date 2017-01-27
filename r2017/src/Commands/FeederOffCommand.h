/*
 * FeederOffCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_FEEDEROFFCOMMAND_H_
#define SRC_COMMANDS_FEEDEROFFCOMMAND_H_

class FeederOffCommand : public CommandBase {
	FeederOffCommand() : CommandBase("Feeder Off Command") {
		Requires(m_shooter.get());
	}
	void Initialize() {
		m_shooter->TurnFeederOff();
	}

	void Execute() {

	}

	bool IsFinished() {
		return true;
	}

	void End() {

	}

	void Interrupt() {
		End();
	}
};



#endif /* SRC_COMMANDS_FEEDEROFFCOMMAND_H_ */




#endif /* SRC_COMMANDS_FEEDEROFFCOMMAND_H_ */
