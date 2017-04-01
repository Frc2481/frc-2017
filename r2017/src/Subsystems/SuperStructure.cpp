/*
 * SuperStructure.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: FIRSTMentor
 */

#include "SuperStructure.h"
#include "RobotMap.h"

SuperStructure::SuperStructure() : Subsystem("SuperStructure"){
	m_shooterMotor = new CANTalon(SHOOTER_MOTOR);
	m_loaderMotor = new CANTalon(LOADER_MOTOR, 100);
	m_hopperMotor = new CANTalon(HOPPER_MOTOR, 100);
	m_hoodSolenoid = new Solenoid(HOOD_SOLENOID);
	m_hoodSolenoid2 = new Solenoid(HOOD_SOLENOID_2);
	m_shooterMotor->SetClosedLoopOutputDirection(true);
	m_shooterMotor->SelectProfileSlot(0);
	m_shooterMotor->SetControlMode(CANTalon::kSpeed);
//	m_shooterMotor->DisableNominalClosedLoopVoltage();
//	m_shooterMotor->SetNominalClosedLoopVoltage(12);
//	m_shooterMotor->DisableNominalClosedLoopVoltage();
//	m_shooterMotor->SetNominalClosedLoopVoltage(12.0f);
	m_shooterMotor->SetPID(0.025, 0.0025, 0.0);
	m_shooterMotor->SetF(0.026);
	m_shooterMotor->SetIzone(200);
	m_shooterMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	m_shooterMotor->SetSensorDirection(true);
	m_shooterMotor->ConfigPeakOutputVoltage(12,-12);
//	m_shooterMotor->SetInverted(true);
	m_loaderSpeed = 1;
	m_loaderMotor->SetInverted(true);
	m_loaderMotor->ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
	m_loaderMotor->SetVoltageRampRate(36);
	m_hopperMotor->SetVoltageRampRate(36);
	m_onTargetCounter = 0;
	m_speed = 1;
	m_shooterSpeed = 4000;
	m_hoodRaised = false;

	m_loaderMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRateAnalogTempVbat, 500);
	m_loaderMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRateFeedback, 500);
	m_loaderMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRateGeneral, 500);
	m_loaderMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRatePulseWidthMeas, 500);
	m_loaderMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRateQuadEncoder, 500);

	m_shooterMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRateAnalogTempVbat, 500);
	m_shooterMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRateFeedback, 500);
	m_shooterMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRateGeneral, 500);
	m_shooterMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRatePulseWidthMeas, 500);
	m_shooterMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRateQuadEncoder, 500);

	m_hopperMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRateAnalogTempVbat, 500);
	m_hopperMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRateFeedback, 500);
	m_hopperMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRateGeneral, 500);
	m_hopperMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRatePulseWidthMeas, 500);
	m_hopperMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRateQuadEncoder, 500);
}

SuperStructure::~SuperStructure(){
	delete m_shooterMotor;
	delete m_loaderMotor;
	delete m_hopperMotor;
	delete m_hoodSolenoid;
}

void SuperStructure::TurnShooterOn(){
	m_shooterMotor->Enable();
	m_shooterMotor->SetControlMode(CANTalon::kSpeed);
	m_shooterMotor->Set(m_shooterSpeed);
}

void SuperStructure::TurnShooterOff(){
	m_shooterMotor->Disable();
}

void SuperStructure::SetShooterSetpoint(double setpoint) {
	m_shooterMotor->Set(setpoint);
}

void SuperStructure::SetPID(double p, double i, double d) {
	m_shooterMotor->SetPID(p, i, d);
	//I 0.000125
	//I zone 200
}

double SuperStructure::GetP() {
	return m_shooterMotor->GetP();
}

double SuperStructure::GetI() {
	return m_shooterMotor->GetI();
}

double SuperStructure::GetD() {
	return m_shooterMotor->GetD();
}

double SuperStructure::GetShooterSetpoint() {
	return m_shooterMotor->GetSetpoint();
}

double SuperStructure::GetLoaderSpeed() {
	return m_loaderMotor->Get();
}

void SuperStructure::TurnLoaderOn() {
	m_loaderMotor->Set(m_loaderSpeed);
}

void SuperStructure::TurnLoaderOff() {
	m_loaderMotor->Set(0);
}

void SuperStructure::SetLoaderSpeed(double speed) {
	m_loaderSpeed = speed;
}

bool SuperStructure::IsShooterOn() {
	return m_shooterMotor->IsEnabled();

}

bool SuperStructure::IsOnTarget() {
	if(m_shooterMotor->GetSpeed() > 1000 && fabs(m_shooterMotor->GetSpeed() - m_shooterMotor->GetSetpoint()) < 20){
		m_onTargetCounter++;
	}

	else {
		m_onTargetCounter = 0;
	}

	return m_onTargetCounter > 5;
}

void SuperStructure::StartFeeding(){
	m_hopperMotor->Set(m_speed);
}

void SuperStructure::StopFeeding(){
	m_hopperMotor->Set(0);
}

void SuperStructure::SetSpeed(double speed){
	m_speed = speed;
}

double SuperStructure::GetSpeed(){
	return m_shooterMotor->GetSpeed();
}

void SuperStructure::RaiseHood() {
	m_hoodRaised = true;
	m_hoodSolenoid->Set(true);
	m_hoodSolenoid2->Set(false);
}

void SuperStructure::LowerHood() {
	m_hoodRaised = false;
	m_hoodSolenoid->Set(false);
	m_hoodSolenoid2->Set(true);
}

bool SuperStructure::IsRaised() {
	return m_hoodRaised;
}

void SuperStructure::SetShooterSpeed(double speed) {
	m_shooterSpeed = speed;
	SmartDashboard::PutNumber("Shooter Setpoint Speed", m_shooterSpeed);
	if (m_shooterMotor->IsEnabled()) {
		m_shooterMotor->Set(m_shooterSpeed);
	}
}

void SuperStructure::SetShooterSpeedOpenLoop(double speed) {
	m_shooterMotor->SetControlMode(CANTalon::kPercentVbus);
	m_shooterMotor->Set(speed);
}

void SuperStructure::SetShooterControlMode(CANTalon::ControlMode mode) {
	m_shooterMotor->SetControlMode(mode);
}

double SuperStructure::GetHopperCurrent() {
	return m_hopperMotor->GetOutputCurrent();
}

void SuperStructure::IncShooterSpeed() {
	m_shooterSpeed += 25;
	SetShooterSpeed(m_shooterSpeed);
}

void SuperStructure::DecShooterSpeed() {
	m_shooterSpeed -= 25;
	SetShooterSpeed(m_shooterSpeed);
}
