//
//  List.hpp
//  RedBlackTree
//
//  Created by zhozh on 25.04.2020.
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
    
    List(List<T>& right)
    {
        this->head_ = right.head_;
        right.head_ = nullptr;
    }

    T popFront(); // получение из начала
    
    void pushFront(const T& data); // запись в начало
    void show(); // вывод на экран
    bool deleteByValue(const T& data); // удаление элемента по значению
    List<T>& merge(List<T>& right); // слияние двух списков с поддержанием упорядоченности
    
    void operator+= (const T& data); // +=
    List<T>& operator= (List<T>& other); // присваивание
    
    bool isEmpty() const { return head_ == nullptr; } // проверка на пустоту
    
    void clear(); // очистка списка
    
    ~List();
private:

    template<class N>
    class Node
    {
    public:
        
        T data_;
        Node* pNext_;

        Node(const T& data = T(), Node* pNext = nullptr)
        {
            this->data_ = data;
            this->pNext_ = pNext;
        }
        
    };
    
    Node<T>* head_;
};

template<class T>
void List<T>::clear()
{
    Node<T>* current = head_;
    
    while (head_)
    {
        head_ = head_->pNext_;
        delete current;
        current = head_;
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
                T temp = current->data_;
                current->data_ = data;

                current->pNext_ = new Node<T>(temp, current->pNext_);
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

template <class T>
void List<T>::pushFront(const T& data)
{
    head_ = new Node<T>(data, head_);
}

template<class T>
bool List<T>::deleteByValue(const T& data)
{
    if (head_ == nullptr)
    {
        return false;
    }
    else
    {
        try
        {
            Node<T>* previous = this->head_;
            
            if (previous->data_ == data)
            {
                popFront();
                return true;
            }
            
            while (previous->pNext_->data_ != data)
            {
                previous = previous->pNext_;
            }
            
            Node<T>* toDelete = previous->pNext_;
            previous->pNext_ = toDelete->pNext_;
            delete toDelete;
            return true;
        }
        catch (...)
        {
            return false;
        }
    }
    
    return false;
}

template <class T>
T List<T>::popFront()
{
    Node<T>* temp = head_;
    
    T headData = temp->data_;

    head_ = head_->pNext_;

    delete temp;
    
    //cout << headData << "\n";
    
    return headData;
}

template <class T>
List<T>& List<T>::operator= (List<T>& right)
{
    this->head_ = right.head_;
    right.head_ = nullptr;
    
    return *this;
}

template <class T>
List<T>& List<T>::merge (List<T>& right)
{
    Node<T>* currentLeft = this->head_;
    Node<T>* currentRight = right.head_;
    
    while (currentLeft != nullptr && currentRight != nullptr)
    {
        
        if (currentLeft->data_ > currentRight->data_)
        {
            T tempCurrentLeftData = currentLeft->data_; // элемент, перед которым нужно вставить, принимает значение вставляемого
            currentLeft->data_ = currentRight->data_;
            currentRight->data_ = tempCurrentLeftData;

            Node<T>* tempCurrentLeftNext = currentLeft->pNext_; //запоминаем следующие за текущими элементы списков
            Node<T>* tempCurrentRightNext = currentRight->pNext_;

            currentLeft->pNext_ = currentRight; // вставляем элемент из правого списка в левый
            currentRight->pNext_ = tempCurrentLeftNext;
            
            currentRight = tempCurrentRightNext; // двигаем только правый
            right.head_ = currentRight;
        }
        else if (currentLeft->pNext_ == nullptr)
        {
            if (currentLeft->data_ < currentRight->data_)
            {
                currentLeft->pNext_ = currentRight;
                right.head_ = nullptr;
                //right.tail_ = right.head_;
            }
            else if (currentLeft->data_ == currentRight->data_)
            {
                Node<T>* tempCurrentRightNext = currentRight->pNext_;
                delete currentRight;
                currentLeft->pNext_ = tempCurrentRightNext;
                right.head_ = nullptr;
                //right.tail_ = right.head_;
            }
            break;
        }
        else if (currentLeft->data_ == currentRight->data_)
        {
            currentLeft = currentLeft->pNext_; // двигаем оба
            Node<T>* tempCurrentRightNext = currentRight->pNext_;
            delete currentRight;
            currentRight = tempCurrentRightNext;
            right.head_ = currentRight;
        }
        else
        {
            currentLeft = currentLeft->pNext_; // двигаем левый
        }
        
    }
    
    return *this;
}

template <class T>
void List<T>::show()
{
    Node<T>* current = this->head_;
    while (current != nullptr)
    {
        cout << current->data_ << " ";
        current = current->pNext_;
    }
}

template<class T>
List<T>::~List()
{
    Node<T>* current = head_;
    
    while (head_)
    {
        head_ = head_->pNext_;
        delete current;
        current = head_;
    }
}

#endif /* List_hpp */
