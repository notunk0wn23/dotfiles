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

        Task(string name) {
            if (!exists("./tasks")) {
                cerr << "Failed to create task: ";
            }

            ofstream file(name + ".txt");

            if (file.is_open()) {
                file << "Task Name: " << name << "\n";
                file.close();
                std::cout << "File \"" << name << ".txt\" created successfully.\n";
            } else {
                std::cerr << "Error creating file \"" << name << ".txt\"\n";
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