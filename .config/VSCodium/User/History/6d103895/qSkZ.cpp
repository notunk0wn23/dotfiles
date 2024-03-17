#include <iostream>

#include <tcp.hpp>


int main() {

    TCPServer server;
    server.bindSocket();
    server.listenSocket();

    while (true) {
        TCPClient client;
        client.receiveData();
        client.sendData("Hello, world!");
        client.closeSocket();
    }

    return 0;
}
