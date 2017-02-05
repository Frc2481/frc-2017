/*
 * AutoBackUpFromGearsCommand.h
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_AUTOBACKUPCOMMAND_H_
#define SRC_COMMANDS_AUTOBACKUPCOMMAND_H_

class AutoBackUpFromGearsCommand : public DriveTrainFollowPathCommand {
	Waypoint m_initial = {0, 0, 0};
	Waypoint m_final = {-6, -6, 0}; //TUNE THIS  Inches
	Waypoint m_path[2] = {m_initial, m_final};
	AutoBackUpFromGearsCommand() : DriveTrainFollowPathCommand("AutoBackUpFromGearsCommand") {}
	void Initialize(){
		GeneratePath(m_path, 2);
	}
};

class AutoBackUpFromHopperCommand : public DriveTrainFollowPathCommand {
	Waypoint m_initial = {0, 0, 0};
	Waypoint m_final = {-12, -12, 0}; //TUNE THIS  Inches
	Waypoint m_path[2] = {m_initial, m_final};
	AutoBackUpFromHopperCommand() : DriveTrainFollowPathCommand("AutoBackUpFromHopperCommand") {}
	void Initialize(){
		GeneratePath(m_path, 2);
	}
};

#endif /* SRC_COMMANDS_AUTOBACKUPCOMMAND_H_ */
