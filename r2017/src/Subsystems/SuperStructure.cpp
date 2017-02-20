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
	m_loaderMotor = new CANTalon(LOADER_MOTOR);
	m_hopperMotor = new CANTalon(HOPPER_MOTOR);
	m_hoodSolenoid = new Solenoid(HOOD_SOLENOID);
	m_hoodSolenoid2 = new Solenoid(HOOD_SOLENOID_2);
	m_shooterMotor->SetClosedLoopOutputDirection(true);
	m_shooterMotor->SelectProfileSlot(0);
	m_shooterMotor->SetControlMode(CANTalon::kSpeed);
//	m_shooterMotor->SetPID(0, 0, 0, 0);
	m_shooterMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	m_shooterMotor->SetSensorDirection(true);
	m_shooterMotor->ConfigPeakOutputVoltage(12,-12);
//	m_shooterMotor->SetInverted(true);
	m_loaderSpeed = 1;
	m_loaderMotor->SetInverted(true);
	m_onTargetCounter = 0;
	m_speed = 1;
}

SuperStructure::~SuperStructure(){
	delete m_shooterMotor;
	delete m_loaderMotor;
	delete m_hopperMotor;
	delete m_hoodSolenoid;
}

void SuperStructure::TurnShooterOn(){
	m_shooterMotor->Enable();
	double targetSpeed = SmartDashboard::GetNumber("Shooter Setpoint", 0.0);
	SetShooterSetpoint(targetSpeed);
	printf("Shooter setpoint: %f\n", targetSpeed);
	printf("Shooter P: %f, I: %f, d: %f\n", m_shooterMotor->GetP(), m_shooterMotor->GetI(), m_shooterMotor->GetP());
}

void SuperStructure::TurnShooterOff(){
	m_shooterMotor->Disable();
}

void SuperStructure::SetShooterSetpoint(double setpoint) {
	m_shooterMotor->Set(setpoint);
}

void SuperStructure::SetPID(double p, double i, double d) {
	m_p = p;
	m_i = i;
	m_d = d;
	m_shooterMotor->SetPID(m_p, m_i, m_d);
}

double SuperStructure::GetP() {
	return m_p;
}

double SuperStructure::GetI() {
	return m_i;
}

double SuperStructure::GetD() {
	return m_d;
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
	if(m_shooterMotor->GetSpeed() > 1000 && fabs(m_shooterMotor->GetSpeed() - m_shooterMotor->GetSetpoint() > 20)){
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
	m_hoodSolenoid->Set(true);
	m_hoodSolenoid2->Set(false);
}

void SuperStructure::LowerHood() {
	m_hoodSolenoid->Set(false);
	m_hoodSolenoid2->Set(true);
}

bool SuperStructure::IsRaised() {
	return m_hoodSolenoid->Get();
}

void SuperStructure::SetShooterSpeed(double speed) {
	m_shooterMotor->Enable();
	m_shooterMotor->SetControlMode(CANTalon::kSpeed);
	m_shooterMotor->Set(speed);
//	m_shooterMotor->Enable();
//	printf("PID enabled\n");
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
