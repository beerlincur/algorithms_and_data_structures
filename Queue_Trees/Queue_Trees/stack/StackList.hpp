//
//  StackList.hpp
//  Queue_Trees
//
//  Created by zhozh on 19.03.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef StackList_hpp
#define StackList_hpp

#include <stdio.h>
#include <iostream>
#include "Stack.hpp"
#include "StackExceptions.hpp"

using std::cout;

// =======================================================================================
// Шаблон класса StackList представляет реализацию структуры стек через односвязный список
//========================================================================================

template <class T>
class StackList: public Stack<T>
{
public:
    
    StackList()
    {
        head_ = nullptr;
    }
    
    StackList(StackList<T>&& other)
    {
        this->head_ = other.head_;
        other.head_ = nullptr;
    }
    
    virtual ~StackList() override
    {
        Node<T>* current = this->head_;

        while (this->head_ != nullptr)
        {
            this->head_ = this->head_->pNext_;
            delete current;
            current = this->head_;
        }
    }
    
    void push (const T& data) override;
    const T& pop() override;
    bool isEmpty() override;
    void peek();
    
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
    
};

template <class T>
void StackList<T>::push(const T& data)
{
    Node<T>* newNode = new Node<T>(data);
    newNode->pNext_ = this->head_;
    this->head_ = newNode;
}

template <class T>
const T& StackList<T>::pop()
{
    if (this->head_ == nullptr)
    {
        throw StackUnderflow();
    }
    
    Node<T>* toDelete = this->head_;
    T result = this->head_->data_;
    this->head_ = this->head_->pNext_;
    delete toDelete;
    return result;
}

template <class T>
bool StackList<T>::isEmpty()
{
    return (this->head_ == nullptr);
}

template <class T>
void StackList<T>::peek()
{
    Node<T>* current = this->head_;
    while (current != nullptr)
    {
        cout << current->data_ << " ";
        current = current->pNext_;
    }
    cout << "\n";
}

#endif /* StackList_hpp */
