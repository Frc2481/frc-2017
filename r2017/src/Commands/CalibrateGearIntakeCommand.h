#ifndef CalibrateGearIntakeCommand_H
#define CalibrateGearIntakeCommand_H

#include "../CommandBase.h"
#include "Commands/InstantCommand.h"

class CalibrateGearIntakeCommand : public InstantCommand {
public:
	CalibrateGearIntakeCommand() : InstantCommand("CalibrateGearIntakeCommand"){
		SetRunWhenDisabled(true);
	}
	void Initialize(){
		double temp = CommandBase::m_gearIntake->GetRawPivotPos();
		PersistedSettings::GetInstance().Set("GEAR_INTAKE_OFFSET", temp);
	}
};

#endif  // CalibrateGearIntakeCommand_H
