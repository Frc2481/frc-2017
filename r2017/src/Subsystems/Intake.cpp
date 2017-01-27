/*
 * Intake.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */
#include "Intake.h"
#include "RobotMap.h"

Intake::Intake() : Subsystem("Intake") {
	m_intakeMotor = new CANTalon(INTAKE_MOTOR);
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
