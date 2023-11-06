#ifndef ADVANCED_PROGRAMMING_FAKEFILESYSTEM_HPP
#define ADVANCED_PROGRAMMING_FAKEFILESYSTEM_HPP

#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <exception>
#include <algorithm>

#include "Directory.hpp"
#include "FakeFilesystemComponent.hpp"

using namespace std;

class FakeFileSystem {
public:
    FakeFileSystem(Directory* rootPath);

    bool changeDirectoryLogic(std::string targetDirName);

    void displayDirectory();
    bool changeDirectory(std::string targetDirName);
    void sortContentsBySize();
    void sortContentsByName();
    void createDirectory(const std::string& dirName);
    void createFile(const std::string& fileName);

private:
    Directory *root;
    Directory *currentDirectory;
};


#endif //ADVANCED_PROGRAMMING_FAKEFILESYSTEM_HPP
