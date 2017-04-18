/*
 * AutoDriveCommand.h
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_AUTODRIVECOMMAND_H_
#define SRC_COMMANDS_AUTODRIVECOMMAND_H_

class AutoDriveCommand : public CommandBase {
private:
	double m_X;
	double m_Y;
	double m_Twist;
	bool m_TimeoutSet;

public:
	AutoDriveCommand(double x, double y, double twist, double timeout = 0)
		: m_X(x), m_Y(y), m_Twist(twist) {
		Requires(m_driveTrain.get());

		if (timeout > 0){
					SetTimeout(timeout);
					m_TimeoutSet = true;
				}
				else {
					m_TimeoutSet = false;
				}
	}

	void Initialize(){}
	void Execute(){
		CommandBase::m_driveTrain->Drive(m_X, m_Y, m_Twist);
	}

	bool IsFinished(){
		return IsTimedOut() || !m_TimeoutSet;
	}

	void End(){
		if (m_TimeoutSet){
			CommandBase::m_driveTrain->Stop();
		}
	}

	void Interrupted(){
		End();
	}
};


#endif /* SRC_COMMANDS_AUTODRIVECOMMAND_H_ */
