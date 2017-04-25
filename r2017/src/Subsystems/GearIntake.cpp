#include "GearIntake.h"
#include "../RobotMap.h"
#include "Commands/IntakePivotWithJoyStickCommand.h"
#include "Commands/IntakeWhenBeamBrokenCommand.h"

const double GEAR_DOWN_POS = 1500.0;
const double GEAR_UP_POS = 0.0;

GearIntake::GearIntake() : Subsystem("GearIntake") {
	m_pivotMotor = new CANTalon(PIVOT_MOTOR);
	m_hpBreak = new DigitalInput(0);
	m_intakeBreak = new DigitalInput(1);
	m_offset = PersistedSettings::GetInstance().Get("GEAR_INTAKE_OFFSET", 0);
	printf("IntakeOffset %f\n", m_offset);
	m_setpoint = 0;
	m_hasGear = false;
	m_hpBeam = false;
	m_lock = false;

	m_pivotMotor->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
	m_pivotMotor->SelectProfileSlot(0);
	m_pivotMotor->SetPID(2.1,0.0,0.0);
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

void GearIntake::InitDefaultCommand() {
//	SetDefaultCommand(new IntakePivotWithJoyStickCommand());
	SetDefaultCommand(new IntakeWhenBeamBrokenCommand());
}

void GearIntake::SetIntakePos(double pos) {
	if(!m_lock){
		m_pivotMotor->Enable();
		m_pivotMotor->SetControlMode(CANTalon::kPosition);
		double setpoint = std::max(std::min(pos, GEAR_DOWN_POS), GEAR_UP_POS);
		m_setpoint = setpoint + m_offset;
		m_setpoint /= 4096.0;
		m_pivotMotor->SetSetpoint(m_setpoint);
	}
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

void GearIntake::SetIntakeOpenLoop(double speed) {
	if(!m_lock){
		m_pivotMotor->Enable();
		m_pivotMotor->SetControlMode(CANTalon::kPercentVbus);
		m_pivotMotor->Set(speed);
	}
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

bool GearIntake::IsHPBeamBroken() {
	return !m_hpBreak->Get(); //m_hpBeam;
}

bool GearIntake::GetHasGear() {
	return !m_intakeBreak->Get(); /*m_hasGear || CommandBase::m_gearIntakeRoller->GetIntakeCurrent() >= 40.0;*/
}

double GearIntake::PivotClosedLoopError() {
	return (double)m_pivotMotor->GetClosedLoopError();
}

void GearIntake::LockGearIntake() {
	m_lock = true;
}

void GearIntake::UnlockGearIntake() {
	m_lock = false;
}

bool GearIntake::GetGearLock() {
	return m_lock;
}

void GearIntake::SetHasGear(bool hasGear) {
	m_hasGear = hasGear;
}

void GearIntake::SetHPBeamBroken(bool hpBeam) {
	m_hpBeam = hpBeam;
}

double GearIntake::GetEncoderSpeed() {
	return m_pivotMotor->GetEncVel();
}

double GearIntake::GetAppliedThrottle() {
	return m_pivotMotor->GetOutputVoltage();
}
