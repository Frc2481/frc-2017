/*
 * GearLoader.h
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_SUBSYSTEMS_GEARLOADER_H_
#define SRC_SUBSYSTEMS_GEARLOADER_H_

#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "CANTalon.h"

class GearLoader : public Subsystem {
private:
	CANTalon *m_gearLoaderMotor;

public:
GearLoader();
~GearLoader();
void UnloadGear();
};



#endif /* SRC_SUBSYSTEMS_GEARLOADER_H_ */
