#pragma once

#include <string>
#include <vector>

#include "Tree.hpp"

class FileSystem : public Tree {
    private:
        std::string name;
        std::string delim = "/"; 

        FSNode* findNode(const std::string &path) const; 

        void splitString(std::string s, std::vector<std::string>& splitted) const; 

        void showErrorMessage(const std::string &method, const std::string &msg, const std::string &path) const;

    public: 
        explicit FileSystem();
        
        virtual ~FileSystem(); 

        void touch(const std::string &path, const std::string &filename);
        void mkdir(const std::string &path, const std::string &dirname);
        void rm(const std::string &path, const std::string &filename);
        void rmdir(const std::string &path, const std::string &dirname);
        void ls() const;
        // virtual void print(std::ostream &os) const override; 
        // virtual Node* clone() const override; 

        // friend std::ostream & operator << (std::ostream &os, const FSNode &sn);
};
