/*
 * ShooterOnCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SHOOTERONCOMMAND_H_
#define SRC_COMMANDS_SHOOTERONCOMMAND_H_

class ShooterOnCommand : public CommandBase {
public:
	ShooterOnCommand() : CommandBase("Shooter On Command") {
		Requires(m_shooter.get());
	}

	void Initialize() {
		m_shooter->TurnShooterOn();
	}

	void Execute() {

	}

	bool IsFinished() {
		return true;
	}

	void End() {

	}

	void Inerrupted() {
		End();
	}
};



#endif /* SRC_COMMANDS_SHOOTERONCOMMAND_H_ */
