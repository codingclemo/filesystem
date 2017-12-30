#include <iostream>

#include "StringNode.hpp"

using namespace std; 

StringNode::StringNode(std::string value) : Node(), value(value) {
    // cout << "\t\t\t\tConstructor StringNode(" << value << ") called." << " address of this = " << this << endl; 
}

StringNode::StringNode(const StringNode &sn) : Node(), value(sn.value) {
    // cout << "\t\t\t\tCopy Constructor StringNode(" << sn.value << ") called."  << " address of this = " << this << endl; 
}

StringNode::~StringNode() {
    // cout << "\t\t\t\tDestructor ~StringNode(" << value << ") called."  << " address of this = " << this << endl; 
}

void StringNode::print(std::ostream &os) const {
    os << value;
}

std::ostream & operator << (std::ostream &os, const StringNode &sn) {
    sn.print(os);
    return os; 
}

Node* StringNode::clone() const {
    return new StringNode(*this);
} 
