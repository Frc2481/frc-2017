/*
 * SwerveModule.cpp
 *
 *  Created on: Jan 19, 2017
 *      Author: FIRSTMentor
 */

#include <Components/SwerveModule.h>
#include "RoboUtils.h"

SwerveModule::SwerveModule(uint32_t driveID, uint32_t steerID) {
	SmartDashboard::PutNumber("Temp Setpoint", 0.0);
	// TODO Auto-generated constructor stub
	m_driveMotor = new CANTalon(driveID);
	m_steerMotor = new CANTalon(steerID);
	m_prevAngle = 0;
	m_offset = 0;
	m_optimized = 0;
	m_speedP = 0;
	m_speedI = 0;
	m_speedD = 0;
	m_steerP = 3;
	m_steerI = 0;
	m_steerD = 40;
	m_isSpeedPIDEnabled = false;
	m_driveDistanceOffset = 0.0;

	m_driveMotor->SelectProfileSlot(0);
	m_driveMotor->SetControlMode(CANTalon::kPercentVbus);
	m_driveMotor->SetPID(m_speedP, m_speedI, m_speedD);
	m_driveMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	m_driveMotor->SetSensorDirection(true);

	m_driveMotor->ConfigNeutralMode(CANTalon::kNeutralMode_Coast);

	m_steerMotor->SelectProfileSlot(0);
	m_steerMotor->SetControlMode(CANTalon::kPosition);
	m_steerMotor->SetPID(m_steerP, m_steerI, m_steerD);
	m_steerMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
	m_steerMotor->SetSensorDirection(true);
	m_steerMotor->SetClosedLoopOutputDirection(false);
	m_steerMotor->SetPulseWidthPosition(m_steerMotor->GetPulseWidthPosition() & 0xFFF);
	m_steerMotor->SetAllowableClosedLoopErr(1);
	m_steerMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRateFeedback, 10);
	m_steerMotor->Enable();
}

SwerveModule::~SwerveModule() {
	delete m_driveMotor;
	delete m_steerMotor;
}

void SwerveModule::Set(float speed, float angle) {
	SetOpenLoopSpeed(speed);
	SetAngle(angle);
}


float SwerveModule::GetSpeed() const {
	return m_driveMotor->Get();
}

float SwerveModule::GetAngle() const {
	return GetRawAngle() - m_offset;
}

float SwerveModule::GetRawAngle() const{
	return m_steerMotor->GetPulseWidthPosition()/4096.0 * -360.0;
}

float SwerveModule::GetOffset() const {
	return m_offset;
}

void SwerveModule::SetOffset(float offset) {
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
	return m_steerMotor->GetP();
}

double SwerveModule::GetSteerI() {
	return m_steerI;
}

double SwerveModule::GetSteerD() {
	return m_steerD;
}

int SwerveModule::AngleToEncoderTicks(double angle) {
	return (int)(angle/360 * 4096);
}

double SwerveModule::GetDistance() {
	return m_driveMotor->GetPosition() - m_driveDistanceOffset;
}

void SwerveModule::SetOpenLoopSpeed(float speed) {
	if (m_driveMotor->GetControlMode() != CANTalon::kPercentVbus){
		m_driveMotor->SetControlMode(CANTalon::kPercentVbus);
	}

	if (fabs(speed) < .05){
		m_stopped = true;
	}
	else {
		m_stopped = false;
	}

	if(m_angleOptimized == true){
		speed *= -1;
	}
	m_driveMotor->Set(speed);
}

void SwerveModule::SetClosedLoopSpeed(float speed) {
	if (m_driveMotor->GetControlMode() != CANTalon::kSpeed){
		m_driveMotor->SetControlMode(CANTalon::kSpeed);
	}

	if (fabs(speed) > 0.01){
		m_stopped = false;
	}
	else {
		m_stopped = true;
	}

	if(m_angleOptimized == true){
		speed *= -1;
	}
	m_driveMotor->Set(speed);
}

void SwerveModule::SetAngle(float angle) {
	float currentAngle = GetAngle();

		angle = RoboUtils::constrainDeg0To360(angle);
		currentAngle = RoboUtils::constrainDeg0To360(currentAngle);

		if (m_optimized && fabs(angle - currentAngle) > 90 && fabs(angle - currentAngle) < 270) {
			angle = ((int)angle + 180) % 360;
			m_angleOptimized = true;
		}
		else{
			m_angleOptimized = false;
		}

		//If we are moving slowly, don't change the angle to keep things stable (rotating wheels when speed is small can induce lateral movement)
		if (m_stopped){
			angle = m_prevAngle;
		}
		else {
			m_prevAngle = angle;
		}

		int currentPosition = -m_steerMotor->GetPulseWidthPosition();
		int n = currentPosition/4096;
		angle += m_offset;
		angle = AngleToEncoderTicks(angle);
		angle += n*4096;
		int error = currentPosition - angle;

		if(error < -2048){
			angle -= 4096;
		}
		else if (error > 2048){
			angle += 4096;
		}
		m_steerMotor->SetSetpoint(angle / 4096.0);
}

void SwerveModule::SetOptimized(bool optimized) {
	m_optimized = optimized;
}
void SwerveModule::ResetDriveEncoders() {
	m_driveDistanceOffset = GetDistance();
}

void SwerveModule::SetRampRates() {
	m_driveMotor->SetVoltageRampRate(48);
	m_steerMotor->SetVoltageRampRate(48);
}
