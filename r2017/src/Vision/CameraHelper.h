/*
 * CameraHelper.h
 *
 *  Created on: Apr 6, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_VISION_CAMERAHELPER_H_
#define SRC_VISION_CAMERAHELPER_H_

class CameraHelper {
private:
	double m_dfov;
	double m_width;
	double m_height;

public:
	CameraHelper(double dfov, double w, double h);
	virtual ~CameraHelper();
	double GetFocalLengthPixels() const;
	double GetCenterColumn() const;
	double GetCenterRow() const;
};

#endif /* SRC_VISION_CAMERAHELPER_H_ */
