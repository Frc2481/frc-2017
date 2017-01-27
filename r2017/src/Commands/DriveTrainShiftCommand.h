/*
 * DriveTrainShiftCommand.h
 *
 *  Created on: Jan 24, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_DRIVETRAINSHIFTCOMMAND_H_
#define SRC_COMMANDS_DRIVETRAINSHIFTCOMMAND_H_

#include "CommandBase.h"

class DriveTrainShiftCommand : public CommandBase{
private:
	bool m_shiftUp;
public:
	DriveTrainShiftCommand(bool shiftUp) :
		CommandBase("DriveTrainShiftCommand"), m_shiftUp(shiftUp) {
			Requires(m_driveTrain.get());
	}

	void Initialize() {
		m_driveTrain->Shift(m_shiftUp);
	}
	void Execute(){

	}

	bool IsFinished(){
		return true;
	}

	void End(){
		m_driveTrain->Shift(false);
	}

	void Interrupted(){
		End();
	}
};



#endif /* SRC_COMMANDS_DRIVETRAINSHIFTCOMMAND_H_ */
