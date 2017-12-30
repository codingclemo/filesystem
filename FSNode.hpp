#pragma once

#include <string>

#include "Node.hpp"

class FSNode : public Node {
    private:
        std::string name; 

    public: 
        explicit FSNode(std::string name = "");
        FSNode(const FSNode &sn);
        
        virtual ~FSNode(); 

        virtual void print(std::ostream &os) const override; 
        virtual Node* clone() const override; 

        friend std::ostream & operator << (std::ostream &os, const FSNode &sn);
};
