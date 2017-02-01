#pragma once
#include "util/Rotation2D.h"

class ShooterAimingParameters /*:public Subsystems*/{
private:
	double m_range;
	Rotation2D m_turretAngle;
	int m_trackID;
public:
	ShooterAimingParameters(double range, Rotation2D turretAngle, int trackID);
	double getRange();
	Rotation2D getTurretAngle();
	int getTrackID();
};