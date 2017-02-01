#include "pch.h"
#include "TargetInfo.h"

TargetInfo::TargetInfo(double y, double z) {
	m_y = y;
	m_z = z;
}

double TargetInfo::getX() {
	return m_x;
}

double TargetInfo::getY() {
	return m_y;
}

double TargetInfo::getZ() {
	return m_z;
}