/*
 * Hopper.h
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_SUBSYSTEMS_HOPPER_H_
#define SRC_SUBSYSTEMS_HOPPER_H_

#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "CANTalon.h"

class Hopper : public Subsystem {
private:
	CANTalon *m_hopperMotor;
	CANTalon *m_liftMotor;
	double m_speed;

public:
	Hopper();
	~Hopper();
	void StartFeeding();
	void StopFeeding();
	void SetSpeed(double speed);
	double GetSpeed();
};



#endif /* SRC_SUBSYSTEMS_HOPPER_H_ */
