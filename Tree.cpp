#include <cassert>
#include <iostream>

#include "Tree.hpp"

using namespace std; 

Tree::Tree() : root(nullptr) {
    cout << "\t\t\t\tConstructor Tree() called" << endl; 
} 

Tree::~Tree() {
    cout << "\t\t\t\tDestructor Tree() called" << endl; 
}

Node* Tree::getRoot() const {
    return root; 
}  

void Tree::insertChild(Node *parent, Node *child) {
    if (parent == nullptr) {
        cout << "'Tree::insertChild'   inserting child as new root" << endl; 
        root = child;
    } else if (parent->getFirstChild() == nullptr) {
        // add child as firstChild
        cout << "\t\t\t\t'Tree::insertChild'   inserting child as 'firstChild'" << endl; 
        cout << "parent.value = ";
        parent->print(cout);
        cout << "   child.value = ";
        child->print(cout);
        cout << endl;     
        parent->setFirstChild(child);
    } else  {
        // find last node in list 
        cout << "\t\t\t\t'Tree::insertChild'   inserting child at end of list of nextSiblings()" << endl; 
        Node* sibling = parent->getFirstChild(); 
        cout << "sibling.value = ";
        sibling->print(cout);
        cout << endl;     
        while (sibling->getNextSibling() != nullptr) {
            sibling = sibling->getNextSibling();
        }
        // append child node
        cout << "adding child to sibling.value = ";
        sibling->print(cout);
        cout << "    child.value = ";
        child->print(cout);
        cout << endl; 
        sibling->setNextSibling(child);
    } 
}

void Tree::deleteSubTree(Node *node) {
    cout << "\t\t\t\tdeleteSubTree NOT implemented - exiting!" << endl; 
    exit(1); 
}

int Tree::getNodeCount() const {
    int cnt = 0; 
    return cnt; 
}

void Tree::Clear() {
    // just set the root node to nullptr, nodes have to be cleaned up somewhere else
    root = nullptr; 
}

void Tree::DeleteElements() {
    // delete the whole tree and free the memory
}

void Tree::printRecursive(Node *n, int depth, std::ostream &os) const {
    Node *sibling;
    Node *child; 
    child = n; 
    while (child != nullptr) {
        // os << "depth: " << depth << std::string(depth * 2, ' ');
        sibling = child;
        os << std::string(depth * 2, ' ');
        sibling->print(os);
        sibling = sibling->getNextSibling();
        while (sibling != nullptr) {
            os << " | ";
            sibling->print(os);
            os << " | ";
            if (sibling->getFirstChild() != nullptr) {
                 printRecursive(sibling->getFirstChild(), depth + 1, os);
            }
            sibling = sibling->getNextSibling();
        }
        os << endl; 
        child = child->getFirstChild(); 
    }
}

void Tree::print(std::ostream &os) const {
    printRecursive(root, 1, os);
    // os << "print from tree" << endl; 
    // root->print(os);
}

std::ostream & operator << (std::ostream &os, const Tree &t) {
    // t.print(os);
    // os << "<< operator for tree called " << endl << flush; 
    t.print(os);
    return os; 
}
