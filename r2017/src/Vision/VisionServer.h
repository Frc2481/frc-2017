#ifndef VISION_SERVER_H
#define VISION_SERVER_H

#include "AdbBridge.h"
#include <vector>

class VisionUpdateReceiver;
class VisionMessage;

class VisionServer {
private:
	bool mIsConnect = false;
	bool mWantsAppRestart = false;
	bool mRunning = true;
	int mPort;
	char* mPortStr;
	AdbBridge* m_adb;
	std::vector<VisionUpdateReceiver*> m_receivers;

	int m_sockfd;

public:
	class ServerThread
	{
	private:
		int commfd;
		std::vector<char>* recvBuf;
		std::vector<std::string> split(std::string &text, char sep);
	public:
		ServerThread(int fd);
		~ServerThread();
		void send(VisionMessage* message);
		void handleMessage(VisionMessage* message, double timestamp);
		void runServerThread();
		static void runServerThreadWrapper(void* context);
	};

	VisionServer(char* port);
	~VisionServer();
	bool isConnected();
	void requestAppRestart();
	void restartAdb();

	void runAccepterThread();
	static void runAccepterThreadWrapper(void* context);

	void addVisionUpdateReceiver(VisionUpdateReceiver* receiver);
	void removeVisionUpdateReceiver(VisionUpdateReceiver* receiver);
};

#endif
