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
	m_flickerSolenoid2 = new Solenoid(GEAR_FLICKER_2);
	m_gearLidSolenoid = new Solenoid(GEAR_LID);
	m_gearLidSolenoid2 = new Solenoid(GEAR_LID_2);
	m_ourGearCounter = 0;
	m_theirGearCounter = 0;
}

GearFlicker::~GearFlicker() {
	delete m_flickerSolenoid;
	delete m_gearLidSolenoid;
}

void GearFlicker::FlickGear(){
	m_flickerSolenoid->Set(false);
	m_flickerSolenoid2->Set(true);
}

void GearFlicker::ResetGear(){
	m_flickerSolenoid->Set(true);
	m_flickerSolenoid2->Set(false);
}

bool GearFlicker::IsUnloaded(){
	return m_flickerSolenoid->Get();
}

void GearFlicker::OpenLid() {
	m_gearLidSolenoid->Set(false);
	m_gearLidSolenoid2->Set(true);
}

void GearFlicker::CloseLid() {
	m_gearLidSolenoid->Set(true);
	m_gearLidSolenoid2->Set(false);
}

bool GearFlicker::IsOpen() {
	return m_gearLidSolenoid->Get();
}

void GearFlicker::IncOurGear() {
	m_ourGearCounter++;
}

void GearFlicker::DecOurGear() {
	m_ourGearCounter--;
}

void GearFlicker::IncTheirGear() {
	m_theirGearCounter++;
}

void GearFlicker::DecTheirGear() {
	m_ourGearCounter--;
}
