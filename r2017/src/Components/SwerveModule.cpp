/*
 * SwerveModule.cpp
 *
 *  Created on: Jan 19, 2017
 *      Author: FIRSTMentor
 */

#include <Components/SwerveModule.h>

SwerveModule::SwerveModule(uint32_t driveID, uint32_t steerID) {
	// TODO Auto-generated constructor stub
	m_driveMotor = new CANTalon(driveID);
	m_steerMotor = new CANTalon(steerID);
	m_prevAngle = 0;
	m_offset = 0;
	m_optimized = 0;
	m_speedP = 0;
	m_speedI = 0;
	m_speedD = 0;
	m_steerP = 0;
	m_steerI = 0;
	m_steerD = 0;
	m_isSpeedPIDEnabled = false;

	m_driveMotor->SelectProfileSlot(0);
	m_driveMotor->SetControlMode(CANTalon::kSpeed);
	m_driveMotor->SetPID(m_speedP, m_speedI, m_speedD);
	m_driveMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	m_driveMotor->SetSensorDirection(true);

	m_steerMotor->SelectProfileSlot(0);
	m_steerMotor->SetControlMode(CANTalon::kPosition);
	m_steerMotor->SetPID(m_steerP, m_steerI, m_steerD);
	m_steerMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
	m_steerMotor->SetSensorDirection(true);
	m_steerMotor->Enable();
}

SwerveModule::~SwerveModule() {
	delete m_driveMotor;
	delete m_steerMotor;
}

void SwerveModule::Set(float speed, float angle) {
	while(angle > 360.0f)
		angle -= 360.0f;
	while(angle < 0.0f)
		angle += 360.0f;

	float currentAngle = GetAngle();

	if (fabs(angle - currentAngle) > 90 && fabs(angle - currentAngle) < 270) {
		angle = ((int)angle + 180) % 360;
		speed = -speed;
	}

	//If we are moving slowly, don't change the angle to keep things stable (rotating wheels when speed is small can induce lateral movement)
	if (fabs(speed) < .05){
		angle = m_prevAngle;
	}
	else {
		m_prevAngle = angle;
	}

	m_driveMotor->Set(speed);
	m_steerMotor->SetSetpoint(angle);
}


float SwerveModule::GetSpeed() const {
	return m_driveMotor->Get();
}

float SwerveModule::GetAngle() const {
	return m_steerMotor->GetPosition();
}

float SwerveModule::GetOffset() const {
	return m_offset;
}

void SwerveModule::SetOffset(float offset) {
	m_steerMotor->SetPosition(offset);
	m_offset = offset;
}

void SwerveModule::SetBrake(bool brake) {
	m_driveMotor->ConfigNeutralMode(brake ? CANTalon::kNeutralMode_Brake : CANTalon::kNeutralMode_Coast);
}

void SwerveModule::SetSpeedPID(double p, double i, double d) {
	m_speedP = p;
	m_speedI = i;
	m_speedD = d;
	m_driveMotor->SetPID(p, i, d);
}

double SwerveModule::GetSpeedP() {
	return m_speedP;
}

double SwerveModule::GetSpeedI() {
	return m_speedI;
}

double SwerveModule::GetSpeedD() {
	return m_speedD;
}

void SwerveModule::SetSpeedPIDEnabled(bool enabled) {
	if(enabled) {
		m_driveMotor->Enable();
	}
	else {
		m_driveMotor->Disable();
	}
	m_isSpeedPIDEnabled = enabled;
}

void SwerveModule::SetSteerPID(double p, double i, double d) {
	m_steerP = p;
	m_steerI = i;
	m_steerD = d;
	m_steerMotor->SetPID(p, i, d);
}

double SwerveModule::GetSteerP() {
	return m_steerP;
}

double SwerveModule::GetSteerI() {
	return m_steerI;
}

double SwerveModule::GetSteerD() {
	return m_steerD;
}
