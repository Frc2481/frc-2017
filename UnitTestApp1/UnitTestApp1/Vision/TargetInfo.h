#pragma once

class TargetInfo {
private:
	double m_x = 1.0;
	double m_y;
	double m_z;
public:
	TargetInfo(double y, double z);
	double getX();
	double getY();
	double getZ();
};