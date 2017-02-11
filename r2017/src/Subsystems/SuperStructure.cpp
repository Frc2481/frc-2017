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
	m_shooterMotor->SetClosedLoopOutputDirection(true);
	m_shooterMotor->SelectProfileSlot(0);
	m_shooterMotor->SetControlMode(CANTalon::kSpeed);
	m_shooterMotor->SetPID(0, 0, 0, 0);
	m_shooterMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	m_shooterMotor->SetSensorDirection(true);
	m_loaderSpeed = 0;
	m_onTargetCounter = 0;
	m_speed = 0.2;
}

SuperStructure::~SuperStructure(){
	delete m_shooterMotor;
	delete m_loaderMotor;
	delete m_hopperMotor;
	delete m_hoodSolenoid;
}

void SuperStructure::TurnShooterOn(){
	m_shooterMotor->Enable();
}

void SuperStructure::TurnShooterOff(){
	m_shooterMotor->Disable();
}

void SuperStructure::SetShooterSetpoint(double setpoint) {
	m_shooterMotor->SetSetpoint(setpoint);
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
	return m_speed;
}

void SuperStructure::RaiseHood() {
	m_hoodSolenoid->Set(true);
}

void SuperStructure::LowerHood() {
	m_hoodSolenoid->Set(false);
}

bool SuperStructure::IsRaised() {
	return m_hoodSolenoid->Get();
}
