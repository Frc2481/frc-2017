/*
 * Hopper.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */
#include "Hopper.h"
#include "RobotMap.h"

Hopper::Hopper() : Subsystem("Hopper") {
	m_hopperMotor = new CANTalon(HOPPER_MOTOR);
	m_liftMotor = new CANTalon(LIFT_MOTOR);
	m_speed = 0.2;
}

Hopper::~Hopper(){
	delete m_hopperMotor;
	delete m_liftMotor;
}

void Hopper::StartFeeding(){
	m_hopperMotor->Set(m_speed);
}

void Hopper::StopFeeding(){
	m_hopperMotor->Set(0);
}

void Hopper::SetSpeed(double speed){
	m_speed = speed;
}

double Hopper::GetSpeed(){
	return m_speed;
}
