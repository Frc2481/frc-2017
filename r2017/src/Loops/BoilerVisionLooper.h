/*
 * BoilerVisionLooper.h
 *
 *  Created on: Apr 8, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_LOOPS_BOILERVISIONLOOPER_H_
#define SRC_LOOPS_BOILERVISIONLOOPER_H_
#include "WPILib.h"
#include "Components/Looper.h"
#include "Vision/GripBoilerTarget.h"
#include "Vision/CameraHelper.h"

class VisionUpdateReceiver;

class BoilerVisionLooper : public Looper{
private:
	cs::UsbCamera m_camera;
	std::auto_ptr<grip::GripBoilerTarget> m_pipeline;
	std::auto_ptr<VisionRunner<grip::GripBoilerTarget> > m_visionRunner;
	CameraHelper m_cameraHelper;
	std::vector<VisionUpdateReceiver*> m_receivers;
public:
	BoilerVisionLooper();
	virtual ~BoilerVisionLooper();
	void OnStart();
	void OnLoop();
	void OnStop();
	void Process(grip::GripBoilerTarget& pipeline);
	static BoilerVisionLooper* GetInstance();
	void removeVisionUpdateReceiver(VisionUpdateReceiver* receiver);
	void addVisionUpdateReceiver(VisionUpdateReceiver* receiver);
};

#endif /* SRC_LOOPS_BOILERVISIONLOOPER_H_ */
