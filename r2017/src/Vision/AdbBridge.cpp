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
    runCommand("shell am force-stop com.team254.cheezdroid \\; am start com.team254.cheezdroid/com.team254.cheezdroid.VisionTrackerActivity");
}

bool AdbBridge::runCommand(const std::string &args) {
	std::stringstream ss;
	ss << m_binLocation << " " << args;
	printf("%s %s", ss.str().c_str(), args.c_str());
	FILE* adbStream = popen(ss.str().c_str(), "r");
	if (adbStream == NULL) {
		printf("Run Command Failed: %d\t%s", errno, ss.str().c_str());
		return false;
	}
	pclose(adbStream);
	return true;
}
