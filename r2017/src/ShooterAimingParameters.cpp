#include "ShooterAimingParameters.h"

ShooterAimingParameters::ShooterAimingParameters(double range, Rotation2D turretAngle, int trackID) {
	m_range = range;
	m_turretAngle = turretAngle;
	m_trackID = trackID;
}

double ShooterAimingParameters::getRange() {
	return m_range;
}

Rotation2D ShooterAimingParameters::getTurretAngle() {
	return m_turretAngle;
}

int ShooterAimingParameters::getTrackID() {
	return m_trackID;
}
