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

class Shooter : public Subsystem {
private:
	CANTalon *m_shooterMotor;
	CANTalon *m_feederMotor;
	double m_p;
	double m_i;
	double m_d;
	double m_feederSpeed;

public:
	Shooter();
	~Shooter();
	void TurnShooterOn();
	void TurnShooterOff();
	void SetShooterSetpoint(double setpoint);
	void SetPID(double p, double i, double d);
	double GetP();
	double GetI();
	double GetD();
	void TurnFeederOn();
	void TurnFeederOff();
	void SetFeederSpeed(double speed);
	double GetShooterSetpoint();
	double GetFeederSpeed();
};



#endif /* SRC_SUBSYSTEMS_SHOOTER_H_ */
