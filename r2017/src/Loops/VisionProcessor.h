/*
 * VisionProcessor.h
 *
 *  Created on: Feb 3, 2017
 *      Author: Team2481
 */

#ifndef SRC_LOOPS_VISIONPROCESSOR_H_
#define SRC_LOOPS_VISIONPROCESSOR_H_

#include <mutex>
#include "Components/Looper.h"
#include "Vision/VisionUpdate.h"
#include "utils/RobotChains.h"
#include "Components/Looper.h"

class VisionProcessor : Looper, VisionUpdateReceiver {
private:
	VisionProcessor();
	VisionUpdate m_update;
	bool m_processed;
	bool m_eligible;
	std::mutex m_mutex;
public:
	virtual ~VisionProcessor();
	VisionProcessor* GetInstance();
	void OnStart();
	void OnLoop();
	void OnStop();
	void gotUpdate(VisionUpdate update);
	void ProcessGearTarget(TargetInfo &left, TargetInfo &right);
};

#endif /* SRC_LOOPS_VISIONPROCESSOR_H_ */
