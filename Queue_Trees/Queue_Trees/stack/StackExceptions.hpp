//
//  StackExceptions.hpp
//  Queue_Trees
//
//  Created by zhozh on 19.03.2020.
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
    StackOverflow() : reason("Stack Overflow") {};
    
    const char* what() { return reason; }

private:
       const char* reason;  // ! const
};


class StackUnderflow : public exception
{

public:
    
    StackUnderflow() : reason("Stack Underflow") {};
    
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

#endif /* StackExceptions_hpp */
