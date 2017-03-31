#ifndef SWERVEMODULE_H_
#define SWERVEMODULE_H_
#include <WPILib.h>
#include "ContinuousEncoder.h"
#include "CANTalon.h"
#include "RobotParameters.h"


class SwerveModule {
private:
    CANTalon *m_driveMotor;
    CANTalon *m_steerMotor;
    float m_prevAngle;
    float m_offset;
    bool m_optimized;
    double m_speedP;
	double m_speedI;
	double m_speedD;
    double m_steerP;
	double m_steerI;
	double m_steerD;
	bool m_isSpeedPIDEnabled;
	bool m_angleOptimized;
	bool m_stopped;
	double m_driveDistanceOffset;
	double m_velocity;
	double m_accel;
	bool m_motionMagic;
	double m_angleSetpoint;

public:
	enum CANTalonType{
		DRIVE_MOTOR,
		STEER_MOTOR,
	};
	SwerveModule(uint32_t driveID, uint32_t steerID);
	virtual ~SwerveModule();
	void Set(float speed, float angle);
	float GetSpeed()const;
	float GetAngle()const;
	float GetRawAngle()const;
	float GetOffset() const;
	void SetOffset(float offset);
	void SetBrake(bool brake);

	void SetSpeedPID(double p, double i, double d);
	void SetSpeedPIDEnabled(bool enabled);
	double GetSpeedP();
	double GetSpeedI();
	double GetSpeedD();

	int GetError();

	void SetSteerPID(double p, double i, double d);
	double GetSteerP();
	double GetSteerI();
	double GetSteerD();

	int AngleToEncoderTicks(double angle);
	double GetDistance();

	void SetOpenLoopSpeed(float speed);
	void SetClosedLoopSpeed(float speed);
	void SetAngle(float angle, bool forced = false);

	void SetOptimized(bool optimized);
	void ResetDriveEncoders();

	void SetRampRates();

	void SetSlaveMotor(int id);
	void ResetSlaveMotor();

	void SetMotionMagic(double setpoint);
	void SetMagicBool(bool magic);
	void SetMagicAccel(double accel);
	double GetAngleSetpoint();

	bool IsOnTarget(double angle);

	void SetOpenLoopSteerSpeed(double speed);

	CANTalon* GetMotor(enum CANTalonType motor);
};

#endif /*SWERVEMODULE_H_*/
