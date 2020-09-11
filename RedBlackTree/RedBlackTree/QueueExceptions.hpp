//
//  QueueExceptions.hpp
//  RedBlackTree
//
//  Created by zhozh on 25.04.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef QueueExceptions_hpp
#define QueueExceptions_hpp

#include <exception>

using std::exception;

class QueueOverflow: public exception // переполнение очереди
{
public:
    
    QueueOverflow() : reason("Queue overflow") {};
    
    const char* what() { return reason; }

private:
       const char* reason;  // ! const
};


class QueueUnderflow: public exception // недостаток элементов в очереди
{
public:
    
    QueueUnderflow() : reason("Queue underflow") {};
    
    const char* what() { return reason; }

private:
       const char* reason;  // ! const
};

#endif /* QueueExceptions_hpp */
