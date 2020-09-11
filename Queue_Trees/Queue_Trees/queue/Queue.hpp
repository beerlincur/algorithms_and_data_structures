//
//  Queue.hpp
//  Queue_Trees
//
//  Created by zhozh on 18.03.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>


// =============================================================
// Шаблон класса Queue представляет понятие абстрактного очередь
//==============================================================

template <class T>
class Queue
{
public:
    
    virtual ~Queue() {};
    
    virtual void enQueue(const T& element) = 0;
    
    virtual const T& deQueue() = 0;
    
    virtual bool isEmpty() const = 0;
};

#endif /* Queue_hpp */
