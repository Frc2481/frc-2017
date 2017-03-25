/*
 * Compressor.h
 *
 *  Created on: Mar 24, 2017
 *      Author: Team2481
 */

#ifndef SRC_SUBSYSTEMS_AIRCOMPRESSOR_H_
#define SRC_SUBSYSTEMS_AIRCOMPRESSOR_H_

#include "WPILib.h"
#include "Commands/Subsystem.h"

class AirCompressor : public Subsystem {
public:
	AirCompressor();
	virtual ~AirCompressor();
	void Start();
	void Stop();
private:
	std::unique_ptr<Compressor> m_compressor;
};

#endif /* SRC_SUBSYSTEMS_AIRCOMPRESSOR_H_ */
