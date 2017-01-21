/*
 * Climber.h
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_SUBSYSTEMS_CLIMBER_H_
#define SRC_SUBSYSTEMS_CLIMBER_H_

#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "CANTalon.h"

class Climber : public Subsystem {
private:
	CANTalon *m_climberMotor;

public:
Climber(uint32_t climberID);
~Climber();
void StartClimbing();
void StopClimbing();
};


#endif /* SRC_SUBSYSTEMS_CLIMBER_H_ */
