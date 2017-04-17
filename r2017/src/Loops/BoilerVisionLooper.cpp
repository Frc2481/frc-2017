/*
 * BoilerVisionLooper.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: FIRSTMentor
 */
#include "Loops/BoilerVisionLooper.h"
#include "Utils/Constants.h"
#include "Vision/VisionUpdateReceiver.h"

BoilerVisionLooper::BoilerVisionLooper()
	: Looper(100000), m_camera(frc::CameraServer::GetInstance()->StartAutomaticCapture("cam2", 1)),
	  m_cameraHelper(58.17, 320, 240){
	m_pipeline.reset(new grip::GripBoilerTarget());
	m_camera.SetFPS(10);
	m_camera.SetResolution(320, 240);
	m_camera.SetBrightness(0);
	m_camera.SetExposureManual(0);
	m_visionRunner.reset(new frc::VisionRunner<grip::GripBoilerTarget>(
			m_camera,
			m_pipeline.get(),
			std::bind(&BoilerVisionLooper::Process, this, std::placeholders::_1)));
}

BoilerVisionLooper::~BoilerVisionLooper() {
	// TODO Auto-generated destructor stub
}

void BoilerVisionLooper::OnStart() {
}

void BoilerVisionLooper::OnLoop() {
//	printf("BoilerOnLoop\n");
	m_visionRunner->RunOnce();
}

void BoilerVisionLooper::OnStop() {
}

void BoilerVisionLooper::Process(grip::GripBoilerTarget& pipeline) {
	auto targets = pipeline.GetFilterContoursOutput();
//	printf("Target Size %d\n", targets->size());
	VisionUpdate visionUpdate;
	int i = 0;
	for(auto target : *targets) {
		cv::Rect bb = cv::boundingRect(target);
		double centerX = bb.x + bb.width / 2.0;
		double y = -(centerX - m_cameraHelper.GetCenterColumn()) / m_cameraHelper.GetFocalLengthPixels();
		double z = -(bb.y - m_cameraHelper.GetCenterRow()) / m_cameraHelper.GetFocalLengthPixels();
		visionUpdate.m_targets.push_back(TargetInfo(y, z));
		//SmartDashboard::PutNumber("FocalLengthPixels", m_cameraHelper.GetFocalLengthPixels());
//		std::stringstream ss("Target X");
//		ss << i;
//		SmartDashboard::PutNumber(ss.str().c_str(), bb.x);
//		std::stringstream ss2("Target Y");
//		ss2 << i++;
//		SmartDashboard::PutNumber(ss2.str().c_str(), bb.y);
	}
	for (auto it : m_receivers) {
		it->gotUpdate(visionUpdate);
	}
}

BoilerVisionLooper* BoilerVisionLooper::GetInstance() {
	static BoilerVisionLooper instance;
	return &instance;
}

void BoilerVisionLooper::addVisionUpdateReceiver(VisionUpdateReceiver* receiver)
{
	if(std::find(m_receivers.begin(), m_receivers.end(), receiver) == m_receivers.end())
	{
		m_receivers.push_back(receiver);
	}
}

void BoilerVisionLooper::removeVisionUpdateReceiver(VisionUpdateReceiver* receiver)
{
	auto result = std::find(m_receivers.begin(), m_receivers.end(), receiver);
	if (result != m_receivers.end()) {
		m_receivers.erase(result);
	}
}
