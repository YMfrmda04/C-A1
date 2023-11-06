#include "FakeFilesystemComponent.hpp"

FakeFilesystemComponent::FakeFilesystemComponent(const path& itemPath) : objPath(itemPath), name(itemPath.filename().string()) {
    //path parentPath = itemPath.parent_path();
    //parent = !parentPath.empty() ? parent = parentPath.stem().string() : "";

    // Get the parent path by removing the last element
    path parentPath = itemPath.parent_path();

    // Get the name between the last and second-to-last '/'
    if (!parentPath.empty()) {
        parent = parentPath.stem().string();
    } else {
        // If there is no parent path, set it to an empty string or handle it as needed
        parent = "";
    }

}

const std::string FakeFilesystemComponent::GetName() const {
    return name;
}

const std::string FakeFilesystemComponent::GetParent() const {
    return parent;
}

const path FakeFilesystemComponent::GetObjPath() const {
    return objPath;
}

std::unordered_map<std::string, std::unique_ptr<FakeFilesystemComponent>>& FakeFilesystemComponent::GetContent() {
    return content;
}

bool FakeFilesystemComponent::setContent(const std::unordered_map<std::string, std::shared_ptr<FakeFilesystemComponent>>& newContent) {
    content.clear();  // Clear the destination map

    for (const auto& item : newContent) {
        content[item.first] = std::move(std::unique_ptr<FakeFilesystemComponent>(item.second.get())); // or however you create a unique_ptr for your elements
    }

    return true;
}