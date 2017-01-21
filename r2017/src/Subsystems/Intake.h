/*
 * Intake.h
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_SUBSYSTEMS_INTAKE_H_
#define SRC_SUBSYSTEMS_INTAKE_H_

#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "CANTalon.h"

class Intake : public Subsystem {
private:
	CANTalon *m_intakeMotor;

public:
	Intake(uint32_t intakeID);
	~Intake();
	void Consume();
	void Vomit();
	void Stop();
};



#endif /* SRC_SUBSYSTEMS_INTAKE_H_ */
