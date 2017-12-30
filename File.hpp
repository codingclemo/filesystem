#pragma once

#include <string>

#include "FSNode.hpp"

class File : public FSNode {
    private:
        std::string contents; 
         
    public: 
        explicit File(std::string name = "", std::string contents = "");        
        virtual ~File(); 

        friend std::ostream & operator << (std::ostream &os, const File &f);
};
