#include "AimingParameters.h"

AimingParameters::AimingParameters(RigidTransform2D targetTransform, int trackID) {
	m_transform = targetTransform;
	m_trackID = trackID;
}

double AimingParameters::getDistance() {
	return m_transform.getTranslation().norm();
}

Rotation2D AimingParameters::getAngle() {
	return m_transform.inverse().getRotation();
}

int AimingParameters::getTrackID() {
	return m_trackID;
}
