/*
 * TalonMotionProfileFollower.h
 *
 *  Created on: Mar 25, 2017
 *      Author: Team2481
 */

#ifndef SRC_COMPONENTS_TALONMOTIONPROFILEFOLLOWER_H_
#define SRC_COMPONENTS_TALONMOTIONPROFILEFOLLOWER_H_
#include "CANTalon.h"

class TalonMotionProfileFollower {
private:
	CANTalon *m_talon;
	CANTalon::MotionProfileStatus m_status;
	int m_loopTimeout;
	bool m_debug;
	bool m_started;
	static const int kNumLoopsTimeout = 10;
	static const int kMinPointsInTalon = 5;
public:
	TalonMotionProfileFollower(CANTalon *talon);
	virtual ~TalonMotionProfileFollower();
	void Periodic();
	void LoadPath(const double profile[][3], int count);
	void RunPath();
	bool IsReady();
	bool IsTimedOut();
	bool IsFinished();
};

#endif /* SRC_COMPONENTS_TALONMOTIONPROFILEFOLLOWER_H_ */
