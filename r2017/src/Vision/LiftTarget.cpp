/*
 * LiftTarget.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Team2481
 */

#include <Vision/LiftTarget.h>
#include <cmath>

LiftTarget::LiftTarget() : TargetInfo(0, 0){
	// TODO Auto-generated constructor stub

}

LiftTarget::LiftTarget(TargetInfo& a, TargetInfo& b)
	: TargetInfo(a, b), m_skew(b.getY() - a.getY(),b.getZ() - a.getZ(), false){
}

LiftTarget::~LiftTarget() {
	// TODO Auto-generated destructor stub
}

const Rotation2D& LiftTarget::GetSkew() const {
	return m_skew;
}
