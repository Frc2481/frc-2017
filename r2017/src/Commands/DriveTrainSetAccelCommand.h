#ifndef DriveTrainSetAccelCommand_H
#define DriveTrainSetAccelCommand_H

#include "../CommandBase.h"

class DriveTrainSetAccelCommand : public InstantCommand {
private:
	double m_accel;
public:
	DriveTrainSetAccelCommand(double accel) : InstantCommand("DriveTrainSetAccelCommand"){
		m_accel = accel;
	}
	void Initialize(){
		CommandBase::m_driveTrain->SetMotionMagicAccel(m_accel);
	}
};

#endif  // DriveTrainSetAccelCommand_H
