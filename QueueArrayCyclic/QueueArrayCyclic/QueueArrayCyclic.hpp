//
//  QueueArrayCyclic.hpp
//  QueueArrayCyclic
//
//  Created by zhozh on 05.04.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef QueueArrayCyclic_hpp
#define QueueArrayCyclic_hpp

#include "Queue.hpp"
#include "QueueExceptions.hpp"
#include <iostream>

using std::cout;

template <class T>
class QueueArray: public Queue<T>
{
public:

    QueueArray(size_t defaultSize = 100); // размер "по умолчанию"
    QueueArray(const QueueArray<T>& src);
    QueueArray<T>& enQueue(const T& element) override;
    QueueArray<T>& deQueue() override;
    T& front() override;
    bool isEmpty() const override;
    size_t size() const override;
    void show() const override;
    virtual ~QueueArray() override;

private:

    T* array_;
    size_t head_;
    size_t tail_;
    size_t size_;

    void deleteQueue_() override;
};

template <class T>
QueueArray<T>::QueueArray(size_t size) :
    head_(0),
    tail_(0),
    array_(nullptr),
    size_(0)
{
    try
    {
        array_ = new T[size];
        size_ = size;
    }
    catch (...)
    {
        throw WrongQueueSize();
    }
}

template <class T>
QueueArray<T>::QueueArray(const QueueArray<T>& src) :
    array_(nullptr),
    head_(0),
    tail_(0),
    size_(0)
{
    try
    {
        array_ = new T[src.size_];
        size_ = src.size_;
    }
    catch (...)
    {
        throw WrongQueueSize();
    }
    // копирование очереди . . .
    head_ = src.head_;
    tail_ = src.tail_;
    for (size_t i = head_; i < tail_; ++i)
    {
        array_[i % size_] = src.array_[i % size_];
    }
}

template <class T>
QueueArray<T>& QueueArray<T>::enQueue(const T& element)
{
    if (tail_ - head_ == size_)
    {
        throw QueueOverflow(); // нет места для нового элемента
    }
    // занесение элемента в очередь . . .
    array_[tail_ % size_] = element;
    ++tail_;
    return *this;
}

template <class T>
QueueArray<T>& QueueArray<T>::deQueue()
{
    if (tail_ == head_)
    {
        throw QueueUnderflow(); // очередь пуста
    }
    // удаление элемента из очереди . . .
    ++head_;
    if (head_ == size_)
    {
        head_ = 0;
        tail_ -= size_;
    }
    return *this;
}

template <class T>
T& QueueArray<T>::front()
{
    if (tail_ == head_)
    {
        throw QueueUnderflow(); // очередь пуста
    }
    return array_[head_];
}

template <class T>
bool QueueArray<T>::isEmpty() const
{
    return (head_ == tail_);
}

template <class T>
size_t QueueArray<T>::size() const
{
    return (tail_ - head_);
}

template <class T>
void QueueArray<T>::show() const
{
    for(size_t i = head_; i < tail_; i++)
    {
        cout << array_[i % size_] << " ";
    }
}

template <class T>
void QueueArray<T>::deleteQueue_()
{
    delete[] array_;
    array_ = nullptr;
    size_ = head_ = tail_ = 0;
}

template <class T>
QueueArray<T>::~QueueArray()
{
    deleteQueue_();
}

#endif /* QueueArrayCyclic_hpp */
