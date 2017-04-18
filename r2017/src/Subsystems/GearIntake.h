#ifndef GearIntake_H
#define GearIntake_H

#include <Commands/Subsystem.h>
#include "CANTalon.h"

class GearIntake : public Subsystem {
private:
	CANTalon* m_pivotMotor;
	CANTalon* m_intakeMotor;
	double m_offset;
	double m_setpoint;
public:
	GearIntake();
	void InitDefaultCommand();
	void IntakeGear(double speed);
	void StopIntake();
	void SpitGear();
	double GetIntakeCurrent();
	double GetIntakePower();
	void SetIntakePos(double pos);
	void SetIntakeOpenLoop(double speed);
	void StopIntakePivot();
	double GetPivotSpeed();
	double GetRawPivotPos();
	double GetPivotPos();
	bool PivotOnTarget();
	bool IsEncoderPluggedIn();
	void ZeroEncoderPosition();
	double GetPivotCurrent();
	double GetPivotAppliedThrottle();
};

#endif  // GearIntake_H
