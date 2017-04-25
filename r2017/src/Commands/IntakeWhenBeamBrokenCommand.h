#ifndef IntakeWhenBeamBrokenCommand_H
#define IntakeWhenBeamBrokenCommand_H

#include "../CommandBase.h"
#include "Commands/IntakeFromHPAndSetToReadyCommandGroup.h"
#include "Commands/ClearBallsCommandGroup.h"
#include "Commands/HomeGearIntakeCommandGroup.h"

class IntakeWhenBeamBrokenCommand : public CommandBase {
private:
	CommandGroup* m_intakeCommand;
	CommandGroup* m_clearCommand;
	CommandGroup* m_stowCommand;
public:
	IntakeWhenBeamBrokenCommand() : CommandBase("IntakeWhenBeamBrokenCommand"){
		Requires(m_gearIntake.get());
		m_intakeCommand = new IntakeFromHPAndSetToReadyCommandGroup();
		m_clearCommand = new ClearBallsCommandGroup();
		m_stowCommand = new HomeGearIntakeCommandGroup();
	}
	void Initialize(){}
	void Execute(){
		if(m_gearIntake->IsHPBeamBroken() && m_gearIntake->GetHasGear() == false &&
				m_gearIntake->GetPivotPos() <= 50.0 && m_gearFlicker->IsOpen()){
			m_intakeCommand->Start();
		}
		else if(m_gearIntake->IsHPBeamBroken() && !m_gearFlicker->IsOpen() && m_gearIntake->GetPivotPos() <= 50.0
				&& !m_gearIntake->GetHasGear()){
//			printf("ClearCommand\n");
			m_clearCommand->Start();
		}
		else if(m_gearIntake->GetPivotPos() >= 50.0 && !m_gearIntake->GetHasGear()){
			m_stowCommand->Start();
		}
	}
	bool IsFinished(){
		return false;
	}
};

#endif  // IntakeWhenBeamBrokenCommand_H
