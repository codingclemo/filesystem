#include <cassert>
#include <iostream>

#include "Tree.hpp"

using namespace std; 

Tree::Tree() : root(nullptr), cntNodes(0) {
    cout << "\t\t\t\tConstructor Tree() called" << endl; 
} 

void Tree::traverseRecursiveAndInsert(Tree &newTree, Node &oldTree, Node *newParent) {
    Node *oldSibling, *newSibling;
    Node *oldChild, *newChild; 

    newSibling = nullptr; 
    newChild = nullptr; 

    oldChild = &oldTree;
    while (oldChild != nullptr) {
        // cout << " in outer while" << endl;
        newChild = oldChild->clone();
        newTree.insertChild(newParent, newChild);
        
        oldSibling = oldChild;
        oldSibling = oldSibling->getNextSibling();

        while (oldSibling != nullptr) {
            // cout << " in inner while" << endl; 
            newSibling = oldSibling->clone();
            newTree.insertChild(newParent, newSibling);
            
            if (oldSibling->getFirstChild() != nullptr) {
                // cout << endl << endl << "rec call to 'traverseRecursiveAndInsert'" << endl;
                traverseRecursiveAndInsert(newTree, *(oldSibling->getFirstChild()), newSibling);
            }
            oldSibling = oldSibling->getNextSibling();
        }
        // cout << " after  inner while" << endl; 
        newParent = newChild; 
        oldChild = oldChild->getFirstChild(); 
    }
}

// cntNodes is adapted by calling "insertChild" in traverseRecursiveAndInsert
Tree::Tree(const Tree &t) : root(nullptr), cntNodes(0) {
    cout << "\t\t\t\tCopyConstructor Tree() called!" << endl; 
    traverseRecursiveAndInsert(*this, *(t.getRoot()), nullptr);

    // cout << "\t\t\t\tcopy constructed tree root = " << root << endl;
    assert(t.cntNodes == this->cntNodes);
}

Tree::~Tree() {
    cout << "\t\t\t\tDestructor Tree() called and " << cntNodes << " are still in the tree!" << endl; 
}

Node* Tree::getRoot() const {
    return root; 
}  

void Tree::insertChild(Node *parent, Node *child) {
    cntNodes++;
    if (parent == nullptr) {
        // cout << "'\t\t\t\tTree::insertChild'   inserting child as new root" << endl; 
        root = child;
    } else if (parent->getFirstChild() == nullptr) {
        // add child as firstChild
        // cout << "\t\t\t\t'Tree::insertChild'   inserting child as 'firstChild'" << endl; 
        // cout << "\t\t\t\tparent.value = " << *parent << "   child.value = " << *child << endl;     
        parent->setFirstChild(child);
    } else {
        // find last node in list 
        // cout << "\t\t\t\t'Tree::insertChild'   inserting child at end of list of nextSiblings()" << endl; 
        Node* sibling = parent->getFirstChild(); 
        // cout << "\t\t\t\tsibling.value = " << *sibling << endl;     
        while (sibling->getNextSibling() != nullptr) {
            sibling = sibling->getNextSibling();
        }
        // append child node
        // cout << "\t\t\t\tadding child to sibling.value = "<< *sibling<< "    child.value = "<< *child << endl; 
        sibling->setNextSibling(child);
    } 
    // cout << "\t\t\t\'insertChild'  called   cntNodes = " << cntNodes << endl; 
}

void Tree::deleteSubTree(Node *node) {
    Node *sibling;
    Node *child;
    Node *deleteMe; 
    child = node->getFirstChild(); 
    node->setFirstChild(nullptr);
    // if (node == root) {
    //     root = nullptr; 
    // }
    while (child != nullptr) {
        sibling = child;
        deleteMe = child; 

        // save the pointer to the firstChild
        child = child->getFirstChild();
        
        sibling = sibling->getNextSibling();
        delete deleteMe; 
        deleteMe = nullptr; 
        cntNodes--;
        while (sibling != nullptr) {
            if (sibling->getFirstChild() != nullptr) {
                deleteSubTree(sibling);
            }
            deleteMe = sibling; 
            sibling = sibling->getNextSibling();
            delete deleteMe; 
            deleteMe = nullptr; 
            cntNodes--;
        }         
    }
}

void Tree::getNodeCountRecursive(Node &n, int &cnt) const {
    Node *sibling;
    Node *child; 
    child = &n; 
    while (child != nullptr) {
        cnt++;
        sibling = child;
        sibling = sibling->getNextSibling();
        while (sibling != nullptr) {
            cnt++;
            if (sibling->getFirstChild() != nullptr) {
                getNodeCountRecursive(*(sibling->getFirstChild()), cnt);
            }
            sibling = sibling->getNextSibling();
        }
        child = child->getFirstChild(); 
    }
}

int Tree::getNodeCount() const {
    int cnt = 0; 
    getNodeCountRecursive(*root, cnt);
    return cnt; 
}

void Tree::Clear() {
    // just set the root node to nullptr, nodes have to be cleaned up somewhere else
    root = nullptr; 
}

void Tree::DeleteElements() {
    if (root != nullptr) {
        deleteSubTree(root);
        delete root; 
        cntNodes--;
        root = nullptr;
    } 
}

void Tree::printRecursive(Node &n, int depth, std::ostream &os) const {
    Node *sibling;
    Node *child; 
    child = &n; 
    //os << "first: " << *child <<endl;
    while (child != nullptr) {
        // os << "depth: " << depth << std::string(depth * 2, ' ');
        sibling = child;
        os << std::string(depth * 2, ' ') << *sibling;
        // sibling->print(os);
        sibling = sibling->getNextSibling();
        while (sibling != nullptr) {
            os << "  " << *sibling;
            // sibling->print(os);
            if (sibling->getFirstChild() != nullptr) {
                os << endl; 
                printRecursive(*(sibling->getFirstChild()), depth, os);
            }
            sibling = sibling->getNextSibling();
        }
        os << endl; 
        child = child->getFirstChild(); 
        depth += 2; 
    }
}

void Tree::print(std::ostream &os) const {
    // os << "print from tree" << endl; 
    // os << "root = " << root << endl; 
    printRecursive(*root, 1, os);
    // root->print(os);
}

Tree& Tree::operator = (const Tree &t) {
    cout << "\t\t\t\tAssignment Operator Tree = called!" <<  " with tree with cntNodes = " << cntNodes << endl; 
    if (this == &t) return *this;
    
    // delete the existing tree
    // cout << "\t\t\t\tAssignment Operator Tree =   calling DeletElements()" <<endl;
    DeleteElements();
    // cout << "\t\t\t\tAssignment Operator Tree =   calling traverseRecursiveAndInsert()" <<endl;
    traverseRecursiveAndInsert(*this, *(t.getRoot()), nullptr);

    assert(t.cntNodes == this->cntNodes);
    return *this; 
} 

std::ostream & operator << (std::ostream &os, const Tree &t) {
    // t.print(os);
    // os << "<< operator for tree called " << endl << flush; 
    t.print(os);
    return os; 
}
