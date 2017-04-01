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

class RobotChainLooper : public Looper {
private:
	RobotChainLooper();
	double m_onLoopCounter;
	double m_flPrevDistance;
	double m_frPrevDistance;
	double m_blPrevDistance;
	double m_brPrevDistance;
	double m_flPrevRotation;
	double m_frPrevRotation;
	double m_blPrevRotation;
	double m_brPrevRotation;
	SwerveModule* frModule;
	SwerveModule* flModule;
	SwerveModule* brModule;
	SwerveModule* blModule;
public:
	virtual ~RobotChainLooper();
	void OnStart();
	void OnLoop();
	void OnStop();
	static RobotChainLooper* GetInstance();
};

#endif /* SRC_LOOPS_ROBOTCHAINLOOPER_H_ */
