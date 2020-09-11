//
//  List.h
//  AISD
//
//  Created by zhozh on 10.02.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef List_h
#define List_h

#pragma once

#include <iostream>

using std::ostream;
using std::cout;
using std::endl;

class List
{
public:
    List() : head_(nullptr), tail_(nullptr) {};

    List(List&& other) noexcept //перемещения
    {
        this->head_ = other.head_;
        this->tail_ = other.tail_;
        other.head_ = nullptr;
        other.tail_ = nullptr;
    }

    void operator+= (const int number);
    bool operator== (const List& list);
    List& operator= (List& other);
    
    List& merge(List& right);
    void addTail (const int number);

    friend List& operator& (const List& left, const List& right);

    friend List& operator| (const List& left, const List& right);

    friend ostream& operator<< (ostream& out, const List& list);
    
    virtual ~List()
    {
        Node* current = this->head_;

        while (head_ != nullptr)
        {
            head_ = head_->pNext_;
            delete current;
            current = head_;
        }
    };
    
private:

    class Node
    {
    public:
        Node* pNext_;
        int data_;

        Node(const int data = int(), Node* pNext = nullptr)
        {
            this->data_ = data;
            this->pNext_ = pNext;
        }

    };
    Node* tail_;
    Node* head_;
};

#endif /* List_h */
