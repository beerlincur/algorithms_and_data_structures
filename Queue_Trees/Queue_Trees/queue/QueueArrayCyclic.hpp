//
//  QueueArrayСyclic.hpp
//  Queue_Trees
//
//  Created by zhozh on 28.03.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef QueueArrayCyclic_hpp
#define QueueArrayCyclic_hpp

#include <stdio.h>
#include <iostream>
#include "Queue.hpp"
#include "QueueExceptions.hpp"

using std::cout;

//==============================================================
// Шаблон класса QueueArray - реализация круговой очереди.
// Элементы очереди помещаются в массив.
//==============================================================

template <class T>
class QueueArray: public Queue<T>
{
public:
    QueueArray(int size = 100); // size задает размер "по умолчанию"

    QueueArray(const QueueArray<T>& src);

    virtual ~QueueArray() { delete[] array_; }

    void enQueue(const T& element) override;

    const T& deQueue() override;

    bool isEmpty() const override { return head_ == tail_; }
    
    T& peekFront() const { return array_[head_]; }

    void show() const;
private:
    T* array_; // массив элементов очереди
    int head_ = 1; // Очередь пуста, если head[Q] = tail[Q].
    int tail_ = 1; // Первоначально: head[Q] = tail[Q] = 1;
    int size_; // размер очереди
};

template <class T>
QueueArray<T>::QueueArray(int size):
    size_(size)
{
    try
    {
        array_ = new T[size_ + 1]; // пытаемся заказать память под элементы стека...
    }
    catch (...)
    {                              // если что-то случилось (например, размер слишком большой
        throw WrongQueueSize();    // или отрицательный) - возникает искл.ситуация
    }
}

template <class T>
QueueArray<T>::QueueArray(const QueueArray<T>& src):
    head_(src.head_),
    tail_(src.tail_),
    size_(src.size_)
{
    try
    {
        array_ = new T[size_ + 1];
    }
    catch (...)
    {
        throw WrongQueueSize();
    }
    
    size_t i = head_;
    
    do
    {
        array_[i] = src.array_[i];
        
        if (i == size_)
        {
            i = 0;
        }
        else
        {
            i++;
        }
            
    } while (i != tail_);
}

template <class T>
void QueueArray<T>::enQueue(const T& element)
{
    if (head_ == tail_ + 1)
    {
        throw QueueOverflow(); // нет места для нового элемента
    }
    
    array_[tail_] = element;
    
    if (tail_ == size_)
    {
        tail_ = 0;
    }
    else
    {
        tail_++;
    }
}

template <class T>
const T& QueueArray<T>::deQueue()
{
    if (head_ == tail_)
    {
        throw QueueUnderflow(); // очередь пуста
    }
    
    const T& data = array_[head_];
    
    if (head_ == size_)
    {
        head_ = 0;
    }
    else
    {
        head_++;
    }

    return data;
}

template<class T>
inline void QueueArray<T>::show() const
{
    if (this->isEmpty())
    {
        cout << " is empty";
    }
    else
    {
        size_t i = head_;
        do
        {
            cout << array_[i] << ' ';
            if (i == size_)
            {
                i = 0;
            }
            else
            {
                i++;
            }
            
        } while (i != tail_);
    }
}

#endif /* QueueArrayCyclic_hpp */
