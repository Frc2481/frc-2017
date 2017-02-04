/*
 * TrajectoryFollowerLooper.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Team2481
 */

#ifndef SRC_LOOPS_TRAJECTORYFOLLOWERLOOPER_H_
#define SRC_LOOPS_TRAJECTORYFOLLOWERLOOPER_H_
#include "Components/Looper.h"
#include <thread>
#include <atomic>
#include <Utility.h>

class TrajectoryFollowerLooper : Looper {
private:
	TrajectoryFollowerLooper(int interval);
	static TrajectoryFollowerLooper* m_instance;
public:
	virtual ~TrajectoryFollowerLooper();
	static TrajectoryFollowerLooper* GetInstance();
	void OnStart();
	void OnLoop();
	void OnStop();
};
TrajectoryFollowerLooper* TrajectoryFollowerLooper::m_instance = 0;

#endif /* SRC_LOOPS_TRAJECTORYFOLLOWERLOOPER_H_ */
