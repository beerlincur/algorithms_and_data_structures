//
//  List.hpp
//  SortingAlgorithms
//
//  Created by zhozh on 02.04.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <iostream>

using std::cout;

template<class T>
class List
{
public:
    List() : head_(nullptr) {};

    T& popFront();
    void pushBack(const T& data);
    void pushFront(const T& data);
    void show();
    
    //T& operator[](const int index);
    void operator+=(const T& data);
    
    bool isEmpty() const { return head_ == nullptr; }
    
    void clear();
    
    ~List();
private:

    template<class N>
    class Node
    {
    public:
        
        T data_;
        Node *pNext_;

        Node(T data = T(), Node *pNext = nullptr)
        {
            this->data_ = data;
            this->pNext_ = pNext;
        }

    };
    
    Node<T>* head_;
};

template<typename T>
T& List<T>::popFront()
{
    Node<T>* temp = head_;
    
    T toReturn = temp->data_;
    
    head_ = head_->pNext_;

    delete temp;
    
    return toReturn;

}


template<class T>
void List<T>::clear()
{
    while (head_)
    {
        popFront();
    }
}

template <class T>
void List<T>::operator+= (const T& data)
{
    if (this->head_ == nullptr)
    {
        this->head_ = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head_;
        
        while (current != nullptr)
        {
            
            if (data < current->data_)
            {
                T tempInt = current->data_;
                current->data_ = data;

                current->pNext_ = new Node<T>(tempInt, current->pNext_);
                return;
            }

            if (current->pNext_ == nullptr)
            {
                current->pNext_ = new Node<T>(data);
                return;
            }

            current = current->pNext_;
        }

    }
}

template<class T>
List<T>::~List() { clear(); }

#endif /* List_hpp */
