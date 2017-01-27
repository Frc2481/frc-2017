/*
 * GearLoader.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */
#include "GearLoader.h"
#include "RobotMap.h"

GearLoader::GearLoader() : Subsystem("GearLoader") {
	m_gearLoaderMotor = new CANTalon(GEAR_LOADER_MOTOR);
}

GearLoader::~GearLoader() {
	delete m_gearLoaderMotor;
}

void UnloadGear(){

}
