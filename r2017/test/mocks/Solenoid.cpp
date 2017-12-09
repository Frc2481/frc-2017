#include "Solenoid.h"

Solenoid::Solenoid()
	: m_on(false) {
}

Solenoid::Solenoid(int moduleNumber, int channel)
	: m_on (false){
}

Solenoid::~Solenoid() {
}

void Solenoid::Set(bool on) {
	m_on = on;
}

bool Solenoid::Get() const{
	return m_on;
}
