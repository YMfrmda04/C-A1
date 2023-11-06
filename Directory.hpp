#ifndef ADVANCED_PROGRAMMING_Directory_HPP
#define ADVANCED_PROGRAMMING_Directory_HPP

#include <map>
#include "FakeFilesystemComponent.hpp"
#include "File.hpp"

using namespace std;

class Directory : public FakeFilesystemComponent{
public:
    Directory(const path& path);
    Directory(const FakeFilesystemComponent& component);


    friend std::ostream& operator<<(std::ostream& os, const Directory& directory);
    friend std::istream& operator>>(std::istream& is, Directory& directory);

    int GetSize() const override;
    string listContent() const override;
    bool isDirectory() const override;

    string addFile(const path& filePath, int fileSize);
    Directory& addSubdirectory(const path& dirName);

    bool removeFile(const std::string& fileName);
    bool removeSubdirectory(const std::string& dirName);

private:
    int size;
};

#endif // ADVANCED_PROGRAMMING_Directory_HPP
