#include <iostream>

#include "Tree.hpp"

using namespace std; 

Tree::Tree() : root(nullptr) {
    cout << "Constructor Tree() called" << endl; 
} 

Tree::~Tree() {
    cout << "Destructor Tree() called" << endl; 
}

Node* Tree::getRoot() const {
    return root; 
}  

void Tree::insertChild(Node *parent, Node *child) {
    
}

void Tree::deleteSubTree(Node *node) {

}

int Tree::getNodeCount() const {
    int cnt = 0; 
    return cnt; 
}

void Tree::Clear() {
}

void Tree::DeleteElements() {

}

void Tree::print(std::ostream &os) const {

}
