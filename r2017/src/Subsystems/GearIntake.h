#ifndef GearIntake_H
#define GearIntake_H

#include <Commands/Subsystem.h>
#include "DigitalInput.h"
#include "CANTalon.h"

class GearIntake : public Subsystem {
private:
	CANTalon* m_pivotMotor;
	DigitalInput* m_hpBreak;
	DigitalInput* m_intakeBreak;
	double m_offset;
	double m_setpoint;
	bool m_hasGear;
	bool m_lock;
	bool m_hpBeam;
public:
	GearIntake();
	void InitDefaultCommand();
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
	bool IsHPBeamBroken();
	bool GetHasGear();
	double PivotClosedLoopError();
	void LockGearIntake();
	void UnlockGearIntake();
	bool GetGearLock();
	void SetHasGear(bool hasGear);
	void SetHPBeamBroken(bool hpBeam);
	double GetEncoderSpeed();
	double GetAppliedThrottle();
};

#endif  // GearIntake_H
