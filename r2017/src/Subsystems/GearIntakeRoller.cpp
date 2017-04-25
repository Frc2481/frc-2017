#include "GearIntakeRoller.h"
#include "../RobotMap.h"
#include "RobotParameters.h"

GearIntakeRoller::GearIntakeRoller() : Subsystem("GearIntakeRoller") {
	m_intakeMotor = new CANTalon(INTAKE_MOTOR);
	m_intakeMotor->SetControlMode(CANTalon::kPercentVbus);
}

void GearIntakeRoller::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void GearIntakeRoller::IntakeGear(double speed) {
	m_intakeMotor->Set(speed);
}

void GearIntakeRoller::SpitGear() {
	m_intakeMotor->Set(0.4);
}

void GearIntakeRoller::StopIntake() {
	m_intakeMotor->Set(0);
}

double GearIntakeRoller::GetIntakeCurrent() {
	return m_intakeMotor->GetOutputCurrent();
}

double GearIntakeRoller::GetIntakePower() {
	return fabs(m_intakeMotor->GetOutputCurrent() * m_intakeMotor->GetOutputVoltage());
}
