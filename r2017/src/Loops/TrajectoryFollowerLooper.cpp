/*
 * TrajectoryFollowerLooper.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: Team2481
 */

#include <Loops/TrajectoryFollowerLooper.h>
#include "Components/TrajectoryFollower.h"

TrajectoryFollowerLooper::TrajectoryFollowerLooper(int interval) : Looper(interval){
}

TrajectoryFollowerLooper::~TrajectoryFollowerLooper() {
	// TODO Auto-generated destructor stub
}

void TrajectoryFollowerLooper::OnLoop() {
	TrajectoryFollower::GetInstance()->PeriodicUpdate();
}

TrajectoryFollowerLooper* TrajectoryFollowerLooper::GetInstance() {
	static TrajectoryFollowerLooper m_instance(10000);
	return &m_instance;
}

void TrajectoryFollowerLooper::OnStart() {

}

void TrajectoryFollowerLooper::OnStop() {
}
