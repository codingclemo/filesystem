#pragma once

#include <string>

#include "Node.hpp"

class StringNode : public Node {
    private:
        std::string value; 

    public: 
        explicit StringNode(std::string value = "");
        virtual ~StringNode(); 

        virtual void print(std::ostream &os) const; 

        friend std::ostream & operator << (std::ostream &os, const StringNode &sn);
};
