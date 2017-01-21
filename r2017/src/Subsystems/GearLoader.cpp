/*
 * GearLoader.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */
#include "GearLoader.h"

GearLoader::GearLoader(uint32_t gearLoaderID) : Subsystem("GearLoader") {
	m_gearLoaderMotor = new CANTalon(gearLoaderID);
}

GearLoader::~GearLoader() {
	delete m_gearLoaderMotor;
}

void UnloadGear(){

}
