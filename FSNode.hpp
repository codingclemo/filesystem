#pragma once

#include <string>

#include "Node.hpp"

class FSNode : public Node {
    protected:
        std::string name; 

    public: 
        explicit FSNode(std::string name = "");
        FSNode(const FSNode &sn);
        
        virtual ~FSNode(); 

        virtual void print(std::ostream &os) const = 0; 
        
        virtual std::string getName() const; 

        friend std::ostream & operator << (std::ostream &os, const FSNode &sn);
};
