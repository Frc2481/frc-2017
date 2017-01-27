/*
 * ShooterOffCommand.h
 *
 *  Created off: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SHOOTEROFFCOMMAND_H_
#define SRC_COMMANDS_SHOOTEROFFCOMMAND_H_

class ShooterOffCommand : public CommandBase {
public:
	ShooterOffCommand() : CommandBase("Shooter Off Command") {
		Requires(m_shooter.get());
	}

	void Initialize() {
		m_shooter->TurnShooterOff();
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



#endif /* SRC_COMMANDS_SHOOTEROFFCOMMAND_H_ */
