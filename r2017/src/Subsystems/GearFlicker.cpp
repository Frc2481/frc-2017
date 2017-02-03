/*
 * GearFlicker.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */
#include <Subsystems/GearFlicker.h>
#include "RobotMap.h"

GearFlicker::GearFlicker() : Subsystem("GearFlicker") {
	m_flickerSolenoid = new Solenoid(GEAR_FLICKER);
}

GearFlicker::~GearFlicker() {
	delete m_flickerSolenoid;
}

void GearFlicker::FlickGear(){
	m_flickerSolenoid->Set(true);
}

void GearFlicker::ResetGear(){
	m_flickerSolenoid->Set(false);
}

bool GearFlicker::IsUnloaded(){
	return m_flickerSolenoid->Get();
}
