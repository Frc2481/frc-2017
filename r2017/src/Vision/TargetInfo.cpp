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

TargetInfo::TargetInfo(const TargetInfo& a, const TargetInfo& b) {
	m_y = (a.m_y + b.m_y)/2.0;
	m_z = (a.m_z + b.m_z)/2.0;

}

double TargetInfo::getZ() {
	return m_z;
}
