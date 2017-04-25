#ifndef LockIntakeCommand_H
#define LockIntakeCommand_H

#include "../CommandBase.h"

class LockIntakeCommand : public CommandBase {
private:
	double m_time;
public:
	LockIntakeCommand() : CommandBase("LockIntakeByCurrentCommand"){
	}
	void Initialize(){
		m_time = frc::GetFPGATime();
	}
	void Execute(){
		if(!(fabs(m_gearIntake->GetAppliedThrottle()) >= 0.2 && fabs(m_gearIntake->GetEncoderSpeed()) <= 20.0)){//m_gearIntake->GetPivotCurrent() < 4.0){
//			printf("ConditionsMetForLockOut\n");
			m_time = frc::GetFPGATime();
		}
		else{
//			printf("LockOutTimerStarted\n");
		}
		printf("DeltaTime %f\n", frc::GetFPGATime() - m_time);
		if(frc::GetFPGATime() - m_time >= .75 / 0.000001){
//			printf("LockedOut\n");
			m_time = 0;
			m_gearIntake->StopIntakePivot();
			m_gearIntake->LockGearIntake();
		}
	}
	bool IsFinished(){
		return false;
	}
	void End(){}
};

#endif  // LockIntakeByCurrentCommand_H
