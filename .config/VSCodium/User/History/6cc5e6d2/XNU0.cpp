#include <TCPServer.hpp>
#include <arpa/inet.h> // Add this include directive


TCPServer::TCPServer(int port) {
    // Create a socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating socket\n";
        return;
    }

    // Bind the socket to an IP address and port
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error binding socket\n";
        return;
    }
}

void TCPServer::startListening() {
    // Listen for incoming connections
    if (listen(serverSocket, SOMAXCONN) == -1) {
        std::cerr << "Error listening on socket\n";
        return;
    }

    std::cout << "Server started, listening on port " << ntohs(serverAddress.sin_port) << std::endl;

    // Accept incoming connections
    while (true) {
        sockaddr_in clientAddress;
        socklen_t clientAddressSize = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (sockaddr*)&clientAddress, &clientAddressSize);
        if (clientSocket == -1) {
            std::cerr << "Error accepting connection\n";
            return;
        }

        // Create a TCPClient object to store client data
        TCPClient newClient(clientSocket, clientAddress, clientAddressSize);

        // Handle the client (you can implement your logic here)
        handleClient(newClient);
    }
}
std::string TCPServer::receiveData(int clientSocket) {
    constexpr int bufferSize = 1024;
    char buffer[bufferSize];
    std::memset(buffer, 0, bufferSize); // Clear buffer

    // Receive data from client
    ssize_t bytesReceived = recv(clientSocket, buffer, bufferSize, 0);
    if (bytesReceived == -1) {
        std::cerr << "Error in receiving data from client" << std::endl;
        return "";
    }

    // Convert received data to string
    std::string receivedData(buffer);

    return receivedData;
}


void TCPServer::handleClient(const TCPClient& client) {
    // Print client address
    std::cout << "New connection from: " << inet_ntoa(client.getClientAddress().sin_addr) << std::endl;

    // Receive and log data sent by the user
    std::string receivedData = TCPServer::receiveData(client.getClientSocket());
    std::cout << "Data sent by the user: " << receivedData << std::endl;

    // Close client connection
    close(client.getClientSocket());
}

TCPServer::~TCPServer() {
    close(serverSocket);
}
