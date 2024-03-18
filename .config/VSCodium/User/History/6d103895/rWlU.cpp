#include "TCPServer.hpp"
#include <iostream>
#include <csignal>
#include <cstdlib>

// Global flag to indicate whether the program should terminate
volatile sig_atomic_t flag = 0;

// Signal handler function
void signal_handler(int signum) {
    std::cout << "Interrupt signal (" << signum << ") received.\n";
    // Set the flag to indicate that the program should terminate
    flag = 1;
}

int main() {

    // Register signal handler for SIGINT
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        std::cerr << "Failed to register signal handler for SIGINT\n";
        return 1;
    }


    TCPServer server(8080);

    while (!flag) {
        // Continue listening for incoming connections
        server.startListening();
    }

    server.closeConnection();



    server.startListening();

    if (std::signal(SIGINT, [](int signum) {
        std::cout << "Caught SIGINT. Cleaning up.." << std::endl;

        server.closeConnection();
        // Additional cleanup actions can be performed here
        std::exit(signum); // Exit with the received signal number
    }) == SIG_ERR) {
        std::cerr << "Failed to register signal handler for SIGINT\n";
        return 1;
    }


    // Exit the program gracefully
    std::exit(0);
}
