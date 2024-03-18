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


    TCPServer server(8080);
    server.startListening();

    signal(SIGINT, void() {
        std::cout << "Caught SIGINT. Cleaning up.." << std::endl;

        server.closeConnection();


        // Set the flag to indicate that the program should terminate
        flag = 1;

        // Exit the program
        std::exit(0);
    });


    // Exit the program gracefully
    std::exit(0);
}
