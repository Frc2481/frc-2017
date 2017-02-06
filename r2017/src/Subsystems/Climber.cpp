/*
 * Climber.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */
#include "Climber.h"
#include "RobotMap.h"

Climber::Climber() : Subsystem("Climber") {
	m_climberMotor = new CANTalon(CLIMBER_MOTOR);
}

Climber::~Climber(){
	delete m_climberMotor;
}

void Climber::StartClimbing() {
	m_climberMotor->Set(1);
}

void Climber::StopClimbing() {
	m_climberMotor->Set(0);
}

