#include <iostream>
#include <fstream>
#include <filesystem>
#include "headers/json.hpp"

using namespace std;
using namespace std::filesystem;

class Task {
    private:

    public:
        const string name;

        void get() {
            
        }

        Task(name) {
            if (!exists("./tasks")) {
                cerr << "Failed to create task: "
                return 1;
            }

            ofstream file(name + ".txt");

            if (file.is_open()) {
                file << "Task Name: " << taskName << "\n";
                file.close();
                std::cout << "File \"" << taskName << ".txt\" created successfully.\n";
            } else {
                std::cerr << "Error creating file \"" << taskName << ".txt\"\n";
            }
        };






};

void createTasksFolder() {
    if (!exists("./tasks")) {
        create_directory("./tasks");
    }
};

int main() 
{


};