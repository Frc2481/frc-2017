/*
 * Shooter&Hopper.h
 *
 *  Created on: Feb 3, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_SUBSYSTEMS_SUPERSTRUCTURE_H_
#define SRC_SUBSYSTEMS_SUPERSTRUCTURE_H_

#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "CANTalon.h"

class SuperStructure : public Subsystem {
private:
	CANTalon *m_shooterMotor;
	CANTalon *m_loaderMotor;
	CANTalon *m_hopperMotor;
	double m_p;
	double m_i;
	double m_d;
	double m_loaderSpeed;
	int m_onTargetCounter;
	double m_speed;

public:
	SuperStructure();
	~SuperStructure();
	void TurnShooterOn();
	void TurnShooterOff();
	void SetShooterSetpoint(double setpoint);
	void SetPID(double p, double i, double d);
	double GetP();
	double GetI();
	double GetD();
	void TurnLoaderOn();
	void TurnLoaderOff();
	void SetLoaderSpeed(double speed);
	double GetShooterSetpoint();
	double GetLoaderSpeed();
	bool IsShooterOn();
	bool IsOnTarget();
	void StartFeeding();
	void StopFeeding();
	void SetSpeed(double speed);
	double GetSpeed();
};

#endif /* SRC_SUBSYSTEMS_SUPERSTRUCTURE_H_ */
