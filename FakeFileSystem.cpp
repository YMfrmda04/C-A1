#include "FakeFileSystem.hpp"

FakeFileSystem::FakeFileSystem(Directory* rootPath) : root(rootPath), currentDirectory(rootPath){
    for (const auto& entry : recursive_directory_iterator(current_path().parent_path())) {
        path relativePath = entry.path().lexically_relative(current_path().parent_path());
        path subPath = rootPath->GetName() / relativePath;

        if (entry.is_directory()) {
            rootPath->addSubdirectory(subPath);
        } else {
            rootPath->addFile(subPath, entry.file_size());
        }
    }
}

void FakeFileSystem::displayDirectory() {
    try {
        for (const auto &item: root->GetContent()) {
            path itemPath = item.second->GetObjPath().parent_path();

            if (itemPath == currentDirectory->GetObjPath()) {
                cout << item.second->listContent() << endl;
            }
        }
    } catch (exception e){
        cout << "\n" << e.what() << "\n" << endl;
    }
}

bool FakeFileSystem::changeDirectoryLogic(std::string targetDirName){
    auto it = root->GetContent().find(targetDirName);

    if (it != root->GetContent().end() && it->second->isDirectory()
        && (it->second->GetObjPath().parent_path() == currentDirectory->GetObjPath()
        || currentDirectory->GetObjPath().parent_path() == it->second->GetObjPath())) {
        currentDirectory = dynamic_cast<Directory *>(it->second.get());
        return true;
    } else {
        cout << "Directory not found: " << targetDirName << endl;
        return false;
    }
}

bool FakeFileSystem::changeDirectory(std::string targetDirName) {
    bool directoryChanged = false;
    if (currentDirectory->GetObjPath().parent_path() == root->GetName()
    && targetDirName == "..") {
        currentDirectory = root;
        directoryChanged = true;
    } else if(targetDirName == "..") {
        targetDirName = currentDirectory->GetObjPath().parent_path().filename();
        directoryChanged = changeDirectoryLogic(targetDirName);
        cout << directoryChanged << endl;
    } else {
        directoryChanged = changeDirectoryLogic(targetDirName);
    }
    return directoryChanged;
}

void FakeFileSystem::createDirectory(const std::string& dirName){
    path subPath = currentDirectory->GetObjPath() / path(dirName);
    root->addSubdirectory(path(subPath));
}


void FakeFileSystem::createFile(const std::string &fileName){
    // andom number for file sizeee......
    path subPath = currentDirectory->GetObjPath() / path(fileName);
    root->addFile(path(subPath), 0);
}




    // Replace the original content with the sorted content
    //currentDirectory->setContent(std::move(sortedContent));

