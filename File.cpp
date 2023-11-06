#include "File.hpp"

File::File(const path& path) : FakeFilesystemComponent(path), size(file_size(path)){}
File::File(const FakeFilesystemComponent& component) : FakeFilesystemComponent(component.GetObjPath()), size(234) {}


// mak this cnstr deal with rand filesize later :)
File::File(const std::string& name, int fileSize) : FakeFilesystemComponent(name), size(fileSize) {}

std::ostream& operator<<(std::ostream& os, const File& file) {
    return os;
}

std::istream& operator>>(std::istream& is, File& file) {
    return is;
}

int File::GetSize() const {
    return size;
}

std::string File::listContent() const {
    return "Filename: " + GetName() + " FileSize: " + std::to_string(GetSize());
}

bool File::isDirectory() const {
    return false;
}

string File::addFile(const string& fileName, int fileSize) {
    std::unique_ptr<File> subFile = std::make_unique<File>(fileName, fileSize);
    content[fileName] = std::move(subFile);
    return content[fileName]->GetName();
}
