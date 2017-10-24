#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include <netinet/in.h>

class Socket {
protected:
    int sock;
    sockaddr_in myAddr;
    int myPort;

public:

    Socket();

    bool initializeServer(char *_myAddr, int _myPort);
    bool initializeClient(char *_peerAddr, int _peerPort);

    int writeToSocket(char *message, sockaddr_in peerAddr);

    int readFromSocketWithBlock(char *message, size_t message_size, sockaddr_in &peerAddr);

    int getMyPort();

    int getSocketHandler();

    ~Socket();
};

#endif