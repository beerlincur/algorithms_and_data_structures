//
//  QueueArray.hpp
//  Queue_Trees
//
//  Created by zhozh on 18.03.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef QueueArray_hpp
#define QueueArray_hpp

#include <stdio.h>
#include <iostream>
#include "Queue.hpp"
#include "QueueExceptions.hpp"

using std::cout;

// ===============================================================================
// Шаблон класса QueueArray - реализация структуры очереди через одномерный массив
//================================================================================

template <class T>
class QueueArray: public Queue<T>
{
public:
    
    QueueArray(int size = 100);
    QueueArray(const QueueArray<T>& src);
    virtual ~QueueArray() { delete[] array_; }
    
    void enQueue(const T& element);
    const T& deQueue();
    bool isEmpty() { return tail_ < head_; }
    int getSize() const { return size_; }
    T& peekFront() const { return array_[head_]; }
    void show() const;
    
private:
    T* array_;
    int head_ = 0;
    int tail_ = -1;
    int size_;
};

template <class T>
QueueArray<T>::QueueArray(int size)
{
    try {
        array_ = new T[size_ = size];
    }
    catch(...)
    {
        throw WrongQueueSize();
    }
    
    head_ = 0;
    tail_ = -1;
}

template <class T>
QueueArray<T>::QueueArray(const QueueArray<T>& src)
{
    try {
        array_ = new T[size_ = src.size_];
    }
    catch(...)
    {
        throw WrongQueueSize();
    }
    
    for (size_t i = 0; i < src.size_; i++)
    {
        array_[i] == src[i];
    }
    
    this->head_ = src.head_;
    this->tail_ = src.tail_;
}

template <class T>
void QueueArray<T>::enQueue(const T& element)
{
    if (tail_ + 1 == size_)
    {
        throw QueueOverflow();
    }
    
    array_[++tail_] = element;
    
}

template <class T>
const T& QueueArray<T>::deQueue()
{
    if (tail_ < head_)
    {
        throw QueueUnderflow();
    }
    
    return array_[head_++];
    
}

template <class T>
void QueueArray<T>::show() const
{
    for (size_t i = head_; i <= tail_; i++)
    {
        cout << array_[i] << " ";
    }
}


#endif /* QueueArray_hpp */
