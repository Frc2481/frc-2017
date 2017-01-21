/*
 * Intake.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */
#include "Intake.h"

Intake::Intake(uint32_t intakeID) : Subsystem("Intake") {
	m_intakeMotor = new CANTalon(intakeID);
}

Intake::~Intake(){
	delete m_intakeMotor;
}

void Consume(){

}

void Vomit(){

}

void Stop(){

}
