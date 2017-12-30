#pragma once

#include <string>

#include "FSNode.hpp"

class File : public FSNode {
    private:
        std::string contents; 
         
    public: 
        explicit File(std::string name = "", std::string contents = "");        
        virtual ~File(); 

        virtual void print(std::ostream &os) const override; 
        
        virtual Node* clone() const override;
        
        friend std::ostream & operator << (std::ostream &os, const File &f);
};
