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
	Solenoid *m_hoodSolenoid;
	Solenoid *m_hoodSolenoid2;
	double m_loaderSpeed;
	int m_onTargetCounter;
	double m_speed;
	double m_shooterSpeed;
	bool m_hoodRaised;

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
	void ReverseHopper();
	void SetSpeed(double speed);
	double GetSpeed();
	void RaiseHood();
	void LowerHood();
	bool IsRaised();
	void SetShooterSpeed(double speed);
	void SetShooterSpeedOpenLoop(double speed);
	void SetShooterControlMode(CANTalon::ControlMode mode);
	double GetHopperCurrent();
	void IncShooterSpeed();
	void DecShooterSpeed();
};

#endif /* SRC_SUBSYSTEMS_SUPERSTRUCTURE_H_ */
