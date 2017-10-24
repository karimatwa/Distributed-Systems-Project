#include <netdb.h>
#include "socket.h"
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <errno.h>

Socket::Socket() {

}

Socket::~Socket() {
    close(sock);
}

bool Socket::initializeSocket(char *_myAddr=NULL, int _myPort = 0) {
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock < 0) {
        std::cerr << "Socket failed\n";
        return false;
    }

    myPort = _myPort;
    myAddr.sin_family = AF_INET;

    myAddr.sin_port = htons((int) myPort);
    myAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock, (const sockaddr *) &myAddr, sizeof(struct sockaddr_in)) != 0) {
        std::cerr << "Bind failed\n";
        return false;
    }

    return true;
}

int Socket::writeToSocket(char *message, sockaddr_in peerAddr) {

    // strlen(parameters) + 1 for the NULL character at the end
    int bytes_sent = sendto(sock, message, strlen(message) + 1, 0, (const sockaddr *) &peerAddr, sizeof(peerAddr));

    if (bytes_sent < 0) {
        std::cerr << "Sending failed\n";
        std::cerr << strerror(errno) << std::endl;
    }
    return bytes_sent;
}

int Socket::readFromSocketWithBlock(char *message, size_t message_size, sockaddr_in &peerAddr) {

    peerAddr.sin_family = AF_INET;

    socklen_t slength = sizeof(struct sockaddr_in);
    int bytes_read = recvfrom(sock, message, message_size, 0, (sockaddr *) &peerAddr, &slength);

    if (bytes_read < 0) {
        std::cerr << "Receiving failed\n";
        std::cerr << strerror(errno) << std::endl;
    }

    return bytes_read;
}


int Socket::getMyPort() {
    return myPort;
}

int Socket::getSocketHandler() {
    return sock;
}
