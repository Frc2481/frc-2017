/*
 * Shooter.h
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_SUBSYSTEMS_SHOOTER_H_
#define SRC_SUBSYSTEMS_SHOOTER_H_

#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "CANTalon.h"
#include "../Components/ContinuousEncoder.h"

class Shooter : public Subsystem {
private:
	CANTalon *m_shooterMotor;
	CANTalon *m_feederMotor;

public:
	Shooter(uint32_t shooterID, uint32_t feederID);
	~Shooter();
	void TurnOn();
	void TurnOff();

};



#endif /* SRC_SUBSYSTEMS_SHOOTER_H_ */
