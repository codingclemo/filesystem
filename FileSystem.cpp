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
    // cout << "\t\t\t\t\t'findNode'" << endl; 
    vector <string> subdirs; 
    splitString(path, subdirs);
    
    string currentDir; 
    string fullDir;

    // cout << "\t\t\t\t\tsubdirs.size = " << subdirs.size() << endl; 
    FSNode *currentNode = nullptr, *tmp = nullptr; 

    // cout << "\t\t\t\t\troot = " << root << "   *root = " << root << endl; 
    FSNode *root_as_fsnode = dynamic_cast<FSNode*>(root);

    if (root == nullptr) {
        showErrorMessage("?", "FileSystem is empty - can't find path", fullDir);
        return nullptr; 
    }

    if (subdirs.size() > 0) {
        currentNode = root_as_fsnode; 
        
        currentDir = subdirs[0];
        fullDir = "/" + currentDir; 
        subdirs.erase(subdirs.begin());

        string dummy = root_as_fsnode->getName(); 
        // cout << "\t\t\t\t\tdummy = " << dummy << "   root_as_fsnode->getName()  = " << root_as_fsnode->getName() << "  currentDir = "  << currentDir  << endl; 
        // cout << "\t\t\t\t\t root_as_fsnode->getName().length()  = " << root_as_fsnode->getName().length() << "  currentDir.length = "  << currentDir.length()  << endl; 
        if (root_as_fsnode->getName() != currentDir) {
            // showErrorMessage("?", "path not found in filesystem!", fullDir);
            return nullptr;
        }

        // cout << "\t\t\t\t\tcurrentDir = " << currentDir << endl; 
        
        // cout << endl << endl;
        while (!subdirs.empty()) {
            currentDir = subdirs[0];
            fullDir += "/" + currentDir;
            // cout << "\t\t\t\t\tsubdir = " << currentDir << endl; 
            subdirs.erase(subdirs.begin());

            // look up the currentNode 
            tmp = dynamic_cast<FSNode*>(currentNode->getFirstChild());
            // cout << "\t\t\t\t\ttmp->getName()  =  "<< tmp->getName() << "  currentDir = " << currentDir << endl; 
            if (tmp->getName() == currentDir) {
                currentNode = tmp; 
            } else {
                // is the subDir one of the siblings?
                tmp = dynamic_cast<FSNode*>(tmp->getNextSibling()); 
                while ((tmp != nullptr) && (tmp->getName() != currentDir)) {
                    // cout << "\t\t\t\t\t\tWHILE   tmp->getName()  =  "<< tmp->getName() << "  currentDir = " << currentDir << endl; 
                    tmp = dynamic_cast<FSNode*>(tmp->getNextSibling());
                }
                if (tmp == nullptr) {
                    showErrorMessage("?2", "path not found in filesystem!", fullDir);
                    return nullptr;
                }
                currentNode = tmp; 
            }
        }
    } else {
        return nullptr; 
    }
    // assert (currentNode != nullptr);
    return currentNode; 
}

void FileSystem::showErrorMessage(const string &method, const string &msg, const string &path) const {
    cout << "**********************************************************************************************" <<endl;
    cout << "ERROR in '" << method << "'   -  " << msg << "; path: " << path << endl;
    cout << "**********************************************************************************************" <<endl;
}

bool FileSystem::removeNode(FSNode *parent, const std::string &name) {
    FSNode *prev, *n; 
    Node *deleteMe; 

    // cout << "\t\t\t\t\t\t'removeNode'    parent = " << *parent << "   search node with name = " << name << endl; 
    
    FSNode *parent_first_child_as_fsnode = dynamic_cast<FSNode*> (parent->getFirstChild());

    // is the node the "firstChild" ? -> adjust all relevant pointers
    if ((parent_first_child_as_fsnode != nullptr) && (parent_first_child_as_fsnode->getName() == name) ){
        // that's the node we want to delete 
        // cout << "1111" << endl; 
        deleteMe = parent->getFirstChild();
        // the new firstChild of parent
        n = dynamic_cast<FSNode*> (deleteMe->getNextSibling());
        if (n != nullptr) {
            n->setFirstChild(deleteMe->getFirstChild());

            // set as new child from parent
            parent->setFirstChild(n);

            deleteMe->setNextSibling(nullptr);
            deleteMe->setFirstChild(nullptr);
            delete deleteMe;
            deleteMe = nullptr; 
            cntNodes--;
        } else {
            parent->setFirstChild(deleteMe->getFirstChild());
            deleteMe->setNextSibling(nullptr);
            deleteMe->setFirstChild(nullptr);
            delete deleteMe;
            deleteMe = nullptr; 
            cntNodes--;
        }
        
    } else {
        // cout << "22222" << endl; 
        n = parent_first_child_as_fsnode; 
        prev = n; 
        while ((n != nullptr) && (n->getName() != name)) {
            prev = n;
            n = dynamic_cast<FSNode*> (n->getNextSibling());
        }
        if (n == nullptr) {
            // cout << "removeNode - node not found" <<endl; 
            return false;
        } 
        // delete the node
        prev->setNextSibling(n->getNextSibling());
        delete n;
        cntNodes--;
    } 
    return true; 
}

void FileSystem::splitDirname(const std::string &path, std::string &parentDir, std::string &dirname) const {
    // cout << "\t\t\t\t\t'splitDir("<<path << ")"  << endl;
    vector <string> subdirs; 
    splitString(path, subdirs);

    parentDir = ""; 
    dirname = path; 

    if (subdirs.size() == 1) {
        return; 
    }
    while (subdirs.size() > 1) {
        parentDir += "/" + subdirs[0];
        subdirs.erase(subdirs.begin());
    }
    dirname = subdirs[0];
    // cout << "'\t\t\t\t\tsplitDir("<<path << ") returns:  parentDir = " << parentDir  << ", dirname = " << dirname <<  endl;
}

void FileSystem::touch(const string &path, const string &filename) {
    if (path == "") {
        showErrorMessage("mkdir", "Can't insert file in  non-existing base-dir  ''   !", path);
    } else {
        FSNode *n = findNode(path);
        if (n == nullptr) {
            showErrorMessage("touch", "Path not found!", path);
        } else {
            // cout << "'touch'  node found for path = " << path << " has contents n = " << *n << endl; 
            insertChild(n, new File(filename));
        }
    }
}

void FileSystem::mkdir(const string &path, const string &dirname) {
     if (path == "") {
        //  cout << "\t\t\t\t\tmkdir   dirname = "  <<dirname << endl; 
        insertChild(root, new Directory(dirname));
     } else {
         FSNode *n = findNode(path);
         if (n == nullptr) {
            showErrorMessage("mkdir", "Path not found!", path);
        } else {
            // cout << "'mkdir'  node found for path = " << path << " has contents n = " << *n << endl; 
            insertChild(n, new Directory(dirname));
        }
     }
}

void FileSystem::rm(const string &path, const string &filename) {
    FSNode *n = findNode(path);
    // cout << "'rm'  n = " << *n << endl; 
    if (n == nullptr) {
        showErrorMessage("rm", "Path not found!", path);
    } else {
        // cout << "'rm'  node found for path = " << path << " has contents n = " << *n << endl; 
        if (!removeNode(dynamic_cast<FSNode*> (n), filename)) {
            showErrorMessage("rm", "File not found!", path + "/" + filename);
        }
    }
}

void FileSystem::rmdir(const string &path, const string &dirname) {
    assert(path == "");

    string parentDir, name;
    splitDirname(dirname, parentDir, name);
    FSNode *parent = findNode(parentDir);
    FSNode *n = findNode(dirname);

    if (n == nullptr) {
        showErrorMessage("rmdir", "Path not found!", dirname);
    } else {
        // cout << "\t\t\t\t\tparentDir = " << parentDir << "   name =" << name << endl; 
        // cout << "\t\t\t\t\tparent = " << parent << "   *parent =" << *parent << endl;
        // cout << "\t\t\t\t\tn = " << n << "   *n =" << *n << endl; 
        if (parentDir == "") {
            if (root->getFirstChild() != nullptr) {
                showErrorMessage("rmdir", "Can't 'rmdir' directory, because it is not empty!", dirname);
            } else {
                delete root; 
                root = nullptr; 
                cntNodes--;
            }
        } else {
            // cout << "'rmdir'  node found for dirname = " << dirname << " has contents n = " << *n << endl; 

            if ((n->getFirstChild() != nullptr)) {
                showErrorMessage("rmdir", "Can't 'rmdir' directory, because it is not empty!", dirname);
            } else {
                // cout << "\t\t\t\t\t\trmdir  - removing node" <<endl;
                if (!removeNode(dynamic_cast<FSNode*> (parent), name)) {
                    showErrorMessage("rmdir", "Directory not found!", dirname);
                }
            }
        }
    }
}

void FileSystem::ls() const {
    cout << "FileSystem::ls() " << endl; 
    cout << "------------------------" << endl; 
    cout << *this << endl;
    cout << "------------------------" << endl; 
    // cout << endl << "root = " << *root << endl;
}