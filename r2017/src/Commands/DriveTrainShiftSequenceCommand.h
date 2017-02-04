/*
 * DriveTrainShiftSequenceCommand.h
 *
 *  Created on: Jan 26, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_DRIVETRAINSHIFTSEQUENCECOMMAND_H_
#define SRC_COMMANDS_DRIVETRAINSHIFTSEQUENCECOMMAND_H_

#include "Commands/CommandGroup.h"
#include "Commands/WaitCommand.h"
#include "DriveTrainShiftCommand.h"

using namespace frc;

class DriveTrainShiftSequenceCommand : public CommandGroup {
private:
	static constexpr double kShiftDurationCommand = .05;

public:
	DriveTrainShiftSequenceCommand(bool shiftUp) : CommandGroup("DriveTrainShiftSequenceCommand"){
		AddSequential(new WaitCommand(kShiftDurationCommand));
		AddSequential(new DriveTrainShiftCommand(shiftUp));
		AddSequential(new WaitCommand(kShiftDurationCommand));
	}
};


#endif /* SRC_COMMANDS_DRIVETRAINSHIFTSEQUENCECOMMAND_H_ */
