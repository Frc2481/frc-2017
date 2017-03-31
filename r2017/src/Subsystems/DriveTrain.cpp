#include <Commands/DriveWithJoystickCommand.h>
#include "DriveTrain.h"
#include "../RobotMap.h"

#include <cmath>
#include <algorithm>
#include "RobotParameters.h"
#include "Components/PersistedSettings.h"
#include "RoboUtils.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"),
	m_flWheel(new SwerveModule(FRONT_LEFT_DRIVE, FRONT_LEFT_STEER)),
	m_frWheel(new SwerveModule(FRONT_RIGHT_DRIVE, FRONT_RIGHT_STEER)),
	m_brWheel(new SwerveModule(BACK_RIGHT_DRIVE, BACK_RIGHT_STEER)),
	m_blWheel(new SwerveModule(BACK_LEFT_DRIVE, BACK_LEFT_STEER)),
	m_shifter(new Solenoid(SHIFTER)),
	//m_serialPort(new SerialPort(57600,SerialPort::kUSB)),
	m_imu(new AHRS(SerialPort::kMXP)),
//		imu(new IMU(serialPort,update_rate_hz)),
	m_trajectoryFollower(new TrajectoryFollowerLooper(5000, this)),
	m_isFieldCentric(false),
	m_isForward(true),
	m_XPos(0), m_YPos(0), m_Twist(0) {

	printf("Pre DriveTrain Constructor \n");
	m_prevAngle = 90.0;
	m_flWheel->SetOffset(PersistedSettings::GetInstance().Get("FL_ENCODER_OFFSET", 0));
	m_frWheel->SetOffset(PersistedSettings::GetInstance().Get("FR_ENCODER_OFFSET", 0));
	m_brWheel->SetOffset(PersistedSettings::GetInstance().Get("BR_ENCODER_OFFSET", 0));
	m_blWheel->SetOffset(PersistedSettings::GetInstance().Get("BL_ENCODER_OFFSET", 0));
	//driveLogger = new DataLogger("/home/lvuser/DriveLogger.txt");
	m_gyroCorrection = false;

	m_originX = 0.0f;
	m_originY = 0.0f;

/*	bool is_calibrating = imu->IsCalibrating();
	if(!is_calibrating)
	{
		Wait(0.3);
			imu->ZeroYaw();
	}*/
	m_trajectoryFollower->Start();
	printf("Post DriveTrain Constructor \n");
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystickCommand());
}

void DriveTrain::Stop() {
	Drive(0,0,0);
}

void DriveTrain::SetLengthAndWidth(double robotLength, double robotWidth) {
	m_baseLength = robotLength;
	m_baseWidth = robotWidth;
	m_radius = sqrt(pow(robotLength, 2)+pow(robotWidth, 2));
}
//ToDo: move out to library
double DriveTrain::degToRad(double deg) {
	return deg * k_pi / 180;
}

double DriveTrain::radToDeg(double rad) {
	return rad * 180 / k_pi;
}

DriveTrain::~DriveTrain() {
	delete m_frWheel;
	delete m_brWheel;
	delete m_flWheel;
	delete m_blWheel;
}

void DriveTrain::SetSpeedPID(double p, double i, double d){
	m_flWheel->SetSpeedPID(p, i, d);
	m_frWheel->SetSpeedPID(p, i, d);
	m_blWheel->SetSpeedPID(p, i, d);
	m_brWheel->SetSpeedPID(p, i, d);
}
float DriveTrain::GetSpeedP() {
	return m_flWheel->GetSpeedP();
}
float DriveTrain::GetSpeedI(){
	return m_flWheel->GetSpeedI();
}
float DriveTrain::GetSpeedD(){
	return m_flWheel->GetSpeedD();
}

void DriveTrain::SetSteerPID(double p, double i, double d){
	m_flWheel->SetSteerPID(p, i, d);
	m_frWheel->SetSteerPID(p, i, d);
	m_blWheel->SetSteerPID(p, i, d);
	m_brWheel->SetSteerPID(p, i, d);
}
float DriveTrain::GetSteerP(){
	return m_flWheel->GetSteerP();
}
float DriveTrain::GetSteerI(){
	return m_flWheel->GetSteerI();
}
float DriveTrain::GetSteerD(){
	return m_flWheel->GetSteerD();
}

void DriveTrain::ResetGyro(){
//	printf("\n\n reset wii in driveTrain \n \n");
}

float DriveTrain::GetHeading(){
	double heading = m_imu->GetYaw();
	return heading;
}

void DriveTrain::SetFieldCentric(bool fieldCentric) {
	m_isFieldCentric = fieldCentric;
}

void DriveTrain::SetForward(bool fwd) {
	m_isForward = fwd;
}

void DriveTrain::SetGyroCorrection(bool b) {
	m_gyroCorrection = b;
	ResetGyroAccumError();
}

void DriveTrain::ResetGyroAccumError()
{
	m_gyroAccumError = 0.0;
}

void DriveTrain::ZeroYaw() {
	m_imu->ZeroYaw();
}

bool DriveTrain::IsGyroCorrection() const {
	return m_gyroCorrection;
}

//IMU* DriveTrain::GetIMU(){
//	return imu;
//}

void DriveTrain::Drive(double xPos, double yPos, double twist) {
	m_XPos = xPos;
	m_YPos = yPos;
	m_Twist = twist;

	double FWD;
	double STR;

	float gyroAngle = m_imu->GetYaw();//RoboUtils::constrainDeg180From(m_imu->GetYaw(), m_gyroCorrectionOffset);

	//stop Gryo from correcting while sitting still
	if (m_gyroCorrection) {
//		if(m_XPos != 0 || m_YPos != 0) {
			gyroAngle -= m_gyroCorrectionOffset;
//			gyroAngle = std::max(std::min(gyroAngle, 30.0f), -30.0f);
//			m_gyroAccumError += (gyroAngle * 2.0);
//			m_gyroAccumError = std::max(std::min(m_gyroAccumError, 5.0), -5.0);
			float P = .04;//SmartDashboard::GetNumber("Gyro Correction P", 0.0);//0.008; // mPIDGyro->GetP();
//			float I = SmartDashboard::GetNumber("Gyro Correction I", 0.0); // mPIDGyro->GetI() * .1;
//			twist = gyroAngle * P + m_gyroAccumError * I;
//			twist *= sqrt((m_XPos * m_XPos) + (m_YPos * m_YPos));
//			twist *= 2;
//			twist = std::max(std::min(twist, .5), -.5);
		twist = gyroAngle * P;
	}
//
		SmartDashboard::PutNumber("DriveTrain X", m_XPos);
		SmartDashboard::PutNumber("DriveTrain Y", m_YPos);
		SmartDashboard::PutBoolean("GYRO Correction", m_gyroCorrection);
//
		twist = -twist;
		if (m_isFieldCentric) {
			m_heading = -gyroAngle;
			FWD = yPos * std::cos(m_heading * M_PI / 180) + xPos *std::sin(m_heading * M_PI / 180);
			STR = -(xPos * std::cos(m_heading * M_PI / 180) - yPos * std::sin(m_heading * M_PI / 180));
			twist = twist * 0.1;
		}
		else {
			  //limit twist speed while not in field centric
			FWD = yPos;
			STR = -xPos;
			SmartDashboard::PutNumber("DriveTrain Twist", twist);
			twist = twist * .05;
		}

		if (m_isForward) {
			FWD = -FWD;
			STR = -STR;
		}

		if(fabs(m_originX) > 0.1f || fabs(m_originY) > 0.1f){
			twist *= -1;
		}

	    double A = STR - twist * ((m_baseLength / 2.0)+m_originY);
		double B = STR + twist * ((m_baseLength / 2.0)-m_originY);
		double C = FWD - twist * ((m_baseWidth / 2.0)+m_originX);
		double D = FWD + twist * ((m_baseWidth / 2.0)-m_originX);
		double wheelSpeedFL = sqrt(pow(B, 2) + pow(D, 2));
		double wheelSpeedFR = sqrt(pow(B, 2) + pow(C, 2));
		double wheelSpeedBL = sqrt(pow(A, 2) + pow(D, 2));
		double wheelSpeedBR = sqrt(pow(A, 2) + pow(C, 2));
		double wheelAngleFL = atan2(B, D) * 180 / k_pi;
		double wheelAngleFR = atan2(B, C) * 180 / k_pi;
		double wheelAngleBL = atan2(A, D) * 180 / k_pi;
		double wheelAngleBR = atan2(A, C) * 180 / k_pi;


	//speeds normalized 0 to 1
	//maybe eventually reverse motor instead of turning far and going forward
	double maxWheelSpeed = wheelSpeedFR;
	if (wheelSpeedFL > maxWheelSpeed) {
		maxWheelSpeed = wheelSpeedFL;
	}
	if (wheelSpeedBR > maxWheelSpeed) {
		maxWheelSpeed = wheelSpeedBR;
	}
	if (wheelSpeedBL > maxWheelSpeed) {
		maxWheelSpeed = wheelSpeedBL;
	}
	if (maxWheelSpeed > 1) {
		wheelSpeedFR /= maxWheelSpeed;
		wheelSpeedFL /= maxWheelSpeed;
		wheelSpeedBR /= maxWheelSpeed;
		wheelSpeedBL /= maxWheelSpeed;
	}

	SmartDashboard::PutNumber("aref", ControllerPower::GetVoltage5V());
	SmartDashboard::PutNumber("commandedAngleFR", wheelAngleFR);
	SmartDashboard::PutNumber("commandedAngleFL", wheelAngleFL);
	SmartDashboard::PutNumber("commandedAngleBR", wheelAngleBR);
	SmartDashboard::PutNumber("commandedAngleBL", wheelAngleBL);
	SmartDashboard::PutNumber("commandedSpeedFR", wheelSpeedFR);
	SmartDashboard::PutNumber("commandedSpeedFL", wheelSpeedFL);
	SmartDashboard::PutNumber("commandedSpeedBR", wheelSpeedBR);
	SmartDashboard::PutNumber("commandedSpeedBL", wheelSpeedBL);

	m_flWheel->Set(-wheelSpeedFL, wheelAngleFL);
	m_frWheel->Set(wheelSpeedFR, wheelAngleFR);
	m_brWheel->Set(wheelSpeedBR, wheelAngleBR);
	m_blWheel->Set(-wheelSpeedBL, wheelAngleBL);
}

void DriveTrain::SetOrigin(double xPos, double yPos) {
	m_originX = xPos;
	m_originY = yPos;
}

double DriveTrain::GetXOrigin() {
	return m_originX;
}

double DriveTrain::GetYOrigin() {
	return m_originY;
}

float DriveTrain::GetRoll() {
//	roll = imu->GetRoll();
	return m_roll;
}

float DriveTrain::GetPitch() {
//	pitch = imu->GetPitch();
	return m_pitch;
}

void DriveTrain::PeriodicUpdate() {
	Drive(m_XPos, m_YPos, m_Twist);
}

void DriveTrain::SetBrake(bool brake) {
	m_flWheel->SetBrake(brake);
	m_frWheel->SetBrake(brake);
	m_blWheel->SetBrake(brake);
	m_brWheel->SetBrake(brake);
}

double DriveTrain::GetGyroCorrectionOffset() {
	return m_gyroCorrectionOffset;
}

void DriveTrain::SetGyroCorrectionOffset(double offset) {
	m_gyroCorrectionOffset = offset;
}

void DriveTrain::Shift(bool state){
	m_shifter->Set(state);
}

SwerveModule* DriveTrain::GetModule(DriveTrain::SwerveModuleType module) {
	if(module == FRONT_RIGHT_MODULE){
		return m_frWheel;
	}
	else if(module == FRONT_LEFT_MODULE){
		return m_flWheel;
	}
	else if(module == BACK_RIGHT_MODULE){
		return m_brWheel;
	}
	else if(module == BACK_LEFT_MODULE){
		return m_blWheel;
	}
	return 0;
}

Rotation2D DriveTrain::GetAngle() {
	return Rotation2D::fromDegrees(m_imu->GetAngle());
}

double DriveTrain::GetFLVelocityInchesPerSec() {
	return RPMToInchesPerSec(m_flWheel->GetDistance());
}

double DriveTrain::GetFRVelocityInchesPerSec() {
	return RPMToInchesPerSec(m_frWheel->GetDistance());
}

double DriveTrain::GetBLVelocityInchesPerSec() {
	return RPMToInchesPerSec(m_blWheel->GetDistance());
}

double DriveTrain::GetBRVelocityInchesPerSec() {
	return RPMToInchesPerSec(m_brWheel->GetDistance());
}

double DriveTrain::RPMToInchesPerSec(double rpm) {
	return RotationsToInches(rpm) / 60;//Not Sure Why 60
}

double DriveTrain::RotationsToInches(double rotation) {
	return rotation * (INCHES_PER_REV);
}

void DriveTrain::PerformMotionMagic(double setpoint) {
	m_motionSetpoint = setpoint;
	//m_frWheel->SetMotionMagic(m_motionSetpoint);
	//m_flWheel->SetMotionMagic(m_motionSetpoint);
	//m_brWheel->SetMotionMagic(m_motionSetpoint);
	m_flWheel->SetMotionMagic(m_motionSetpoint);
	m_frWheel->SetMotionMagic(-m_motionSetpoint);
	m_blWheel->SetMotionMagic(m_motionSetpoint);
	m_brWheel->SetMotionMagic(-m_motionSetpoint);
//	m_brWheel->SetMagicBool(true);
//	m_blWheel->SetMagicBool(true);
//	m_frWheel->SetMagicBool(true);
}

double DriveTrain::GetMotionMagicSetpoint() {
	return m_motionSetpoint;
}

void DriveTrain::SetSlaveTalons() {
	//m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetClosedLoopOutputDirection(false);
	//m_brWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetClosedLoopOutputDirection(false);
	//m_frWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetClosedLoopOutputDirection(false);
	m_blWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetClosedLoopOutputDirection(false);
	m_flWheel->SetOptimized(false);
	m_blWheel->SetSlaveMotor(FRONT_LEFT_DRIVE);
	m_frWheel->SetSlaveMotor(FRONT_LEFT_DRIVE);
	m_brWheel->SetSlaveMotor(FRONT_LEFT_DRIVE);
}

void DriveTrain::ResetSlaveTalons() {
	//m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetClosedLoopOutputDirection(true);
	//m_brWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetClosedLoopOutputDirection(true);
	//m_frWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetClosedLoopOutputDirection(true);
	m_blWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetClosedLoopOutputDirection(true);
	m_flWheel->SetOptimized(true);
	m_blWheel->ResetSlaveMotor();
	m_frWheel->ResetSlaveMotor();
	m_brWheel->ResetSlaveMotor();
}

double DriveTrain::ComputeDriveDistanceInchestoEncoderRotations(double inches) {
	double final;
	final = inches;
	final /= INCHES_PER_REV;
	final *= ENCODER_REV_PER_WHEEL_REV;
	SmartDashboard::PutNumber("DistanceFromInches", final);
	return final;
}

bool DriveTrain::IsSteerOnTarget(double angle) {
	return m_flWheel->IsOnTarget(angle) && m_frWheel->IsOnTarget(angle)
			&& m_blWheel->IsOnTarget(angle) && m_brWheel->IsOnTarget(angle);
}

void DriveTrain::SetMotionMagicAccel(double accel) {
	m_flWheel->SetMagicAccel(accel);
	m_frWheel->SetMagicAccel(accel);
	m_blWheel->SetMagicAccel(accel);
	m_brWheel->SetMagicAccel(accel);
}

double DriveTrain::GetDriveDistance() {
	return fabs(m_flWheel->GetDistance());
}

bool DriveTrain::IsShifted() {
	return m_shifter->Get();
}

void DriveTrain::EnableFollower() {
	m_trajectoryFollower->Enable();
}

void DriveTrain::DisableFollower() {
	m_trajectoryFollower->Disable();
}
