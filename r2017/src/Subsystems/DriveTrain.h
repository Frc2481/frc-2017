#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <Components/SwerveModule.h>

class DriveTrain : public Subsystem {
private:


public:
	DriveTrain();
	void InitDefaultCommand();
};

#endif  // DriveTrain_H
