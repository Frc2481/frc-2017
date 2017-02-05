/*
 * LiftTarget.h
 *
 *  Created on: Feb 4, 2017
 *      Author: Team2481
 */

#ifndef SRC_VISION_LIFTTARGET_H_
#define SRC_VISION_LIFTTARGET_H_

#include "TargetInfo.h"
#include "utils/Rotation2d.h"

class LiftTarget : public TargetInfo {
public:
	LiftTarget();
	LiftTarget(TargetInfo& a, TargetInfo& b);
	virtual ~LiftTarget();
	const Rotation2D& GetSkew() const;

private:
	Rotation2D m_skew;
	//double m_skew;
};

#endif /* SRC_VISION_LIFTTARGET_H_ */
