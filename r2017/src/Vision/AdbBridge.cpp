/*
 * AdbBridge.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */
#include <stdio.h>
#include <sstream>
#include <Vision/AdbBridge.h>

AdbBridge::AdbBridge(const std::string &adbLocation)
	: m_binLocation(adbLocation) {
}

AdbBridge::~AdbBridge() {
}

void AdbBridge::start() {
	runCommand("start");
}

void AdbBridge::stop() {
	runCommand("kill-server");
}

void AdbBridge::restartAdb() {
	stop();
	start();
}

void AdbBridge::portForward(int localPort, int remotePort) {
	std::stringstream ss;
	ss << "forward tcp:" << localPort << " tcp:" << remotePort;
	runCommand(ss.str().c_str());
}

void AdbBridge::reversePortForward(int remotePort, int localPort) {
	std::stringstream ss;
	ss << "reverse tcp:" << remotePort << " tcp:" << localPort;
	runCommand(ss.str().c_str());
}

void AdbBridge::restartApp() {
    stop();
    start();
}

bool AdbBridge::runCommand(const std::string &args) {
	std::stringstream ss;
	ss << m_binLocation << " " << args;
	FILE* adbStream = popen(ss.str().c_str(), "r");
	if (adbStream == NULL) {
		printf("Run Command Failed: %d\t%s", ss.str().c_str(), errno);
		return false;
	}
	pclose(adbStream);
	return true;
}
