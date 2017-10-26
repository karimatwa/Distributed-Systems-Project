#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include <netinet/in.h>

class Socket {
protected:
    sockaddr_in myAddr;  
	sockaddr_in peerAddr;  
	char * myAddress;
	char * peerAddress;
	int myPort;
	int peerPort;
    char message[1000];

public:

    Socket();

    bool initializeServer(char *_myAddr, int _myPort);

    bool initializeClient(char *_peerAddr, int _peerPort);

    int writeToSocket(char *message);

    int readFromSocket(char *message);

    int getMyPort();

    int getSocketHandler();

    ~Socket();
};

#endif