#include "TCPServer.hpp"

int main() {
    TCPServer server(8080);
    server.startListening();
    return 0;
}
