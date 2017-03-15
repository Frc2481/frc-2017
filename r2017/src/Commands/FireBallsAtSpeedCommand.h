#ifndef FireBallsAtSpeedCommand_H
#define FireBallsAtSpeedCommand_H

#include "../CommandBase.h"

class FireBallsAtSpeedCommand : public CommandBase {
private:
	int m_loopCount;
public:
	FireBallsAtSpeedCommand() : CommandBase("FireBallsAtSpeedCommand"){
		m_loopCount = 0;
	}
	void Initialize(){
		m_loopCount = 0;
	}
	void Execute(){
		if(fabs(m_superStructure->GetSpeed() - m_superStructure->GetShooterSetpoint()) <= 1000){
			m_loopCount++;
			if(m_loopCount >= 10){
				m_superStructure->TurnLoaderOn();
				m_superStructure->StartFeeding();
			}
		}
		else{
			m_loopCount = 0;
			m_superStructure->TurnLoaderOff();
			m_superStructure->StopFeeding();
		}

	}
	bool IsFinished(){
		return false;
	}
	void End(){
		m_superStructure->TurnLoaderOff();
		m_superStructure->StopFeeding();
	}
	void Interrupted(){
		End();
	}
};

#endif  // FireBallsAtSpeedCommand_H
