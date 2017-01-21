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

public:
	Hopper(uint32_t hopperID, uint32_t liftID);
	~Hopper();
	void StartFeeding();
	void StopFeeding();
};



#endif /* SRC_SUBSYSTEMS_HOPPER_H_ */
