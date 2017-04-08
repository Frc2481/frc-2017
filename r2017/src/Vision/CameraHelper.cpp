/*
 * CameraHelper.cpp
 *
 *  Created on: Apr 6, 2017
 *      Author: FIRSTMentor
 */

#include <Vision/CameraHelper.h>
#include <cmath>

CameraHelper::CameraHelper(double dfov, double w, double h)
	: m_dfov(dfov), m_width(w), m_height(h) {}

CameraHelper::~CameraHelper() {}

double CameraHelper::GetFocalLengthPixels() const{
	double d = hypot(m_width, m_height);
	return tan(M_PI_2 - (m_dfov/2)  * (M_PI/180.0)) * (d/2);
}

double CameraHelper::GetCenterColumn() const {
	return m_width / 2.0 -.5;
}

double CameraHelper::GetCenterRow() const {
	return m_height / 2.0 -.5;
}
