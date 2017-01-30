///*
// * TrajectoryFollowerLooper.cpp
// *
// *  Created on: Jan 28, 2017
// *      Author: Team2481
// */
//
//#include <Loops/TrajectoryFollowerLooper.h>
//#include "Components/TrajectoryFollower.h"
//
//TrajectoryFollowerLooper::TrajectoryFollowerLooper() : m_active(false), m_started(false){
//}
//
//TrajectoryFollowerLooper::~TrajectoryFollowerLooper() {
//	// TODO Auto-generated destructor stub
//}
//
//void TrajectoryFollowerLooper::Run() {
//	uint64_t start;
//	while(true){
//		start = frc::GetFPGATime();
//		if(m_active){
//			TrajectoryFollower::GetInstance()->PeriodicUpdate();
//		}
//		uint64_t dt = frc::GetFPGATime() - start;
//		uint64_t sleepTime = kInterval - dt;
//		std::this_thread::sleep_for(std::chrono::microseconds(sleepTime));
//	}
//}
//
//void TrajectoryFollowerLooper::Start() {
//	if(!m_started){
//		m_looperThread = std::thread(&TrajectoryFollowerLooper::Run);
//	m_started = true;
//	}
//}
//
//void TrajectoryFollowerLooper::SetActive(bool active) {
//	m_active = active;
//}
