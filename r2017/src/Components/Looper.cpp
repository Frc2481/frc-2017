/*
 * Looper.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: Team2481
 */

#include <Components/Looper.h>

Looper::Looper() {
	// TODO Auto-generated constructor stub

}

Looper::Looper(int interval) : m_interval(interval), m_started(false), m_active(false) {
}

Looper::~Looper() {
	// TODO Auto-generated destructor stub
}

void Looper::Start() {
	Looper::OnStart();
}

void Looper::Loop() {
	uint64_t start;
	while(true){
		start = frc::GetFPGATime();
		if(m_active){
			Looper::OnLoop();
		}
		uint64_t dt = frc::GetFPGATime() - start;
		uint64_t sleepTime = m_interval - dt;
		std::this_thread::sleep_for(std::chrono::microseconds(sleepTime));
	}
}

void Looper::SetActive(bool active) {
	m_active = active;
}
