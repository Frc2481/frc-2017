/*
 * AutoDriveGearLeftCommand.h
 *
 *  Created on: Jan 28, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_AUTODRIVEGEARCOMMANDS_H_
#define SRC_COMMANDS_AUTODRIVEGEARCOMMANDS_H_

class AutoDriveGearLeftCommand : public DriveTrainFollowPathCommand {
	Waypoint m_initial = {0, 0, 0};
	Waypoint m_final = {1000, 1000, 0}; //TUNE THIS
	Waypoint m_path[2] = {m_initial, m_final};
	AutoDriveGearLeftCommand() : DriveTrainFollowPathCommand("AutoDriveGearLeftCommand") {}
	void Initialize(){
		GeneratePath(m_path, 2);
	}
};

class AutoDriveGearCenterCommand : public DriveTrainFollowPathCommand {
	Waypoint m_initial = {0, 0, 0};
	Waypoint m_final = {1000, 1000, 0}; //TUNE THIS
	Waypoint m_path[2] = {m_initial, m_final};
	AutoDriveGearCenterCommand() : DriveTrainFollowPathCommand("AutoDriveGearCenterCommand") {}
	void Initialize(){
			GeneratePath(m_path, 2);
		}
};

class AutoDriveGearRightCommand : public DriveTrainFollowPathCommand {
	Waypoint m_initial = {0, 0, 0};
	Waypoint m_final = {1000, 1000, 0}; //TUNE THIS
	Waypoint m_path[2] = {m_initial, m_final};
	AutoDriveGearRightCommand() : DriveTrainFollowPathCommand("AutoDriveGearRightCommand") {}
	void Initialize(){
			GeneratePath(m_path, 2);
		}
};


#endif /* SRC_COMMANDS_AUTODRIVEGEARCOMMANDS_H_ */
