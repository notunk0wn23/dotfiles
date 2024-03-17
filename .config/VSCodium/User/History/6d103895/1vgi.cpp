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
    server.startListening();

    std::cout << "Performing cleanup and exiting...\n";
    
    // Perform cleanup actions here
    server.closeConnection();

    // Exit the program gracefully
    std::exit(0);
}
