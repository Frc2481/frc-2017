/*
 * ShooterDecreaseSpeedCommand.h
 *
 *  Created on: Jan 21, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_SHOOTERDECREASESPEEDCOMMAND_H_
#define SRC_COMMANDS_SHOOTERDECREASESPEEDCOMMAND_H_

class ShooterDecreaseSpeedCommand : public CommandBase{
public:
	ShooterDecreaseSpeedCommand() : CommandBase("Shooter Decrease Speed Command"){
		Requires(m_shooter.get());
	}
	void Initialize(){
		m_shooter->SetShooterSetpoint(m_shooter->GetShooterSetpoint()-100);
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


#endif /* SRC_COMMANDS_SHOOTERDECREASESPEEDCOMMAND_H_ */
