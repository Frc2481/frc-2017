#pragma once
#include "utils/Rotation2D.h"
#include "utils/RigidTransform2D.h"

class AimingParameters /*:public Subsystems*/{
private:
	RigidTransform2D m_transform;
	int m_trackID;
public:
	AimingParameters(RigidTransform2D targetTransform, int trackID);
	double getDistance();
	Rotation2D getAngle();
	int getTrackID();
};
