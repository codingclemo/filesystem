#pragma once

#include <iostream>

#include "Node.hpp"

class Tree {
    private: 
        int cntNodes; 

        void printRecursive(Node &n, int depth, std::ostream &os) const;
        void getNodeCountRecursive(Node &n, int &cnt) const;
 
        void traverseRecursiveAndInsert(Tree &newTree, Node &oldTree, Node *parent);

    protected:
        Node *root; 

    public: 
        Tree(); 
        Tree(const Tree &t);  

        virtual ~Tree();

        virtual Node* getRoot() const;  
        virtual void insertChild(Node *parent, Node *child);
        virtual void deleteSubTree(Node *node);
        virtual int getNodeCount() const; 
        virtual void Clear();
        virtual void DeleteElements();
        virtual void print(std::ostream &os) const; 

        Tree& operator = (const Tree &t); 

        friend std::ostream & operator << (std::ostream &os, const Tree &t);
};
