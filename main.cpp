#include <iostream>


#include "StringNode.hpp"
#include "Tree.hpp"

using namespace std; 

int main() {
    Tree *t = new Tree(); 

    StringNode *node1 = new StringNode("1");
    StringNode *node2 = new StringNode("2");
    StringNode *node3 = new StringNode("3");
    StringNode *node4 = new StringNode("4");
    StringNode *node5 = new StringNode("5");
    StringNode *node6 = new StringNode("6");
    StringNode *node7 = new StringNode("7");
    StringNode *node8 = new StringNode("8");
    StringNode *node9 = new StringNode("9");
    StringNode *node10 = new StringNode("10");

    StringNode *node11 = new StringNode("11");
    StringNode *node12 = new StringNode("12");
    StringNode *node13 = new StringNode("13");
    StringNode *node14 = new StringNode("14");
    
    t->insertChild(nullptr, node1);
    t->insertChild(node1, node2);
    t->insertChild(node1, node3);
    t->insertChild(node1, node4);
    
    t->insertChild(node2, node5);
    t->insertChild(node2, node6);

    t->insertChild(node3, node7);
    t->insertChild(node3, node8);
    t->insertChild(node3, node9);   
    t->insertChild(node3, node10);

    t->insertChild(node4, node11);
    t->insertChild(node4, node12);
    t->insertChild(node4, node13);   
    t->insertChild(node4, node14);
    
    cout << "Tree  : .... "<< endl << *t << endl << endl;  

    delete node10;
    delete node9;
    delete node8; 
    delete node7;
    delete node6;
    delete node5;
    delete node4; 
    delete node3;
    delete node2;
    delete node1;
    delete t; 

    return 0;     
}