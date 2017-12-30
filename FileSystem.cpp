#include <iostream>

#include "FileSystem.hpp"

using namespace std; 

FileSystem::FileSystem() : Tree() {
    cout << "\t\t\t\tConstructor FileSystem() called." << " address of this = " << this << endl; 
}

FileSystem::~FileSystem() {
    cout << "\t\t\t\tDestructor ~FileSystem() called."  << " address of this = " << this << endl; 
}

void FileSystem::splitString(std::string s, std::vector<std::string>& splitted) const {
    size_t foundAtPos = 0; 
    if (s.substr(0, 1) == delim) {
        s = s.substr(1, s.length());
    }
    // cout << "splitting s = " << s << endl; 
    splitted.clear(); 
    foundAtPos = s.find(delim, 1);
    while (foundAtPos != string::npos) {
        // cout << "found substr = " << s.substr(0, foundAtPos) << endl; 
        splitted.push_back(s.substr(0, foundAtPos));
        s = s.substr(foundAtPos+1, s.length());

        // cout << "after substr ...  foundAtPos = " << foundAtPos << "  s = " << s << endl; 
        foundAtPos = s.find(delim);
    }
    splitted.push_back(s);
    
    // cout << endl << endl << "found string segments: " << endl;
    // for(auto const& subdir: splitted) {
    //     cout << "subdir: " << subdir << endl; 
    // }
    // cout << endl << endl <<  endl;
} 

Node* FileSystem::findNode(const std::string &path) const {

}

void FileSystem::touch(const std::string &path, const std::string &filename) {
    vector <std::string> subdirs; 
    splitString(path, subdirs);
    cout << "path " << path << " split into subdirs" <<endl;
    for(auto const& subdir: subdirs) {
        cout << "subdir: " << subdir << endl; 
    }
}

void FileSystem::mkdir(const std::string &path, const std::string &dirname) {

}

void FileSystem::rm(const std::string &path, const std::string &filename) {

}

void FileSystem::rmdir(const std::string &path, const std::string &dirname) {

}

void FileSystem::ls() const {

}