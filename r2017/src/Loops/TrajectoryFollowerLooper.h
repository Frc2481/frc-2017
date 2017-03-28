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
#include "CANTalon.h"

class DriveTrain;

class TrajectoryFollowerLooper : public Looper {
private:
	CANTalon *m_flSteer;
	CANTalon *m_frSteer;
	CANTalon *m_blSteer;
	CANTalon *m_brSteer;
	CANTalon *m_flDrive;
	CANTalon *m_frDrive;
	CANTalon *m_blDrive;
	CANTalon *m_brDrive;
public:
	TrajectoryFollowerLooper(int interval, DriveTrain *driveTrain);
	virtual ~TrajectoryFollowerLooper();
	void OnStart();
	void OnLoop();
	void OnStop();
	void SetActive(bool active);
};

#endif /* SRC_LOOPS_TRAJECTORYFOLLOWERLOOPER_H_ */
