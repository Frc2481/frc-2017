#ifndef GenerateOptimalPathToLiftCommand_H
#define GenerateOptimalPathToLiftCommand_H

#include <cmath>
#include "../CommandBase.h"
#include "DriveTrainFollowPathCommand.h"
#include "Commands/InstantCommand.h"
#include "AimingParameters.h"
#include "utils/RigidTransform2D.h"
#include "utils/RobotChains.h"

class GenerateOptimalPathToLiftCommand : public DriveTrainFollowPathCommand {
public:
	GenerateOptimalPathToLiftCommand(): DriveTrainFollowPathCommand("GenerateOptimalPathToLiftCommand"){}
	void Initialize(){
		double timeStamp = frc::GetFPGATime();
		AimingParameters params = RobotChains::getInstance()->getGearAimingParameters(timeStamp).begin();

		Waypoint initial = {0,0,params.getAngle()};
		Waypoint middle = {params.getDistance() * params.getAngle().getCos(),
				params.getDistance() - 18, 0};
		Waypoint final = {params.getDistance() * params.getAngle().getCos(),
				params.getDistance() * params.getAngle().getSin(), 0};

		Waypoint path[3] = {initial, middle, final};
		GeneratePath(path, 3);
	}
	void Execute(){}
	bool IsFinished(){
		return true;
	}
	void End(){}
	void Interrupted(){}
};

#endif  // GenerateOptimalPathToLiftCommand_H
