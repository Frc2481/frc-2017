/*
 * Shooter.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */
#include "Shooter.h"

Shooter::Shooter(uint32_t shooterID, uint32_t feederID) : Subsystem("Shooter"){
	m_shooterMotor = new CANTalon(shooterID);
	m_feederMotor = new CANTalon(feederID);
}

Shooter::~Shooter(){
	delete m_shooterMotor;
	delete m_feederMotor;
}

void TurnOn(){

}

void TurnOff(){

}
