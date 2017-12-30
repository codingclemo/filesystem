#pragma once

class Node {
    private:
        Node *firstChild, *nextSibling; 

    public: 
        explicit Node(Node *firstChild = nullptr, Node *nextSibling = nullptr);
        virtual ~Node(); 
        
        virtual Node* getFirstChild() const; 
        virtual Node* getNextSibling() const; 

        virtual void setFirstChild(Node *n);
        virtual void setNextSibling(Node *n);

        virtual void print(std::ostream &os) const = 0; 

        virtual Node* clone() const = 0; 
        
        // TODO REMOVE!!!
        Node* dumpPointers() const; 

        friend std::ostream & operator << (std::ostream &os, const Node &n);
};
