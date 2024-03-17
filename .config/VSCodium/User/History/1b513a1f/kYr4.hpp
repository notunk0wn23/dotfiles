#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

class TCPClient {
private:
    int clientSocket;
    sockaddr_in clientAddress;
    socklen_t clientAddressSize;

public:
    TCPClient(int socket, sockaddr_in address, socklen_t addressSize);
    int getClientSocket() const;
    sockaddr_in getClientAddress() const;
    socklen_t getClientAddressSize() const;
    void closeConnection();
};

#endif // TCPCLIENT_H
