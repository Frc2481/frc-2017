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
	double m_wait;
public:
	IntakeOnCommand(double speed = -1, double waitTime = 1.0) : CommandBase("IntakeOnCommand"){
		Requires(m_gearIntake.get());
		m_speed = speed;
		m_wait = waitTime;
	}

	void Initialize() {
		m_gearIntake->IntakeGear(m_speed);
	}

	bool IsFinished(){
		printf("CurrentCondition %d\n", (int)(fabs(m_gearIntake->GetIntakeCurrent()) >= 15.0));
		printf("TimeCondition %d\n", (int)(TimeSinceInitialized() > 1.0));
		return fabs(m_gearIntake->GetIntakeCurrent()) >= 15.0 && TimeSinceInitialized() > m_wait;
	}

	void End(){
		printf("IntakeOn StopIntake\n");
		m_gearIntake->StopIntake();
	}
	void Interrupted(){
		printf("Interrupted\n");
		End();
	}
};

#endif /* SRC_COMMANDS_INTAKEONCOMMAND_H_ */
