#include "TCPClient.hpp"

TCPClient::TCPClient(int socket, sockaddr_in address, socklen_t addressSize) 
    : clientSocket(socket), clientAddress(address), clientAddressSize(addressSize) {}

int TCPClient::getClientSocket() const {
    return clientSocket;
}

sockaddr_in TCPClient::getClientAddress() const {
    return clientAddress;
}

socklen_t TCPClient::getClientAddressSize() const {
    return clientAddressSize;
}

void TCPClient::closeConnection() {
    // Close socket
    close(clientSocket);
}
