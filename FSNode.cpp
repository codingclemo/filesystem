#include <iostream>

#include "FSNode.hpp"

using namespace std; 

FSNode::FSNode(std::string name) : Node(), name(name) {
    cout << "\t\t\t\tConstructor FSNode(" << name << ") called." << " address of this = " << this << endl; 
}

FSNode::FSNode(const FSNode &sn) : Node(), name(sn.name) {
    cout << "\t\t\t\tCopy Constructor FSNode(" << sn.name << ") called."  << " address of this = " << this << endl; 
}

FSNode::~FSNode() {
    cout << "\t\t\t\tDestructor ~FSNode(" << name << ") called."  << " address of this = " << this << endl; 
}

void FSNode::print(std::ostream &os) const {
    os << name;
}

std::ostream & operator << (std::ostream &os, const FSNode &sn) {
    sn.print(os);
    return os; 
}

// Node* FSNode::clone() const {
//     return new FSNode(*this);
// } 

std::string FSNode::getName() const {
    return "hallo"; 
}
