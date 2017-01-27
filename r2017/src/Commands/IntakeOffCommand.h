/*
 * IntakeOffCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_INTAKEOFFCOMMAND_H_
#define SRC_COMMANDS_INTAKEOFFCOMMAND_H_

class IntakeOffCommand : public CommandBase {
public:
	IntakeOffCommand() : CommandBase("Intake Off Command"){
		Requires(m_intake.get());
	}

	void Initialize() {
		m_intake->TurnIntakeOff();
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



#endif /* SRC_COMMANDS_INTAKEOFFCOMMAND_H_ */
