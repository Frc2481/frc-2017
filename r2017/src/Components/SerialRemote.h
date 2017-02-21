/*
 * SerialRemote.h
 *
 *  Created on: Feb 13, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMPONENTS_SERIALREMOTE_H_
#define SRC_COMPONENTS_SERIALREMOTE_H_
#include "WPILIb.h"
#include "IIOProvider.h"
#include <stdint.h>
#include "AHRSProtocol.h"
#include "IMUProtocol.h"
#include "IIOCompleteNotification.h"
#include "IBoardCapabilities.h"

class SerialRemote {
private:
	SerialPort *m_serialPort;

	SerialRemote();
public:

	virtual ~SerialRemote();
		void SendSerialChar(char c);
	static SerialRemote* GetInstance();

};

#endif /* SRC_COMPONENTS_SERIALREMOTE_H_ */
