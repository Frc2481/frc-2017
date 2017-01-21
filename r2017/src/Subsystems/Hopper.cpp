/*
 * Hopper.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */
#include "Hopper.h"

Hopper::Hopper(uint32_t hopperID, uint32_t liftID) : Subsystem("Hopper") {
	m_hopperMotor = new CANTalon(hopperID);
	m_liftMotor = new CANTalon(liftID);
}

Hopper::~Hopper(){
	delete m_hopperMotor;
	delete m_liftMotor;
}

void StartFeeding(){

}

void StopFeeding(){

}

