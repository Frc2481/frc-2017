/*
 * FeederOnCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_FEEDERONCOMMAND_H_
#define SRC_COMMANDS_FEEDERONCOMMAND_H_

class FeederOnCommand : public CommandBase {
	FeederOnCommand() : CommandBase("Feeder On Command") {
		Requires(m_shooter.get());
	}
	void Initialize() {
		m_shooter->TurnFeederOn();
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



#endif /* SRC_COMMANDS_FEEDERONCOMMAND_H_ */
