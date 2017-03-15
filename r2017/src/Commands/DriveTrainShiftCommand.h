/*
 * DriveTrainShiftCommand.h
 *
 *  Created on: Jan 24, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_DRIVETRAINSHIFTCOMMAND_H_
#define SRC_COMMANDS_DRIVETRAINSHIFTCOMMAND_H_

#include "CommandBase.h"
#include "Commands/InstantCommand.h"

class DriveTrainShiftCommand : public InstantCommand{
private:
	bool m_shiftUp;
public:
	DriveTrainShiftCommand(bool shiftUp) :
		InstantCommand("DriveTrainShiftCommand"), m_shiftUp(shiftUp) {
			//Requires(CommandBase::m_driveTrain.get());
	}

	void Initialize() {
		CommandBase::m_driveTrain->Shift(m_shiftUp);
	}
};



#endif /* SRC_COMMANDS_DRIVETRAINSHIFTCOMMAND_H_ */
