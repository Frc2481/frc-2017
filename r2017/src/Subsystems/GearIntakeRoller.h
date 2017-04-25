#ifndef GearIntakeRoller_H
#define GearIntakeRoller_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "CANTalon.h"

class GearIntakeRoller : public Subsystem {
private:
	CANTalon* m_intakeMotor;
public:
	GearIntakeRoller();
	void InitDefaultCommand();
	void IntakeGear(double speed);
	void StopIntake();
	void SpitGear();
	double GetIntakeCurrent();
	double GetIntakePower();
};

#endif  // GearIntakeRoller_H
