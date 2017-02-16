/*
 * GearFlicker.h
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_SUBSYSTEMS_GEARFLICKER_H_
#define SRC_SUBSYSTEMS_GEARFLICKER_H_

#include "Solenoid.h"
#include "Commands/Subsystem.h"
#include "CANTalon.h"

class GearFlicker : public Subsystem {
private:
	Solenoid *m_flickerSolenoid;
	Solenoid *m_gearLidSolenoid;

public:
GearFlicker();
~GearFlicker();
void FlickGear();
void ResetGear();
bool IsUnloaded();
void OpenLid();
void CloseLid();
bool IsOpen();
};



#endif /* SRC_SUBSYSTEMS_GEARFLICKER_H_ */
