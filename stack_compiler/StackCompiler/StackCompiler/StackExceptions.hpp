//
//  StackExceptions.hpp
//  StackCompiler
//
//  Created by zhozh on 20.02.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef StackExceptions_hpp
#define StackExceptions_hpp

#include <stdio.h>
#include <exception>


using std::exception;

//========================================================================
// Классы StackOverflow и StackUnderflow представляют две основные
// исключительные ситуации, которые могут возникнуть при работе со стеком
//========================================================================


class StackOverflow : public exception
{
public:
    StackOverflow() : reason("Stack Overflow. Might be besause of wrong operation in your excpression - it must contain only '+', '-', '*', '/', '^', '(' or ')'.") {};
    
    const char* what() { return reason; }

private:
       const char* reason;  // ! const
};


class StackUnderflow : public exception
{

public:
    
    StackUnderflow() : reason("Stack Underflow. Might be besause of wrong operation in your excpression - it must contain only '+', '-', '*', '/', '^', '(' or ')'.") {};
    
    const char* what() { return reason; }

private:
    const char* reason;  // ! const
};

//==============================================================
// Исключительная ситуация WrongStackSize может возникнyть,
// если в конструкторе стека неправильно задан размер.
//==============================================================

class WrongStackSize : public exception
{
public:
    WrongStackSize() : reason("Wrong Stack Size") {};
    const char* what() { return reason; }
    
private:
    
    const char* reason;  // ! const

};

class WrongStackType: public exception
{
public:

    WrongStackType() : reason("Wrong type of stack - must be 0 (with array) or 1 (with list)") {};
    const char* what() { return reason; }
    
private:
    
    const char* reason;
};

class WrongOperation: public exception
{
public:
    WrongOperation() : reason("Wrong operation was given - must be '+', '-', '*', '/', '^', '(' or ')'.") {};
    const char* what() { return reason; }

private:
    
    const char* reason;

};

class ZeroDivision: public exception
{
    
public:
    ZeroDivision() : reason("Division by zero!") {};
    const char* what() { return reason; }
    
private:
    
    const char* reason;
};

class WrongBracketBalance: public exception
{
public:
    WrongBracketBalance() : reason("Wrong brackets balance!") {};
    const char* what() { return reason; }
    
private:
    
    const char* reason;
};
#endif /* StackExceptions_hpp */
