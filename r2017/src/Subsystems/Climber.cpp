/*
 * Climber.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */
#include "Climber.h"

Climber::Climber(uint32_t climberID) : Subsystem("Climber") {
	m_climberMotor = new CANTalon(climberID);
}

Climber::~Climber(){
	delete m_climberMotor;
}

void Climber::StartClimbing() {

}

void Climber::StopClimbing() {

}

