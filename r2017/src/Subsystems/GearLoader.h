/*
 * GearLoader.h
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_SUBSYSTEMS_GEARLOADER_H_
#define SRC_SUBSYSTEMS_GEARLOADER_H_

#include "Solenoid.h"
#include "Commands/Subsystem.h"
#include "CANTalon.h"

class GearLoader : public Subsystem {
private:
	Solenoid *m_gearLoader;

public:
GearLoader();
~GearLoader();
void LoadGear();
void ResetGear();
bool IsUnloaded();
};



#endif /* SRC_SUBSYSTEMS_GEARLOADER_H_ */
