#pragma once

class TargetInfo {
protected:
	double m_x = 1.0;
	double m_y;
	double m_z;
public:
	TargetInfo(double y, double z);
	TargetInfo(const TargetInfo &a, const TargetInfo &b);
	double getX();
	double getY();
	double getZ();
};
