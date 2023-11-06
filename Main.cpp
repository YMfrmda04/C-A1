#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <utility>

class UniqueOrderedData {
private:
    std::vector<std::pair<std::string, int>> data;
    std::set<std::string> keys;

public:
    // Add a pair to the data structure if the key is not a duplicate
    bool addPair(const std::string& key, int value) {
        if (keys.find(key) == keys.end()) {
            data.push_back(std::make_pair(key, value));
            keys.insert(key);
            return true;
        }
        return false; // Key is a duplicate, not added
    }

    // Print the data in the order it was inserted
    void printData() {
        for (const auto& pair : data) {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
    }
};

int main() {
    UniqueOrderedData myData;

    myData.addPair("FolderC", 0);
    myData.addPair("FolderA", 1);
    myData.addPair("FolderB", 2);
    myData.addPair("FolderA", 3); // This pair won't be added due to a duplicate key
    myData.addPair("FolderD", 4);

    myData.printData();

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include "exception"

// Custom struct to represent a file
struct File {
    std::string filename;
    size_t fileSize;

    File(const std::string& name, size_t size) : filename(name), fileSize(size) {}
};

// Function to find the index of a directory by name
int findDirectoryIndex(const std::vector<std::pair<std::string, std::vector<File>*>>& directoryStructure, const std::string& directoryName) {
    for (int i = 0; i < directoryStructure.size(); i++) {
        if (directoryStructure[i].first == directoryName) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

/*
int main() {
    // Use a pointer to a vector to store directories and their files
    std::vector<std::pair<std::string, std::vector<File>*> > directoryStructure;

    // Create directories and add files
    directoryStructure.emplace_back("FolderC", new std::vector<File>());
    directoryStructure.emplace_back("FolderA", new std::vector<File>());
    directoryStructure.emplace_back("FolderA", new std::vector<File>());

    directoryStructure[0].second->emplace_back("file1.txt", 23);
    directoryStructure[0].second->emplace_back("TED.txt", 23232);
    directoryStructure[1].second->emplace_back("file2.txt", 2048);
    directoryStructure[2].second->emplace_back("file3.txt", 1536);

    // Find the index of a directory by name
    std::string directoryToFind = "FolderC";
    int index = findDirectoryIndex(directoryStructure, directoryToFind);

    if (index != -1) {
        std::cout << "Index of directory " << directoryToFind << " is: " << index << std::endl;
    } else {
        std::cout << "Directory " << directoryToFind << " not found." << std::endl;
    }

    // Release the dynamically allocated vectors
    for (const auto& directory : directoryStructure) {
        delete directory.second;
    }

    return 0;
}


 
int main() {
    try {
        // ...

        Directory rootDir("root");
        rootDir.addFile("nknk", 924);



        Directory& subA = rootDir.addSubdirectory(rootDir.GetObjPath().string() +"/subA", 0); // Get a reference to sub A

        Directory& subB = subA.addSubdirectory(subA.GetObjPath().string() +"/subB", 0);

        auto& ace = rootDir.GetContent();


        FakeFileSystem ffs(&rootDir);
        ffs.Dir();
        ffs.changeDirectory("source");
        ffs.Dir();

        //cout << " " << endl;
        //cout <<  subB.GetObjPath() << endl;
        //cout <<  subB.GetName() << endl;
        //cout <<  subB.GetParent() << endl;


        //rootDir.removeFile("nknk");
        //auto a = rootDir.removeSubdirectory("sub A");


        // ...

        return 0;
    } catch (const std::runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

*/
