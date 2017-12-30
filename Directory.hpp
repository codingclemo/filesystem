#pragma once

#include <string>

#include "FSNode.hpp"

class Directory : public FSNode {
    public: 
        explicit Directory(std::string name = "");        
        virtual ~Directory(); 

        virtual void print(std::ostream &os) const override; 

        virtual Node* clone() const override; 

        friend std::ostream & operator << (std::ostream &os, const Directory &d);
};
