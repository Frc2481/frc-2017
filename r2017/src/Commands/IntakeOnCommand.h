/*
 * IntakeOnCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_INTAKEONCOMMAND_H_
#define SRC_COMMANDS_INTAKEONCOMMAND_H_

class IntakeOnCommand : public CommandBase {
public:
	IntakeOnCommand() : CommandBase("Intake On Command"){
		Requires(m_intake.get());
	}

	void Initialize() {
		m_intake->TurnIntakeOn();
	}

	void Execute() {

	}

	bool IsFinished() {
		return true;
	}

	void End() {

	}

	void Interrupted() {
		End();
	}
};



#endif /* SRC_COMMANDS_INTAKEONCOMMAND_H_ */
