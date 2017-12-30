#include <iostream>

#include "StringNode.hpp"
#include "Tree.hpp"

#include "Directory.hpp"
#include "File.hpp"

#include "FileSystem.hpp"

using namespace std; 

void testNodeCount() {
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
    t->insertChild(node11, node13);   
    t->insertChild(node8, node14);
    
    cout << "Tree  : .... "<< endl << *t << endl << endl;  

    int cnt = t->getNodeCount();
    if (cnt != 14) {
        cout << "Ohh no - getNodeCount() should be 14, but is " << cnt << endl;
    } else {
        cout << "getNodeCount() is correct!!!  cnt = " << cnt << endl;
    }
    cout << endl; 

    Tree *t1 = new Tree(); 
    cnt = t1->getNodeCount();
    if (cnt != 0) {
        cout << "Ohh no - getNodeCount() should be 0, but is " << cnt << endl;
    } else {
        cout << "getNodeCount() is correct!!!  cnt = " << cnt << endl;
    }
    cout << endl; 

    StringNode *node15 = new StringNode("15");    
    t1->insertChild(nullptr, node15);
    
    cnt = t1->getNodeCount();
    if (cnt != 1) {
        cout << "Ohh no - getNodeCount() should be 0, but is " << cnt << endl;
    } else {
        cout << "getNodeCount() is correct!!!  cnt = " << cnt << endl;
    }
    cout << endl; 

    
    delete node14;
    delete node13;
    delete node12; 
    delete node11;
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

}

void testPrintTree() {
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

    delete node14;
    delete node13;
    delete node12; 
    delete node11;
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
}


void testDeleteSubTree() {

    // 2 Nodes - delete one node after the other 
    Tree *t1 = new Tree(); 
    StringNode *node2 = new StringNode("2");
    StringNode *node3 = new StringNode("3");
    
    t1->insertChild(nullptr, node2);
    t1->insertChild(node2, node3);
    
    cout << "----------- test DeleteSubTree  with 2 Nodes -----------  "<< endl;  
    cout << "Tree with 2 nodes  : .... "<< endl << *t1 << endl << endl;  
    t1->deleteSubTree(node2);
    cout << "Tree after calling deleteSUbTree on node2   : .... "<< endl << *t1 << endl << endl;  
    // t1->deleteSubTree(node2);
    // cout << "Tree after calling deleteSUbTree on node2   : .... "<< endl << *t1 << endl << endl<< endl<< endl<< endl;  
    cout << "bla " << endl; 

    t1->DeleteElements();
    cout << "Tree after calling deleteElements()  : .... "<< endl << *t1 << endl << endl<< endl<< endl;
    delete t1;

    // 3 Nodes - delete whole subtree at once 
    Tree *t2 = new Tree(); 
    StringNode *node6 = new StringNode("6");
    StringNode *node7 = new StringNode("7");
    StringNode *node8 = new StringNode("8");
    
    t2->insertChild(nullptr, node6);
    t2->insertChild(node6, node7);
    t2->insertChild(node6, node8);
    
    cout << "----------- test DeleteSubTree  with 3 Nodes -----------  "<< endl;  
    cout << "Tree with 3 nodes  : .... "<< endl << *t2 << endl << endl;  
    t2->deleteSubTree(node6);
    cout << "Tree after calling deleteSUbTree on root node node6   : .... "<< endl << *t2 << endl << endl<< endl<< endl;
    
    t2->DeleteElements();
    cout << "Tree after calling deleteElements()  : .... "<< endl << *t2 << endl << endl<< endl<< endl;

    delete t2; 


    // 6 Nodes - 2 subtrees - delete each subtree seperatly 
    Tree *t3 = new Tree(); 
    StringNode *node10 = new StringNode("10");
    StringNode *node11 = new StringNode("11");
    StringNode *node12 = new StringNode("12");
    StringNode *node13 = new StringNode("13");
    StringNode *node14 = new StringNode("14");
    StringNode *node15 = new StringNode("15");
    
    t3->insertChild(nullptr, node10);
    t3->insertChild(node10, node11);
    t3->insertChild(node10, node12);
    t3->insertChild(node11, node13);
    t3->insertChild(node11, node14);
    t3->insertChild(node12, node15);
    
    cout << "----------- test DeleteSubTree  with 6 Nodes and 2 sub trees -----------  "<< endl;  
    cout << "Tree with 6 nodes  : .... "<< endl << *t3 << endl << endl;  
    t3->deleteSubTree(node11);
    cout << "Tree after calling deleteSUbTree on node11  : .... "<< endl << *t3 << endl << endl<< endl<< endl;
    t3->deleteSubTree(node12);
    cout << "Tree after calling deleteSUbTree on node12  : .... "<< endl << *t3 << endl << endl<< endl<< endl;
    t3->DeleteElements();
    cout << "Tree after calling deleteElements()  : .... "<< endl << *t3 << endl << endl<< endl<< endl;

    delete t3; 
}

void testTreeCopyConstructor1() {
    // 1 Node
    Tree *t1 = new Tree(); 
    StringNode *node2 = new StringNode("2");
    
    t1->insertChild(nullptr, node2);
    
    cout << "----------- testTreeCopyConstructor   with 1 Node -----------  "<< endl;  
    cout << "Tree t1 with 1 node  .... "<< endl << *t1 << endl << endl;  

    Tree* t1copy = new Tree(*t1);

    cout << "Tree t1copy .... "<< endl << *t1copy << endl << endl;  

    t1->DeleteElements();
    cout << "Tree t1 after calling t1->deleteElements()  : .... "<< endl << *t1 << endl;
    cout << "Tree t1copy after calling t1->deleteElements()  : .... "<< endl << *t1copy << endl;
    
    t1copy->DeleteElements();
    cout << "Tree t1 after calling t1copy->deleteElements()  : .... "<< endl << *t1 << endl;
    cout << "Tree t1copy after calling t1copy->deleteElements()  : .... "<< endl << *t1copy << endl << endl<< endl<< endl;
    

    cout << endl <<endl<< endl << "calling delete  t1 "<< endl;
    delete t1;
    cout <<  "calling delete  t1copy "<< endl;
    delete t1copy;

    t1 = nullptr; 
    t1copy = nullptr; 
}

void testTreeCopyConstructor2() {
    // 1 Node
    Tree *t1 = new Tree(); 
    StringNode *node2 = new StringNode("2");
    StringNode *node3 = new StringNode("3");
    
    t1->insertChild(nullptr, node2);
    t1->insertChild(node2, node3);
    
    cout << "----------- testTreeCopyConstructor2   with 2 Nodes -----------  "<< endl;  
    cout << "Tree t1 with 2 nodes  .... "<< endl << *t1 << endl << endl;  

    Tree* t1copy = new Tree(*t1);

    cout << "Tree t1copy .... "<< endl << *t1copy << endl << endl;  

    t1->DeleteElements();
    cout << "Tree t1 after calling t1->deleteElements()  : .... "<< endl << *t1 << endl;
    cout << "Tree t1copy after calling t1->deleteElements()  : .... "<< endl << *t1copy << endl;
    
    t1copy->DeleteElements();
    cout << "Tree t1 after calling t1copy->deleteElements()  : .... "<< endl << *t1 << endl;
    cout << "Tree t1copy after calling t1copy->deleteElements()  : .... "<< endl << *t1copy << endl << endl<< endl<< endl;

    cout << endl <<endl<< endl << "calling delete  t1 "<< endl;
    delete t1;
    cout <<  "calling delete  t1copy "<< endl;
    delete t1copy;

    t1 = nullptr; 
    t1copy = nullptr; 
}

void testTreeCopyConstructor6() {
    // 1 Node
    Tree *t1 = new Tree(); 
    StringNode *node10 = new StringNode("10");
    StringNode *node11 = new StringNode("11");
    StringNode *node12 = new StringNode("12");
    StringNode *node13 = new StringNode("13");
    StringNode *node14 = new StringNode("14");
    StringNode *node15 = new StringNode("15");
    
    t1->insertChild(nullptr, node10);
    t1->insertChild(node10, node11);
    t1->insertChild(node10, node12);
    t1->insertChild(node11, node13);
    t1->insertChild(node11, node14);
    t1->insertChild(node12, node15);
    
    cout << "----------- testTreeCopyConstructor6   with 6 Nodes -----------  "<< endl;  
    cout << "Tree t1 with 6 nodes  .... "<< endl << *t1 << endl << endl;  

    Tree* t1copy = new Tree(*t1);

    cout << "Tree t1copy .... "<< endl << *t1copy << endl << endl;  

    t1->DeleteElements();
    cout << "Tree t1 after calling t1->deleteElements()  : .... "<< endl << *t1 << endl;
    cout << "Tree t1copy after calling t1->deleteElements()  : .... "<< endl << *t1copy << endl;
    
    t1copy->DeleteElements();
    cout << "Tree t1 after calling t1copy->deleteElements()  : .... "<< endl << *t1 << endl;
    cout << "Tree t1copy after calling t1copy->deleteElements()  : .... "<< endl << *t1copy << endl << endl<< endl<< endl;

    cout << endl <<endl<< endl << "calling delete  t1 "<< endl;
    delete t1;
    cout <<  "calling delete  t1copy "<< endl;
    delete t1copy;

    t1 = nullptr; 
    t1copy = nullptr; 
}



void testTreeAssignment() {
    // 1 Node
    Tree *t1 = new Tree(); 
    StringNode *node10 = new StringNode("10");
    StringNode *node11 = new StringNode("11");
    StringNode *node12 = new StringNode("12");
    StringNode *node13 = new StringNode("13");
    StringNode *node14 = new StringNode("14");
    StringNode *node15 = new StringNode("15");
    
    t1->insertChild(nullptr, node10);
    t1->insertChild(node10, node11);
    t1->insertChild(node10, node12);
    t1->insertChild(node11, node13);
    t1->insertChild(node11, node14);
    t1->insertChild(node12, node15);
    
    cout << "----------- testTreeCopyConstructor6   with 6 Nodes -----------  "<< endl;  
    cout << "Tree t1 with 6 nodes  .... "<< endl << *t1 << endl << endl;  

    Tree* t1assign = new Tree();

    cout << "Tree t1assign .... "<< endl << *t1assign << endl << endl;  

    *t1assign = *t1; 
    
    cout << "Tree t1 after assignment *t1assign = *t1;  : .... "<< endl << *t1 << endl;
    cout << "Tree t1assing after assignment *t1assign = *t1;  : .... "<< endl << *t1assign << endl;
    cout << "------------------------------------------"<<endl;
    t1->DeleteElements();
    cout << "Tree t1 after t1->deleteElements();  : .... "<< endl << *t1 << endl;
    cout << "Tree t1assign after t1->deleteElements() : .... "<< endl << *t1assign << endl;

    cout << "------------------------------------------"<<endl;
    t1assign->DeleteElements();
    cout << "Tree t1 after t1assign->deleteElements();  : .... "<< endl << *t1 << endl;
    cout << "Tree t1assign after t1assign->deleteElements() : .... "<< endl << *t1assign << endl;

    cout << "------------------------------------------"<<endl;
    cout << endl <<endl<< endl << "calling delete  t1 "<< endl;
    delete t1;
    cout <<  "calling delete  t1assign "<< endl;
    delete t1assign;

    t1 = nullptr; 
    t1assign = nullptr; 
}

void testFileDirectory() {
    Directory *d = new Directory("root");
    cout << "directory = " << *d << endl; 

    File *f = new File("a.out");
    cout << "file = " << *f << endl; 
}

void testFileSystem() {
    FileSystem *fs = new FileSystem();

    fs->mkdir("", "root");
    fs->ls();
    cout << endl; 
    
    fs->touch("root", "ReadMe.txt");
    fs->ls();
    cout << endl; 

    fs->mkdir("root", "bin");
    fs->ls();
    cout << endl; 
    
    fs->touch("root/bin", "a.out");
    fs->touch("root/bin", "b.out");
    fs->ls();
    cout << endl; 

    fs->rm("root/bin", "a.out");
    fs->ls();
    cout << endl; 

    fs->rmdir("", "root");
    fs->ls();
    cout << endl <<endl<< endl <<endl<< endl <<endl; 

    fs->rm("root/bin", "b.out");
    fs->ls();
    cout << endl;

    fs->rmdir("", "root/bin");
    fs->ls();
    cout << endl;

    fs->rm("root", "ReadMe.txt");
    fs->ls();
    cout << endl;
    
    fs->rmdir("", "root");
    fs->ls();
    cout << endl; 

    // fs->DeleteElements();
    delete fs; 
}

int main() {
    // part 1
    // testNodeCount(); 
    testPrintTree();
    // testDeleteSubTree();

    // testTreeCopyConstructor1();
    // testTreeCopyConstructor2();
    // testTreeCopyConstructor6();

    // testTreeAssignment();


    // part 2
    // testFileDirectory(); 
    
    //  

    // FileSystem *fs = new FileSystem();
    // fs->mkdir("", "root");
    // fs->mkdir("root", "bin");
    // 
    // fs->touch("root/bin", "a.out");
    // fs->touch("root/bin", "b.out");
    // fs->ls();
    cout << endl; 
    // 
    // fs->rm("root/bin", "a.out");
    // fs->ls();
    // cout << endl; 


    // cout << endl <<endl<< endl << endl; 
    //  
    // fs->rmdir("", "/root/usr");
    // fs->ls();
    // cout << endl; 
    // 
    // cout << "callinh touch" << endl; 
    // fs->touch("roo3t/bin3/hallo3", "b.out");
    // cout << endl; 

    // fs->touch("/root4/bin4", "b.out");
    // cout << endl; 
    // 
    // fs->touch("/root5", "b.out");
    // cout << endl; 
    // 
    // fs->touch("/root5/bin5/hallo5", "b.out");
    // cout << endl; 

    // fs->touch("/root6/bin6/hallo6/", "b.out");
    // cout << endl; 

    // fs->DeleteElements();
    // delete fs; 

    // cout << endl << endl << endl << endl << endl << endl;
    // testFileSystem();   
    
    return 0;     
}
