#include "GearIntake.h"
#include "../RobotMap.h"
#include "Commands/IntakePivotWithJoyStickCommand.h"

const double GEAR_DOWN_POS = 1500.0;
const double GEAR_UP_POS = 0.0;

GearIntake::GearIntake() : Subsystem("GearIntake") {
	m_intakeMotor = new CANTalon(INTAKE_MOTOR);
	m_pivotMotor = new CANTalon(PIVOT_MOTOR);
	m_offset = PersistedSettings::GetInstance().Get("GEAR_INTAKE_OFFSET", 0);
	printf("IntakeOffset %f\n", m_offset);
	m_setpoint = 0;

	m_intakeMotor->SetControlMode(CANTalon::kPercentVbus);

	m_pivotMotor->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
	m_pivotMotor->SelectProfileSlot(0);
	m_pivotMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
	m_pivotMotor->SetSensorDirection(false);
	m_pivotMotor->SetPulseWidthPosition(m_pivotMotor->GetPulseWidthPosition() & 0xFFF);
	m_pivotMotor->SetClosedLoopOutputDirection(true);
	m_pivotMotor->SetAllowableClosedLoopErr(10);
	m_pivotMotor->ConfigNominalOutputVoltage(1.5,-2.0);
	m_pivotMotor->ConfigPeakOutputVoltage(4.0,-4.0);
	//m_pivotMotor->ConfigLimitMode(CANSpeedController::kLimitMode_SoftPositionLimits);

//	double intakeDown = Preferences::GetInstance()->GetDouble("INTAKE_DOWN_POS", 1250.0);
//	double intakeUp = Preferences::GetInstance()->GetDouble("INTAKE_UP_POS", 0.0);
//	m_pivotMotor->ConfigSoftPositionLimits(intakeUp, intakeDown);
}

void GearIntake::IntakeGear(double speed) {
	printf("IntakeGear\n");
	m_intakeMotor->Set(speed);
}

void GearIntake::SpitGear() {
	printf("SpitGear\n");
	m_intakeMotor->Set(0.4);
}

void GearIntake::StopIntake() {
	printf("StopIntake\n");
	m_intakeMotor->Set(0);
}

void GearIntake::InitDefaultCommand() {
	SetDefaultCommand(new IntakePivotWithJoyStickCommand());
}

void GearIntake::SetIntakePos(double pos) {
	m_pivotMotor->Enable();
	m_pivotMotor->SetControlMode(CANTalon::kPosition);
	double setpoint = pos + m_offset;
	m_setpoint = setpoint / 4096.0;
	m_setpoint = std::max(std::min(m_setpoint, GEAR_DOWN_POS), GEAR_UP_POS);

	m_pivotMotor->SetSetpoint(m_setpoint);
}

double GearIntake::GetPivotSpeed() {
	return m_pivotMotor->GetSpeed();
}

void GearIntake::StopIntakePivot() {
	m_pivotMotor->Disable();
}

double GearIntake::GetPivotPos() {
	return GetRawPivotPos() - m_offset;
}

double GearIntake::GetRawPivotPos() {
	return m_pivotMotor->GetPulseWidthPosition();
}

double GearIntake::GetIntakeCurrent() {
	return m_intakeMotor->GetOutputCurrent();
}

double GearIntake::GetIntakePower() {
	return fabs(m_intakeMotor->GetOutputCurrent() * m_intakeMotor->GetOutputVoltage());
}

void GearIntake::SetIntakeOpenLoop(double speed) {
	m_pivotMotor->Enable();
	m_pivotMotor->SetControlMode(CANTalon::kPercentVbus);
	m_pivotMotor->Set(speed);
}

bool GearIntake::PivotOnTarget() {
	return fabs(m_setpoint - GetPivotPos()) <= 5.0;
}

bool GearIntake::IsEncoderPluggedIn() {
	return m_pivotMotor->IsSensorPresent(CANTalon::CtreMagEncoder_Absolute);
}

void GearIntake::ZeroEncoderPosition() {
	m_pivotMotor->SetEncPosition(0);
}

double GearIntake::GetPivotCurrent() {
	return m_pivotMotor->GetOutputCurrent();
}

double GearIntake::GetPivotAppliedThrottle() {
	return m_pivotMotor->GetOutputVoltage();
}
