#include <iostream>

#include "File.hpp"

using namespace std; 

File::File(std::string name, std::string contents) : FSNode(name), contents(contents) {
    // cout << "\t\t\t\tConstructor File(" << name << ") called." << " address of this = " << this << endl; 
}

File::~File() {
    // cout << "\t\t\t\tDestructor ~File(" <<  name  << ") called."  << " address of this = " << this << endl; 
}

void File::print(std::ostream &os) const {
    os << name; // sollte hier nicht contents ausgegeben werden?
}

std::ostream & operator << (std::ostream &os, const File &f) {
    f.print(os);
    return os; 
}

Node* File::clone() const {
    return new File(*this);
} 
