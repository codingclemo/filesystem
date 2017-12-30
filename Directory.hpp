#pragma once

#include <string>

#include "FSNode.hpp"

class Directory : public FSNode {
    public: 
        explicit Directory(std::string name = "");        
        virtual ~Directory(); 

        friend std::ostream & operator << (std::ostream &os, const Directory &d);
};
