#ifndef DriveTrain_H
#define DriveTrain_H

#include "../RobotParameters.h"
#include "../Components/SwerveModule.h"
#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "AHRS.h"
#include "utils/Rotation2D.h"

#include <Commands/Subsystem.h>
#include <Components/SwerveModule.h>

class DriveTrain : public Subsystem {
private:
	SwerveModule *m_flWheel;
	SwerveModule *m_frWheel;
	SwerveModule *m_brWheel;
	SwerveModule *m_blWheel;
	Solenoid *m_shifter;
	const uint8_t k_updateRateHz = 50;
	SerialPort* m_serialPort;
	AHRS* m_imu;
	const double k_pi = 3.14159;
	double m_baseWidth;
	double m_baseLength;
	double m_prevAngle;
	double m_radius;
	float m_prevAngleFR;
	float m_prevAngleFL;
	float m_prevAngleBR;
	float m_prevAngleBL;
	float m_angleOffset;
	float m_heading;
	float m_roll;
	float m_pitch;
	double m_gyroAccumError = 0;
	double m_gyroCorrectionOffset = 180;
	float m_originX;
	float m_originY;
	double m_motionSetpoint;

	bool m_isFieldCentric;
	bool m_isForward;
	bool m_gyroCorrection;
	double m_XPos, m_YPos, m_Twist;

public:
	enum SwerveModuleType{
		FRONT_LEFT_MODULE,
		FRONT_RIGHT_MODULE,
		BACK_LEFT_MODULE,
		BACK_RIGHT_MODULE,
	};
	DriveTrain();
	~DriveTrain();
	void InitDefaultCommand();
	void Drive(double xPos, double yPos, double twist);
	double degToRad(double deg);
	double radToDeg(double rad);
	double limitAngle(double angle);
	void SetLengthAndWidth(double robotLength, double robotWidth);
	void SetOrigin(double xPos, double yPos);
	double GetXOrigin();
	double GetYOrigin();
	void SetSpeedPID(double p, double i, double d);
	float GetSpeedP();
	float GetSpeedI();
	float GetSpeedD();
	void SetSteerPID(double p, double i, double d);
	float GetSteerP();
	float GetSteerI();
	float GetSteerD();
	//void SetI(float i);
	void ResetGyro();
	float GetHeading();
	float GetRoll();
	float GetPitch();
	double GetGyroCorrectionOffset();
	void Stop();
	void SetFieldCentric(bool fieldCentric);
	//void SetOptimized(bool optimized);
	void SetForward(bool fwd);
	void SetGyroCorrection(bool b);
	void SetGyroCorrectionOffset(double offset);
	void ResetGyroAccumError();
	void ZeroYaw();
	bool IsGyroCorrection() const;
//	IMU* GetIMU();
	void PeriodicUpdate();
	void SetBrake(bool brake);
	void Shift(bool state);
	SwerveModule* GetModule(DriveTrain::SwerveModuleType module);
	Rotation2D GetAngle();
	void PerformMotionMagic(double setpoint);

	double GetMotionMagicSetpoint();

	double GetFLVelocityInchesPerSec();
	double GetFRVelocityInchesPerSec();
	double GetBLVelocityInchesPerSec();
	double GetBRVelocityInchesPerSec();
	double RPMToInchesPerSec(double rpm);
	double RotationsToInches(double rotation);

	double ComputeDriveDistanceInchestoEncoderRotations(double inches);

	void SetSlaveTalons();
	void ResetSlaveTalons();
};

#endif  // DriveTrain_H
