#ifndef ADVANCED_PROGRAMMING_FAKEFILESYSTEMCOMPONENT_HPP
#define ADVANCED_PROGRAMMING_FAKEFILESYSTEMCOMPONENT_HPP

#include <string>
#include <iostream>
#include <filesystem>
#include <unordered_map>

using namespace std;
using namespace __fs::filesystem;

class FakeFilesystemComponent {
public:
    FakeFilesystemComponent(const path& itemPath);

    const std::string GetName() const;
    const std::string GetParent() const;
    const path GetObjPath() const;
    virtual int GetSize() const = 0;
    virtual string listContent() const = 0;
    virtual bool isDirectory() const = 0;
    std::unordered_map<std::string, std::unique_ptr<FakeFilesystemComponent>>& GetContent();
    bool setContent(const std::unordered_map<std::string, std::shared_ptr<FakeFilesystemComponent>>& newContent);


    virtual ~FakeFilesystemComponent() = default;

protected:
    string name;
    string parent;
    path objPath;
    int objDept;
    std::unordered_map<std::string, std::unique_ptr<FakeFilesystemComponent>> content;
};

#endif //ADVANCED_PROGRAMMING_FAKEFILESYSTEMCOMPONENT_HPP