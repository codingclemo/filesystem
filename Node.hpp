#pragma once

class Node {
    private:
        Node *firstChild, *nextSibling; 

    public: 
        explicit Node(Node *firstChild = nullptr, Node *nextSibling = nullptr);
        virtual ~Node(); 
        
        virtual Node* getFirstChild() const; 
        virtual Node* getNextSibling() const; 

        virtual void setFirstChild(Node *o);
        virtual void setNextSibling(Node *o);

        virtual void print(std::ostream &os) const = 0; 
};
