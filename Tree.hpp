#pragma once

#include <iostream>

#include "Node.hpp"

class Tree {
    private: 
        int cntNodes; 

        void printRecursive(Node &n, int depth, std::ostream &os) const;
        void getNodeCountRecursive(Node &n, int &cnt) const;
        
    protected:
        Node *root; 

    public: 
        Tree(); 
        virtual ~Tree();
        virtual Node* getRoot() const;  
        virtual void insertChild(Node *parent, Node *child);
        virtual void deleteSubTree(Node *node);
        virtual int getNodeCount() const; 
        virtual void Clear();
        virtual void DeleteElements();
        virtual void print(std::ostream &os) const; 

        friend std::ostream & operator << (std::ostream &os, const Tree &t);
};
