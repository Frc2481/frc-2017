/*
 * RobotStateLooper.h
 *
 *  Created on: Jan 30, 2017
 *      Author: Team2481
 */

#ifndef SRC_LOOPS_ROBOTCHAINLOOPER_H_
#define SRC_LOOPS_ROBOTCHAINLOOPER_H_
#include "Subsystems/DriveTrain.h"
#include "Components/Looper.h"
#include "Components/SwerveModule.h"
#include "CommandBase.h"

class RobotChainLooper : Looper {
private:
	RobotChainLooper(int interval);
	static RobotChainLooper* m_instance;
	double m_flPrevDistance;
	double m_frPrevDistance;
	double m_blPrevDistance;
	double m_brPrevDistance;
	double m_flPrevRotation;
	double m_frPrevRotation;
	double m_blPrevRotation;
	double m_brPrevRotation;
	SwerveModule* frModule = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE);
	SwerveModule* flModule = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE);
	SwerveModule* brModule = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE);
	SwerveModule* blModule = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE);
public:
	virtual ~RobotChainLooper();
	void OnStart();
	void OnLoop();
	void OnStop();
	RobotChainLooper* GetInstance();
};

RobotChainLooper* RobotChainLooper::m_instance = 0;

#endif /* SRC_LOOPS_ROBOTCHAINLOOPER_H_ */
