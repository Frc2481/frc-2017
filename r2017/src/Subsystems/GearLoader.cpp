/*
 * GearLoader.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */
#include "GearLoader.h"
#include "RobotMap.h"

GearLoader::GearLoader() : Subsystem("GearLoader") {
	m_gearLoader = new Solenoid(GEAR_LOADER);
}

GearLoader::~GearLoader() {
	delete m_gearLoader;
}

void GearLoader::LoadGear(){
	m_gearLoader->Set(true);
}

void GearLoader::ResetGear(){
	m_gearLoader->Set(false);
}

bool GearLoader::IsUnloaded(){
	return m_gearLoader->Get();
}
