#ifndef ADVANCED_PROGRAMMING_FILE_HPP
#define ADVANCED_PROGRAMMING_FILE_HPP

#include <string>
#include <iostream>
#include <filesystem>

#include "FakeFilesystemComponent.hpp"

using namespace std;
using namespace __fs::filesystem;

class File : public FakeFilesystemComponent{
public:
    explicit File(const path& path);
    File(const FakeFilesystemComponent& component);


    File(const std::string& name, int fileSize);

    friend std::ostream& operator<<(std::ostream& os, const File& file);
    friend std::istream& operator>>(std::istream& is, File& file);

    int GetSize() const override;
    string listContent() const override;
    bool isDirectory() const override;
    string addFile(const string& fileName, int fileSize);

private:
    int size;
};

#endif // ADVANCED_PROGRAMMING_FILE_HPP
