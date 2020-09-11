//
//  QueueExceptions.hpp
//  Queue_Trees
//
//  Created by zhozh on 18.03.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef QueueExceptions_hpp
#define QueueExceptions_hpp

#include <stdio.h>
#include <exception>

using std::exception;

// ==================================================
// Классы, реализующие интерфейс возможных исключений
// ==================================================

class QueueOverflow: public exception
{
public:
    
    QueueOverflow() : reason("Queue overflow") {};
    
    const char* what() { return reason; }

private:
       const char* reason;  // ! const
};


class QueueUnderflow: public exception
{
public:
    
    QueueUnderflow() : reason("Queue underflow") {};
    
    const char* what() { return reason; }

private:
       const char* reason;  // ! const
};


class WrongQueueSize: public exception
{
public:
    
    WrongQueueSize() : reason("Wrond queue size") {};
    
    const char* what() { return reason; }

private:
       const char* reason;  // ! const
};


#endif /* QueueExceptions_hpp */
