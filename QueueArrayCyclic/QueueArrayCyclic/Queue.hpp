//
//  Queue.hpp
//  QueueArrayCyclic
//
//  Created by zhozh on 05.04.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

template <class T>
class Queue
{
public:

    virtual Queue<T>& enQueue(const T& element) = 0;
    virtual Queue<T>& deQueue() = 0;
    virtual T& front() = 0;
    virtual bool isEmpty() const = 0;
    virtual size_t size() const = 0;
    virtual void show() const = 0;
    virtual ~Queue() {}

private:

    virtual void deleteQueue_() = 0;
};

#endif /* Queue_hpp */
