#ifndef VISION_SERVER_H
#define VISION_SERVER_H

#include "AdbBridge.h"
#include <vector>

class VisionUpdateReceiver;
class VisionMessage;

class VisionServer {
protected	:
	bool m_isConnect = false;
	bool m_wantsAppRestart = false;
	bool m_running = true;
	int m_port;
	char* m_portStr;
	AdbBridge* m_adb;
	std::vector<VisionUpdateReceiver*> m_receivers;

	int m_sockfd;

public:
	class ServerThread
	{
	private:
		int m_commfd;
		std::vector<char> m_recvBuf;
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
