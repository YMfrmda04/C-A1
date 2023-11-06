#ifndef ADVANCED_PROGRAMMING_COMMANDLINEINTERFACE_HPP
#define ADVANCED_PROGRAMMING_COMMANDLINEINTERFACE_HPP

#include "FakeFileSystem.hpp"

class CommandLineInterface {
public:
    explicit CommandLineInterface(FakeFileSystem& fs);

    void start();

private:
    FakeFileSystem& fileSystem;
};

#endif //ADVANCED_PROGRAMMING_COMMANDLINEINTERFACE_HPP
