#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <TCPClient.hpp>

class TCPServer {
private:
    int serverSocket;
    sockaddr_in serverAddress;

public:
    TCPServer(int port);
    void startListening();
    void handleClient(const TCPClient& client);
    ~TCPServer();
};

#endif // TCPSERVER_H
