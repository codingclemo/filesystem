#include <iostream>

#include "Node.hpp"

using namespace std; 

Node::Node(Node *firstChild, Node *nextSibling) :
    firstChild(firstChild), nextSibling(nextSibling) {
    cout << "\t\t\t\tconstructor Node called " << endl; 
}

Node::~Node() {
    cout << "\t\t\t\tDestructor ~Node called" << endl; 
} 
        
Node* Node::getFirstChild() const {
    return firstChild;
} 

Node* Node::getNextSibling() const {
    return nextSibling;
} 

void Node::setFirstChild(Node *n) {
    firstChild = n;
}

void Node::setNextSibling(Node *n) {
    nextSibling = n; 
}

// std::ostream & operator << (std::ostream &os, const Node &n) {
//     cout << "<< operator for Node called" << endl; 
//     n.print(os);
//     return os; 
// }
