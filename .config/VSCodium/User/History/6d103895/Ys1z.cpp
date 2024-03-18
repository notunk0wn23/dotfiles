#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

class TCPServer {
private:

public:
    TCPServer() {
        // Create a socket
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            std::cerr << "Failed to create socket" << std::endl;
            return 1;
        }

        // Set up server address
        sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(8080); // Change port if needed

        // Bind socket to address
        if (bind(sockfd, (sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
            std::cerr << "Failed to bind socket" << std::endl;
            close(sockfd);
            return 1;
        }
    }
    ~TCPServer() {}

    void listen() {}

    void accept() {}

    void send() {}

    void receive() {}

    void close() {}

}

class Client {
private:
    sockaddr_in client_addr;
    socklen_t client_len;
    int client_sockfd;
public:

    Client() {
        this->client_len = sizeof(this->client_addr);
        this->client_sockfd = accept(sockfd, (sockaddr*)&client_addr, &client_len);
        if (client_sockfd == -1) {
            std::cerr << "Failed to accept connection" << std::endl;
            close(sockfd);
            return 1;
        }
    }
    ~Client() {
        close(this->client_sockfd);
    }
};



int main() {

  // Listen for incoming connections
  if (listen(sockfd, 1) == -1) {
    std::cerr << "Failed to listen on socket" << std::endl;
    close(sockfd);
    return 1;
  }

  std::cout << "Server listening on port 8080..." << std::endl;

  // Wait for a connection (this will block)
  sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  int client_sockfd = accept(sockfd, (sockaddr*)&client_addr, &client_len);
  if (client_sockfd == -1) {
    std::cerr << "Failed to accept connection" << std::endl;
    close(sockfd);
    return 1;
  }

  std::cout << "Client connected!" << std::endl;

  // We don't actually receive or send any data here
  // This is the simplest server possible

  // Close client socket and server socket
  close(client_sockfd);
  close(sockfd);

  return 0;
}
