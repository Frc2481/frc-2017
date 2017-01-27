/*
 * HopperOffCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_HOPPEROFFCOMMAND_H_
#define SRC_COMMANDS_HOPPEROFFCOMMAND_H_

class HopperOffCommand : public CommandBase {
public:
	HopperOffCommand() : CommandBase("Hopper Off Command"){
		Requires(m_hopper.get());
	}

	void Initialize() {
		m_hopper->StopFeeding();
	}

	void Executive() {

	}

	bool IsFinished() {
		return true;
	}

	void End() {

	}

	void Interrupted(){
		End();
	}
};

#endif /* SRC_COMMANDS_HOPPEROFFCOMMAND_H_ */
