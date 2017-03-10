#ifndef DriveTrainSetOriginCommand_H
#define DriveTrainSetOriginCommand_H

#include "../CommandBase.h"
#include "Commands/InstantCommand.h"

class DriveTrainSetOriginCommand : public InstantCommand {
private:
	double m_x;
	double m_y;
public:
	DriveTrainSetOriginCommand(double x, double y) : InstantCommand("DriveTrainSetOriginCommand"){
		m_x = x;
		m_y = y;
	}
	void Initialize(){
		CommandBase::m_driveTrain->SetOrigin(m_x, m_y);
	}
};

#endif  // DriveTrainSetOriginCommand_H
