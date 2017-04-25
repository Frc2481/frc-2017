#ifndef RotateToAngleGyroCommand_H
#define RotateToAngleGyroCommand_H

#include "../CommandBase.h"
#include "utils/InterpolatingDouble.h"
#include "utils/InterpolatingMap.h"
#include "utils/RobotChains.h"
#include "RoboUtils.h"

class RotateToAngleGyroCommand : public CommandBase {
protected:
	InterpolatingMap<InterpolatingDouble, InterpolatingDouble> m_pMap;
	double m_angle;
	double m_p;
	double m_i;
	double m_d;
	int m_loopCounter;
	double m_time;
	double m_prevTime;
	double m_prevError;
	double m_accumError;
	double m_offset;
public:
	RotateToAngleGyroCommand(double angle) : CommandBase("RotateToAngleGyroCommand"){
		Requires(CommandBase::m_driveTrain.get());
		m_angle = angle;
		m_loopCounter = 0;
		m_prevError = angle;
		m_accumError = 0;
		m_pMap.put(InterpolatingDouble(0), InterpolatingDouble(0));
		m_pMap.put(InterpolatingDouble(45), InterpolatingDouble(-0.0287));
		m_pMap.put(InterpolatingDouble(60), InterpolatingDouble(-0.026));
		m_pMap.put(InterpolatingDouble(90), InterpolatingDouble(-0.0205));
	}
	void Initialize(){
		//m_angle = SmartDashboard::GetNumber("RotateToAngle Angle", 0.0);
		m_p = -0.04; //SmartDashboard::GetNumber("Gyro Rotation P",0.0);
//		if(m_p == 0.0){
//			m_p = m_pMap.getInterpolated(InterpolatingDouble(fabs(m_angle - m_driveTrain->GetHeading()))).m_value;
//		}
//		m_i = SmartDashboard::GetNumber("Gyro Rotation I", 0.0);
		m_d = 0.0;///*200;*/SmartDashboard::GetNumber("Gyro Rotation D", 0.0);
		m_prevTime = frc::GetFPGATime();
	}
	void Execute(){
		m_time = frc::GetFPGATime();
		//double heading = RoboUtils::constrainDeg180From(CommandBase::m_driveTrain->GetHeading(), m_angle);
		double error = m_angle - CommandBase::m_driveTrain->GetHeading();//heading;
		double errorD = (error - m_prevError) / (m_time - m_prevTime);
//		SmartDashboard::PutNumber("ErrorD", errorD * m_d);
		double output = (error * m_p) - (errorD * m_d);
//		if(fabs(error) <= 5){
//			m_accumError += error;
//			output += m_accumError*m_i;
//		}
//		else{
//			m_accumError = 0;
//		}
//		SmartDashboard::PutNumber("AccumError", m_accumError);
		CommandBase::m_driveTrain->Drive(0,0,output);//std::min(std::max(output, -0.75),0.75));
		if(fabs(error) <= 1.5){
			m_loopCounter++;
		}
		else{
			m_loopCounter = 0;
		}
		m_prevError = error;
		m_prevTime = frc::GetFPGATime();
	}
	bool IsFinished(){
		return m_loopCounter == 5;
	}
	void End(){
//		printf("Target Rotate Angle %f\n", m_angle);
//		printf("Real Rotate Angle %f\n", CommandBase::m_driveTrain->GetHeading());
		CommandBase::m_driveTrain->Drive(0,0,0);
//		SmartDashboard::PutNumber("TimeSinceRotateStart", TimeSinceInitialized());
	}
	void Interrupted(){
		End();
	}
};

class CameraRotateToAngle : public RotateToAngleGyroCommand{
private:
	bool m_skew;
public:
	CameraRotateToAngle(bool skew = false) : RotateToAngleGyroCommand(0){
		m_skew = skew;
	}
	void Initialize(){
		double time = frc::GetFPGATime();
		std::list<AimingParameters> params = RobotChains::getInstance()->getGearAimingParameters(time);
		if(!m_skew){
			m_angle = params.begin()->getRobotAngle();
			m_prevError = m_angle;
		}
		else{
			m_angle = params.begin()->getTargetAngle().getDegrees();
			m_prevError = m_angle;
		}
		RotateToAngleGyroCommand::Initialize();
	}
	void Execute(){
		RotateToAngleGyroCommand::Execute();
	}
	bool IsFinished(){
		return RotateToAngleGyroCommand::IsFinished();
	}
	void End(){
		RotateToAngleGyroCommand::End();
	}
	void Interrupted(){
		End();
	}
};
#endif  // RotateToAngleGyroCommand_H
