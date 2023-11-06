#include "CommandLineInterface.hpp"
#include <iostream>

CommandLineInterface::CommandLineInterface(FakeFileSystem& fs) : fileSystem(fs) {}

void CommandLineInterface::start() {
    std::string input;
    while (true) {
        std::cout << "Enter a command ('dir', 'cd name', 'sortsize', 'sortname', 'mkdir' 'exit'): ";
        std::getline(std::cin, input);


        if (input == "dir") {
            fileSystem.displayDirectory();
        } else if (input.substr(0, 3) == "cd ") {
            std::string newDir = input.substr(3);
            if (!fileSystem.changeDirectory(newDir)) {
                std::cout << "Invalid directory path. please enter directory path." << std::endl;
            }
        } else if (input == "sortsize") {
            //fileSystem.sortsize();
        } else if (input == "sortname") {
            //fileSystem.sortContentsByName();
        } else if(input.substr(0, 6) == "mkdir "){
            std::string newDir = input.substr(6);
            fileSystem.createDirectory(newDir);
        } else if(input.substr(0, 7) == "mkfile "){
            std::string newFile = input.substr(7);
            fileSystem.createFile(newFile);
        } else if(input.substr(0, 4) == "del ") {
            // del
        } else if (input == "exit") {
            break;
        }

        else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
}
