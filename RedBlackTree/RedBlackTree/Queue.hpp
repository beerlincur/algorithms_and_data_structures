//
//  Queue.hpp
//  RedBlackTree
//
//  Created by zhozh on 25.04.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include "QueueExceptions.hpp"
#include <iostream>

using std::cout;

template <class T>
class QueueList
{
public:
    
    QueueList();
    QueueList(const QueueList<T>& src);
    virtual ~QueueList();
    
    void enQueue(const T& element); // добавление в конец
    const T& deQueue(); // удаление из начала
    bool isEmpty() const { return head_ == nullptr; } // проверка на пустоту
    T& peekFront() const { return head_->data_; } // получение из начала
    void show() const; // вывод на экран
    
private:
    
    template<class N>
    class Node
    {
    public:
        Node* pNext_;
        N data_;

        Node(const N data = N(), Node *pNext = nullptr)
        {
            this->data_ = data;
            this->pNext_ = pNext;
        }

    };
    
    Node<T>* head_;
    Node<T>* tail_;
};


template <class T>
QueueList<T>::QueueList()
{
    head_ = nullptr;
    tail_ = nullptr;
}

template <class T>
QueueList<T>::QueueList(const QueueList<T>& src)
{
    Node<T>* current = src.head_;
    
    while(current != nullptr)
    {
        this->enQueue(current->data_);
        current = current->pNext_;
    }
}

template <class T>
void QueueList<T>::enQueue(const T& element)
{
    if (head_ == nullptr)
    {
        head_ = new Node<T>(element);
        tail_ = head_;
        return;
    }
    
    tail_->pNext_ = new Node<T>(element);
    tail_ = tail_->pNext_;
}

template <class T>
const T& QueueList<T>::deQueue()
{
    Node<T>* toDelete = head_;
    T& headData = head_->data_;
    
    if (head_ == nullptr)
    {
        throw QueueUnderflow();
    }
    
    head_ = head_->pNext_;
    
    delete toDelete;
    return headData;
}

template <class T>
void QueueList<T>::show() const
{
    if (head_ == nullptr)
    {
        throw QueueUnderflow();
    }
    
    Node<T>* current = head_;
    while (current != nullptr)
    {
        cout << current->data_ << " ";
        current = current->pNext_;
    }
}

template <class T>
QueueList<T>::~QueueList()
{
    Node<T>* current = head_;
    
    while (head_)
    {
        head_ = head_->pNext_;
        delete current;
        current = head_;
    }
}

#endif /* Queue_hpp */
