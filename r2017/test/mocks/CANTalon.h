#pragma once
Class CANTalon{
public:
	
	enum ControlMode {
		kPercentVbus = 0,
		kCurrent = 1,
		kSpeed = 2,
		kPosition = 3,
		kVoltage = 4,
		kFollower = 5,
		kMotionProfile = 6,
	};
	
	CANTalon();
	CANTalon(int deviceNumber);
	~CANTalon();
	void Set(double value);
	double Get() const;
	void SelectProfileSlot(int slotIdx);
	void SetControlMode(ControlMode mode);
	void SetPID(m_steerP, m_steerI, m_steerD);
	void SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
	void SetSensorDirection(true);
	void SetClosedLoopOutputDirection(false);
	void SetPulseWidthPosition(int pos);
    void SetAllowableClosedLoopErr(int error);
	void SetStatusFrameRateMs(CANTalon::StatusFrameRateFeedback, int period);
	void Enable();

    
private:
	double m_speed;
};
}


