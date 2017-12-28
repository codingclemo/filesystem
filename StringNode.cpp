#include <iostream>

#include "StringNode.hpp"

using namespace std; 

StringNode::StringNode(std::string value) : value(value), Node() {
    cout << "\t\t\t\tConstructor StringNode(" << value << ") called." << endl; 

}
StringNode::~StringNode() {
    cout << "\t\t\t\tDestructor StringNode(" << value << ") called." << endl; 
}

void StringNode::print(std::ostream &os) const {
    // cout << " print from StringNode called  "  << endl; 
    os << value;
}

// std::ostream & operator << (std::ostream &os, const StringNode &sn) {
//     cout << " << operator for StringNode called "  << endl; 
//     sn.print(os);
//     return os; 
// }
