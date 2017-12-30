#include <iostream>

#include "Directory.hpp"

using namespace std; 

Directory::Directory(std::string name) : FSNode(name) {
    // cout << "\t\t\t\tConstructor Directory(" << name << ") called." << " address of this = " << this << endl; 
}

Directory::~Directory() {
    // cout << "\t\t\t\tDestructor ~Directory(" << name << ") called."  << " address of this = " << this << endl; 
}

void Directory::print(std::ostream &os) const {
    os << name;
}

std::ostream & operator << (std::ostream &os, const Directory &d) {
    d.print(os);
    return os; 
}

Node* Directory::clone() const {
    return new Directory(*this);
} 
