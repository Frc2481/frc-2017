/*
 * AutoDriveHopperCommand.h
 *
 *  Created on: Jan 28, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_AUTODRIVEHOPPERCOMMAND_H_
#define SRC_COMMANDS_AUTODRIVEHOPPERCOMMAND_H_

#include "WPILib.h"

class AutoLeftHopperFromLeftGearCommand : public DriveTrainFollowPathCommand {
	AutoLeftHopperFromLeftGearCommand() : DriveTrainFollowPathCommand("AutoLeftHopperFromLeftGearCommand") {}
	void Initialize(){
		GeneratePath(m_path, 2);
		DriverStation::Alliance color = DriverStation::GetInstance().GetAlliance()
		if(color == DriverStation::Alliance::kRed){
			Waypoint initial = {0, 0, 0};
			Waypoint final = {1000, 1000, 0}; //TUNE THIS
			Waypoint path[2] = {initial, final};
			GeneratePath(path, 2);
		}
		else if(color == DriverStation::Alliance::kBlue){
			Waypoint initial = {0, 0, 0};
			Waypoint final = {1000, 1000, 0}; //TUNE THIS
			Waypoint path[2] = {initial, final};
			GeneratePath(path, 2);
		}
		else {
			Waypoint initial = {0, 0, 0};
			Waypoint final = {0, 150, 0}; //TUNE THIS
			Waypoint path[2] = {initial, final};
			GeneratePath(path, 2);
		}
	}
};

class AutoRightHopperFromRightGearCommand : public DriveTrainFollowPathCommand {
	Waypoint m_initial = {0, 0, 0};
	Waypoint m_final = {1000, 1000, 0}; //TUNE THIS
	Waypoint m_path[2] = {m_initial, m_final};
	AutoRightHopperFromRightGearCommand() : DriveTrainFollowPathCommand("AutoRightHopperFromRightGearCommand") {}
	void Initialize(){
			GeneratePath(m_path, 2);
			DriverStation::Alliance color = DriverStation::GetInstance().GetAlliance()
			if(color == DriverStation::Alliance::kRed){
				Waypoint initial = {0, 0, 0};
				Waypoint final = {1000, 1000, 0}; //TUNE THIS
				Waypoint path[2] = {initial, final};
				GeneratePath(path, 2);
			}
			else if(color == DriverStation::Alliance::kBlue){
				Waypoint initial = {0, 0, 0};
				Waypoint final = {1000, 1000, 0}; //TUNE THIS
				Waypoint path[2] = {initial, final};
				GeneratePath(path, 2);
			}
			else {
				Waypoint initial = {0, 0, 0};
				Waypoint final = {0, 150, 0}; //TUNE THIS
				Waypoint path[2] = {initial, final};
				GeneratePath(path, 2);
		  } 
};

#endif /* SRC_COMMANDS_AUTODRIVEHOPPERCOMMAND_H_ */
