#include "Directory.hpp"


Directory::Directory(const path& name) : FakeFilesystemComponent(name){}
Directory::Directory(const FakeFilesystemComponent& component) : FakeFilesystemComponent(component.GetObjPath()) {}

std::ostream& operator<<(std::ostream& os, const Directory& directory) {
    return os;
}

std::istream& operator>>(std::istream& is, Directory& directory) {
    return is;
}

int Directory::GetSize() const {
    return size;
}

bool Directory::isDirectory() const {
    return true;
}

std::string Directory::listContent() const {
    return "Directory name: " + GetName() + " FileSize: " + std::to_string(GetSize());
}

string Directory::addFile(const path& filePath, int fileSize) {
    string fileName = filePath.filename();
    std::unique_ptr<File> subFile = std::make_unique<File>(filePath, fileSize);
    content[fileName] = std::move(subFile);
    return content[fileName]->GetName();
}

Directory& Directory::addSubdirectory(const path& dirPath) {
    string dirName = dirPath.filename();
    std::unique_ptr<Directory> subDir = std::make_unique<Directory>(dirPath);
    content[dirName] = std::move(subDir);

    return dynamic_cast<Directory&>(*content[dirName]);
}

bool Directory::removeFile(const std::string& fileName) {
    auto it = content.find(fileName);
    if (it != content.end()) {
        content.erase(it);
        return true;
    }
    return false;
}

bool Directory::removeSubdirectory(const std::string& dirName) {
    auto it = content.find(dirName);
    if (it != content.end()) {
        content.erase(it);
        return true;
    }
    return false;
}