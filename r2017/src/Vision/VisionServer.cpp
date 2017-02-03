#include "VisionServer.h"
#include "AdbBridge.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <pthread.h>
#include <vector>

#include "Messages/VisionMessage.h"
#include "Messages/OffwireMessage.h"
#include "Messages/HeartbeatMessage.h"
#include "VisionUpdate.h"

VisionServer::VisionServer(char* port)
{
	m_adb = new AdbBridge("/usr/bin/adb");
	mPort = atoi(port);
	mPortStr = port;
	m_sockfd = -1;

	int sockfd, rv;
	struct addrinfo hints, *servinfo, *p;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	if((rv = getaddrinfo(NULL, mPortStr, &hints, &servinfo)) != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return;
	}
	for(p=servinfo; p != NULL; p=p->ai_next)
	{
		if((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
		{
			continue;
		}
		if(setsockopt(sockfd, SOL_SOCKET, S_REUSEADDR, &yes, sizeof(int)) == -1)
		{
			continue;
		}
		if(bind(sockfd, p->ai_addr, p->ai_addrlen) == -1)
		{
			close(sockfd);
			continue;
		}
		break;
	}
	freeaddrinfo(servinfo);

	if(p == NULL)
	{
		//Server failed to bind, do something interesting
	}
	if(listen(sockfd, BACKLOG) == -1)
	{
		//Couldn't listen, do something interesting
		return;
	}
	pthread_t accepterThread;
	pthread_create(&accepterThread, NULL, &VisionServer::runAccepterThreadWrapper, &this);

	m_adb->start();
	m_adb->reversePortForward(*port, *port));
}

VisionServer::~VisionServer()
{
	delete m_adb;
}

bool VisionServer::isConnected()
{
	return mIsConnect;
}

void VisionServer::requestAppRestart()
{
	mWantsAppRestart = true;
}

void VisionServer::restartAdb()
{
	m_adb->restartAdb();
	m_adb->reversePortForward(mPort, mPort);
}

void VisionServer::runAccepterThread()
{
	struct sockaddr_storage their_addr;
	socklen_t sin_size = sizeof(their_addr);
	int new_fd;
	while(mRunning)
	{
		new_fd = accept(m_sockfd, (struct sockaddr *)&their_addr, &sin_size);
		if(new_fd == -1)
		{
			//Error accepting connection, do something interesting
			continue;
		}
		inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr *)&their_addr), s, sizeof(s));

		VisionServer::ServerThread *st = new VisionServer::ServerThread(new_fd);
		pthread_t pst;
		pthread_create(&pst, NULL, &VisionServer::ServerThread::runServerThreadWrapper, st);

		sleep(0.1);
	}
}

void VisionServer::runAccepterThreadWrapper(void* context)
{
	return ((VisionServer*)context)->runAccepterThread();
}

void VisionServer::addVisionUpdateReceiver(VisionUpdateReceiver* receiver)
{
	if(std::find(m_receivers.begin(), m_receivers.end(), receiver) == m_receivers.end())
	{
		m_receivers.push_back(receiver);
	}
}

void VisionServer::removeVisionUpdateReceiver(VisionUpdateReceiver* receiver)
{
	//Erase if exists
	//Note that the item being removed is a pointer and thus needs to be deleted before being removed
}

VisionServer::ServerThread::ServerThread(int fd)
{
	commfd = fd;
	recvBuf = new std::vector<char>();
}

VisionServer::ServerThread::~ServerThread()
{
	delete recvBuf;
}

void VisionServer::ServerThread::send(VisionMessage* message)
{
	const char* toSend = message->toJson();
	int numSent = 0;
	int bytesLeft = strlen(toSend);
	int n;
	if(commfd != 0)
	{
		while(remToSend > 0)
		{
			n = ::send(commfd, toSend+numSent, bytesLeft, 0);
			if(n == -1) { break; }
			numSent += n;
			bytesLeft -= n;
		}
	}
}

void VisionServer::ServerThread::handleMessage(VisionMessage* message, double timestamp)
{
	std::string mType = message->getType();
	if("targets" == mType)
	{
		VisionUpdate update = VisionUpdate::generateFromJsonString(timestamp, message->getMessage());
		//receivers.removeAll(null singleton);
		if(update.isValid()) {
			//for(
			//{
			//	receiver.gotUpdate(update);
			//}
		}
	}
	if("heartbeat" == mType)
	{
		send(&HeartbeatMessage());
	}
}

void VisionServer::ServerThread::runServerThread()
{
	if(commfd == 0)
	{
		return;
	}
	int bytesRead;
	std::string rcvStr;
	while(bytesRead = recv(commfd, recvBuf.data(), sizeof(recvBuf), 0))
	{
		if(bytesRead == -1)
		{
			//Error reading, do something interesting
		}
		else
		{
			rcvStr.append(recvBuf.cbegin(), recvBuf.cend());
			recvBuf.clear();
		}
		//Split string by \n and pass each into handleMessage
		//Not networking, fill in later
		std::vector<std::string> msgs = split(rcvStr, '\n');
		for(size_t i = 0; i < msgs.size(); i++)
		{
			OffWireMessage* parsedMessage = new OffWireMessage(msgs[i]);
			if(parsedMessage->isValid())
			{
				handleMessage(parsedMessage, 0);  //timestamp
			}
		}
	}
}

VisionServer::ServerThread::runServerThreadWrapper(void* context)
{
	return ((VisionServer::ServerThread*)context)->runServerThread();
}

std::vector<std::string> VisionServer::ServerThread::split(std::string &text, char sep)
{
	std::vector<std::string> tokens;
	std::size_t start = 0, end = 0;
	while((end = text.find(sep, start)) != std::string::npos) {
		tokens.push_back(text.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(text.substr(start));
	return tokens;
}
