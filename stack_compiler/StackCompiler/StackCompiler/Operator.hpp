//
//  Operator.hpp
//  StackCompiler
//
//  Created by zhozh on 23.02.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef Operator_hpp
#define Operator_hpp

#include <stdio.h>
#include "StackExceptions.hpp"

class Operator
{
public:
    
    Operator ()
    {
        this->operation_ = ' ';
        this->priority_ = -1;
    }
    
    Operator (const char operation)
    {
        this->operation_ = operation;
        this->priority_ = ((operation == '(' || operation == ')') ? 0 : (operation == '+' || operation == '-') ? 1 : (operation == '*' || operation == '/') ? 2 : (operation == '^') ? 3 : -1);
        
        if (this->priority_ == -1)
        {
            throw WrongOperation();
        }
    }
    
    virtual ~Operator() {};
    
    int getPriority() const { return this->priority_; }
    char getOperation() const { return this->operation_; }
    
private:
    
    int priority_;
    char operation_;
};

#endif /* Operator_hpp */
