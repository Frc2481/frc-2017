/*
 * SerialRemote.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: FIRSTMentor
 */

#include <Components/SerialRemote.h>

SerialRemote::SerialRemote() : m_serialPort(new SerialPort(115200, SerialPort::kUSB)) {

}

SerialRemote::~SerialRemote() {
	// TODO Auto-generated destructor stub
}
void SerialRemote::SendSerialChar(char c){
	const char str[] = {c};
	m_serialPort->Write(str);
}

 SerialRemote* SerialRemote::GetInstance(){
	 static SerialRemote* instance = NULL;
	 if(instance == NULL){
		 instance = new SerialRemote();
	 }
	 return instance;
 }
