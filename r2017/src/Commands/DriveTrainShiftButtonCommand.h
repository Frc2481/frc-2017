/*
 * DriveTrainShiftButtonCommand.h
 *
 *  Created on: Jan 26, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_DRIVETRAINSHIFTBUTTONCOMMAND_H_
#define SRC_COMMANDS_DRIVETRAINSHIFTBUTTONCOMMAND_H_

#include "CommandBase.h"
#include "DriveTrainShiftSequenceCommand.h"

class DriveTrainShiftButtonCommand : public CommandBase {
private:
	Command *m_upShiftCommand;
	Command *m_downShiftCommand;

public:
	DriveTrainShiftButtonCommand() : CommandBase("DriveTrainShiftButtonCommand"),
		m_upShiftCommand(new DriveTrainShiftSequenceCommand(true)),
		m_downShiftCommand(new DriveTrainShiftSequenceCommand(true)){
	}

	void Initialize(){
		m_upShiftCommand->Start();
	}

	void Execute(){}

	bool IsFinished(){
		return false;
	}

	void End(){
		m_downShiftCommand->Start();
	}

	void Interrupted(){
		End();
	}
};




#endif /* SRC_COMMANDS_DRIVETRAINSHIFTBUTTONCOMMAND_H_ */
