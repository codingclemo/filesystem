#include <iostream>

#include "Node.hpp"

using namespace std; 

Node::Node(Node *firstChild, Node *nextSibling) :
    firstChild(firstChild), nextSibling(nextSibling) {
    cout << "\t\tconstructor Node called " << endl; 
}

Node::~Node() {
    cout << "\t\tDestructor ~Node called" << endl; 
} 
        
Node* Node::getFirstChild() const {
    return firstChild;
} 

Node* Node::getNextSibling() const {
    return nextSibling;
} 

void Node::setFirstChild(Node *o) {
    firstChild = o;
}

void Node::setNextSibling(Node *o) {
    nextSibling = o; 
}
