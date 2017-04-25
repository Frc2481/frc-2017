#ifndef DriveTrainWaitForEncoderDistanceCommand_H
#define DriveTrainWaitForEncoderDistanceCommand_H

#include "../CommandBase.h"

class DriveTrainWaitForEncoderDistanceCommand : public CommandBase {
private:
	double m_distance;
	double m_loopCounter;
	bool m_onTarget;
public:
	DriveTrainWaitForEncoderDistanceCommand(double distance) : CommandBase("DriveTrainWaitForEncoderDistanceCommand"){
		m_distance = distance;
		m_onTarget = false;
	}
	void Initialize(){
//		printf("Initialize, WaitforEncoder\n");
		m_onTarget = false;
	}
	void Execute(){
//		printf("Execute, WaitforEncoder\n");
//		printf("Distance %f\n", CommandBase::m_driveTrain->GetDriveDistance());
		if(m_distance - CommandBase::m_driveTrain->GetDriveDistance() <= .3){
			m_onTarget = true;
		}
		else{
			m_onTarget = false;
		}
	}
	bool IsFinished(){
		return m_onTarget;
	}
	void End(){
//		printf("End, WaitforEncoder\n");
	}
	void Interrupted(){}
};

#endif  // DriveTrainWaitForEncoderDistanceCommand_H
