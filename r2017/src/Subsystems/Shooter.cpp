/*
 * Shooter.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */
#include "Shooter.h"
#include "RobotMap.h"

Shooter::Shooter() : Subsystem("Shooter"){
	m_shooterMotor = new CANTalon(SHOOTER_MOTOR);
	m_feederMotor = new CANTalon(FEEDER_MOTOR);
	m_shooterMotor->SelectProfileSlot(0);
	m_shooterMotor->SetControlMode(CANTalon::kSpeed);
	m_shooterMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	m_shooterMotor->SetSensorDirection(true);
	m_feederSpeed = 0;
}

Shooter::~Shooter(){
	delete m_shooterMotor;
	delete m_feederMotor;
}

void Shooter::TurnShooterOn(){
	m_shooterMotor->Enable();
}

void Shooter::TurnShooterOff(){
	m_shooterMotor->Disable();
}

void Shooter::SetShooterSetpoint(double setpoint) {
	m_shooterMotor->SetSetpoint(setpoint);
}

void Shooter::SetPID(double p, double i, double d) {
	m_p = p;
	m_i = i;
	m_d = d;
	m_shooterMotor->SetPID(m_p, m_i, m_d);
}

double Shooter::GetP() {
	return m_p;
}

double Shooter::GetI() {
	return m_i;
}

double Shooter::GetD() {
	return m_d;
}

double Shooter::GetShooterSetpoint() {
	return m_shooterMotor->GetSetpoint();
}

double Shooter::GetFeederSpeed() {
	return m_feederMotor->Get();
}

void Shooter::TurnFeederOn() {
	m_feederMotor->Set(m_feederSpeed);
}

void Shooter::TurnFeederOff() {
	m_feederMotor->Set(0);
}

void Shooter::SetFeederSpeed(double speed) {
	m_feederSpeed = speed;
}

