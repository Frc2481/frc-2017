/*
 * Compressor.cpp
 *
 *  Created on: Mar 24, 2017
 *      Author: Team2481
 */

#include <Subsystems/AirCompressor.h>

AirCompressor::AirCompressor() : Subsystem("AirCompressor") {
	m_compressor.reset(new Compressor());
	m_compressor->Start();
}

AirCompressor::~AirCompressor() {
	// TODO Auto-generated destructor stub
}

void AirCompressor::Start() {
	m_compressor->Start();
}

void AirCompressor::Stop() {
	m_compressor->Stop();
}
