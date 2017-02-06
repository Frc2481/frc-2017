#ifndef VISION_SERVER_H
#define VISION_SERVER_H

#include "AdbBridge.h"
#include <vector>

class VisionUpdateReceiver;
class VisionMessage;

class VisionServer {
protected	:
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
		VisionServer* m_visionServer;
	public:
		ServerThread(int fd, VisionServer* outer);
		~ServerThread();
		void send(VisionMessage* message);
		void handleMessage(VisionMessage* message, double timestamp);
		void* runServerThread();
		static void* runServerThreadWrapper(void* context);
	};

	VisionServer(char* port);
	~VisionServer();
	bool isConnected();
	void requestAppRestart();
	void restartAdb();
	void* get_in_addr(struct sockaddr *sa);

	void runAccepterThread();
	static void* runAccepterThreadWrapper(void* context);

	void addVisionUpdateReceiver(VisionUpdateReceiver* receiver);
	void removeVisionUpdateReceiver(VisionUpdateReceiver* receiver);
};

#endif
