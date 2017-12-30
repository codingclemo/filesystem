#include <cassert>
#include <iostream>

#include "Directory.hpp"
#include "File.hpp"
#include "FSNode.hpp"
#include "FileSystem.hpp"

using namespace std; 

FileSystem::FileSystem() : Tree() {
    cout << "\t\t\t\tConstructor FileSystem() called." << " address of this = " << this << endl; 
}

FileSystem::~FileSystem() {
    cout << "\t\t\t\tDestructor ~FileSystem() called."  << " address of this = " << this << endl; 
}

void FileSystem::splitString(string s, std::vector<string>& splitted) const {
    size_t foundAtPos = 0; 
    if (s.substr(0, 1) == delim) {
        s = s.substr(1, s.length());
    }
    // cout << "\t\t\t\t\tsplitting s = " << s << endl; 
    splitted.clear(); 
    foundAtPos = s.find(delim, 1);
    while (foundAtPos != string::npos) {
        // cout << "\t\t\t\t\tfound substr = " << s.substr(0, foundAtPos) << endl; 
        splitted.push_back(s.substr(0, foundAtPos));
        s = s.substr(foundAtPos+1, s.length());

        // cout << "\t\t\t\t\tafter substr ...  foundAtPos = " << foundAtPos << "  s = " << s << endl; 
        foundAtPos = s.find(delim);
    }
    splitted.push_back(s);
} 

FSNode* FileSystem::findNode(const string &path) const {
    cout << "\t\t\t\t\t'findNode'" << endl; 
    vector <string> subdirs; 
    splitString(path, subdirs);
    
    string currentDir; 
    string fullDir;

    cout << "\t\t\t\t\tsubdirs.size = " << subdirs.size() << endl; 
    FSNode *currentNode = nullptr, *tmp = nullptr; 

    cout << "\t\t\t\t\troot = " << root << "   *root = " << root << endl; 
    FSNode *root_as_fsnode = dynamic_cast<FSNode*>(root);

    if (root == nullptr) {
        showErrorMessage("?", "FileSystem is empty - can't find path", fullDir);
    }

    if (subdirs.size() > 0) {
        currentNode = root_as_fsnode; 
        
        currentDir = subdirs[0];
        fullDir = "/" + currentDir; 
        subdirs.erase(subdirs.begin());

        string dummy = root_as_fsnode->getName(); 
        cout << "dummy = " << dummy << endl; 
        if (root_as_fsnode->getName() != currentDir) {
        //     showErrorMessage("?", "path not found in filesystem!", fullDir);
        }

        // cout << "subdir = " << currentDir << endl; 
    //     while (!subdirs.empty()) {
    //         currentDir = subdirs[0];
    //         fullDir += "/" + currentDir;
    //         // cout << "subdir = " << currentDir << endl; 
    //         subdirs.erase(subdirs.begin());

    //         // look up the currentNode 
    //         tmp = dynamic_cast<FSNode*>(currentNode->getFirstChild());
    //         if (tmp->getName() == currentDir) {
    //             currentNode = tmp; 
    //         } else {
    //             // is the subDir one of the siblings?
    //             tmp = dynamic_cast<FSNode*>(currentNode->getNextSibling()); 
    //             while ((tmp != nullptr) && (tmp->getName() != currentDir)) {
    //                 tmp = dynamic_cast<FSNode*>(tmp->getNextSibling());
    //             }
    //             if (tmp == nullptr) {
    //                 showErrorMessage("?", "path not found in filesystem!", fullDir);
    //             }
    //             currentNode = tmp; 
    //         }
    //     }
    } else {
        return nullptr; 
    }
    // assert (currentNode != nullptr);
    return currentNode; 
}

void FileSystem::showErrorMessage(const string &method, const string &msg, const string &path) const {
    cout << "ERROR in '" << method << "'   -  " << msg << "; path: " << path << endl<< endl;
    cout << "ABORTING!" << endl; 
    exit(-1); 
}

void FileSystem::touch(const string &path, const string &filename) {
    Node *n; 

    n = findNode(path);
    if (n == nullptr) {
        showErrorMessage("touch", "FileSystem is empty!", path);
    } else {
        cout << "touch node found for path = " << path << " has contents n = " << n << endl; 
    }
}

void FileSystem::mkdir(const string &path, const string &dirname) {
     if (path == "") {
         cout << "\t\t\t\t\tmkdir   dirname = "  <<dirname << endl; 
        insertChild(root, new Directory(dirname));
     } else {
         cout << "\t\t\t\t\tNOT IMPLEMENTED" << endl; 
     }
}

void FileSystem::rm(const string &path, const string &filename) {

}

void FileSystem::rmdir(const string &path, const string &dirname) {

}

void FileSystem::ls() const {
    cout << "FileSystem::ls() " << endl; 
    cout << "------------------------" << endl; 
    cout << *this << endl;
    cout << "------------------------" << endl; 
    // cout << endl << "root = " << *root << endl;
}