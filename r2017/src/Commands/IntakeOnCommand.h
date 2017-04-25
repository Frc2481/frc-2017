/*
 * IntakeOnCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_INTAKEONCOMMAND_H_
#define SRC_COMMANDS_INTAKEONCOMMAND_H_

#include "Commands/InstantCommand.h"

class IntakeOnCommand : public CommandBase {
	double m_speed;
public:
	IntakeOnCommand(double speed = -1, double waitTime = 1.0) : CommandBase("IntakeOnCommand"){
		Requires(m_gearIntakeRoller.get());
		m_speed = speed;
		SetTimeout(waitTime);
	}

	void Initialize() {
		m_gearIntakeRoller->IntakeGear(m_speed);
	}

	bool IsFinished(){
		return IsTimedOut();
	}

	void End(){
//		printf("IntakeOn StopIntake\n");
		m_gearIntakeRoller->StopIntake();
	}
	void Interrupted(){
//		printf("Interrupted\n");
		End();
	}
};

#endif /* SRC_COMMANDS_INTAKEONCOMMAND_H_ */
