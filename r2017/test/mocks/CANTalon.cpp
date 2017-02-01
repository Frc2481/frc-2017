#include "CANTalon.h"

CANTalon::CANTalon()
	: m_speed(0) {
}

CANTalon::CANTalon(int moduleNumber, int channel)
	: m_speed(0) {
}

CANTalon::~CANTalon() {
}

void CANTalon::Set(double value) {
	m_speed = 0;
}

bool CANTalon::Get() const {
	return m_speed;
}

void CANTalon::SelectProfileSlot(int slotIdx) {
}

void CANTalon::SetControlMode(ControlMode mode) {
	kPosition = 3
}

void CANTalon::SetPID(m_steerP, m_steerI, m_steerD) {
}

void CANTalon::SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute) {
}

void CANTalon::SetSensorDirection(true) {
}

void CANTalon::SetClosedLoopOutputDirection(false) {
}

void CANTalon::SetPulseWidthPosition(int pos) {
}




void CANTalon::SetAllowableClosedLoopErr(int error) {
}

void CANTalon::SetStatusFrameRateMs(CANTalon::StatusFrameRateFeedback, int period) {
}

void CANTalon::Enable() {
}
