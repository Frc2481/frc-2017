/*
 * AdbBridge.h
 *
 *  Created on: Jan 20, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_VISION_ADBBRIDGE_H_
#define SRC_VISION_ADBBRIDGE_H_

#include <string>

class AdbBridge {
public:
	AdbBridge(const std::string &adbLocation);
	virtual ~AdbBridge();
	void start();
	void stop();
	void restartAdb();
	void portForward(int localPort, int remotePort);
	void reversePortForward(int remotePort, int localPort);
	void restartApp();
private:
	bool runCommand(const std::string &args);
	std::string m_binLocation;
};

#endif /* SRC_VISION_ADBBRIDGE_H_ */
