#ifndef DriveToDistanceEncoderCommand_H
#define DriveToDistanceEncoderCommand_H

#include "../CommandBase.h"

class DriveToDistanceEncoderCommand : public CommandBase {
private:
	double m_distance;
public:
	DriveToDistanceEncoderCommand() : CommandBase("DriveToDistanceEncoderCommand"){
		Requires(m_driveTrain.get());
	}
	void Initialize(){
		double distance = SmartDashboard::GetNumber("Auto Gear Drive Distance",0.0);
		m_distance = m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(distance);
		m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
	}
	void Execute(){
		m_driveTrain->Drive(.5,0,0);
	}
	bool IsFinished(){
		//FIXME
		return fabs(m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition())
				>= m_distance;
	}
	void End(){
		m_driveTrain->Drive(0,0,0);
	}
	void Interrupted(){
		End();
	}
};

#endif  // DriveToDistanceEncoderCommand_H
