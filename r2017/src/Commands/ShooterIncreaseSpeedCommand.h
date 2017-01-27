/*
 * ShooterIncreaseSpeedCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SHOOTERINCREASESPEEDCOMMAND_H_
#define SRC_COMMANDS_SHOOTERINCREASESPEEDCOMMAND_H_

class ShooterIncreaseSpeedCommand : public CommandBase{
public:
	ShooterIncreaseSpeedCommand() : CommandBase("Shooter Increase Speed Command") {
		Requires(m_shooter.get());
	}
	void Initialize(){
		m_shooter->SetShooterSetpoint(m_shooter->GetShooterSetpoint()+100);
	}

	void Execute() {

	}

	bool IsFinished(){
		return true;
	}

	void End() {

	}

	void Interrupted() {
		End();
	}
};


#endif /* SRC_COMMANDS_SHOOTERINCREASESPEEDCOMMAND_H_ */
