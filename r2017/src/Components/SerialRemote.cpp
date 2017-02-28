/*
 * SerialRemote.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: FIRSTMentor
 */

#include <Components/SerialRemote.h>

SerialRemote::SerialRemote() : m_serialPort(new SerialPort(115200, SerialPort::kMXP)) {
	m_serialPort->SetTimeout(1.0);
	m_serialPort->Reset();
}

SerialRemote::~SerialRemote() {
	// TODO Auto-generated destructor stub
}
void SerialRemote::SendSerialChar(char c){
	if(m_serialPort != 0){
		try{
			delete m_serialPort;
		}catch(std::exception& ex){

		}
		m_serialPort = 0;
	}
	m_serialPort = new SerialPort(115200, SerialPort::kMXP);
	m_serialPort->SetTimeout(1.0);
	m_serialPort->Write(&c,1);
	m_serialPort->Flush();
	m_serialPort->Reset();
}

 SerialRemote* SerialRemote::GetInstance(){
	 static SerialRemote* instance = NULL;
	 if(instance == NULL){
		 instance = new SerialRemote();
	 }
	 return instance;
 }
