/*
 * ShooterHoodToggleCommand.h
 *
 *  Created on: Feb 11, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SHOOTERHOODTOGGLECOMMAND_H_
#define SRC_COMMANDS_SHOOTERHOODTOGGLECOMMAND_H_

#include "Commands/InstantCommand.h"
#include "utils/RobotChains.h"

class ShooterHoodToggleCommand : public InstantCommand{
public:
	ShooterHoodToggleCommand() : InstantCommand("ShooterHoodToggleCommand"){}

	void Initialize() {
		double triggeredHoodAngle = Preferences::GetInstance()->GetDouble("LOWER_HOOD_ANGLE", 0);
		double untriggeredHoodAngle = Preferences::GetInstance()->GetDouble("RAISED_HOOD_ANGLE", 0);
		if (CommandBase::m_superStructure->IsRaised()){
//			RobotChains::getInstance()->SetBoilerPitchAngle(triggeredHoodAngle);
			CommandBase::m_superStructure->LowerHood();
		} else {
			CommandBase::m_superStructure->RaiseHood();
//			RobotChains::getInstance()->SetBoilerPitchAngle(untriggeredHoodAngle);
		}
	}
};

#endif /* SRC_COMMANDS_SHOOTERHOODTOGGLECOMMAND_H_ */
