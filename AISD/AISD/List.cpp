//
//  List.cpp
//  AISD
//
//  Created by zhozh on 10.02.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//
#include "List.h"

void List::operator+= (const int number)
{
    if (this->head_ == nullptr)
    {
        this->head_ = new Node(number);
        this->tail_ = this->head_;
    }
    else
    {
        Node* current = this->head_;
        while (current != nullptr)
        {
            if (current->data_ == number)
            {
                cout << "Note: The number " << number << " has been already recorded - was skipped successfully" << endl;
                return;
            }
            
            if (number < current->data_)
            {
                int tempInt = current->data_;
                current->data_ = number;

                current->pNext_ = new Node(tempInt, current->pNext_);
                return;
            }

            if (current->pNext_ == nullptr)
            {
                current->pNext_ = new Node(number);
                tail_ = current->pNext_;
                return;
            }

            current = current->pNext_;
        }

    }
}

void List::addTail (const int number)
{
    
    if (this->head_ == nullptr)
    {
        this->head_ = new Node(number);
        this->tail_ = this->head_;
    }
    else
    {
        this->tail_->pNext_ = new Node(number);
        this->tail_ = this->tail_->pNext_;
    }
}

bool List::operator== (const List& right)
{
    Node* currentLeft = this->head_;
    Node* currentRight = right.head_;

    while (currentLeft != nullptr && currentRight != nullptr && currentLeft->data_ == currentRight->data_)
    {
        if (currentLeft->pNext_ == nullptr && currentRight->pNext_ == nullptr)
        {
            return (currentLeft->data_ == currentRight->data_);
        }
        currentLeft = currentLeft->pNext_;
        currentRight = currentRight->pNext_;
    }

    return false;
}


//                                                   .
// 1 3 5 8 13 24     1 3 5 7 9 11       0 2 4 6 8 10 14    0  1  2  3  4  5  6   8   10  12  13  24      6 13 24            left
// 6 13 24           0 2 4 6 8 10 12    1 3 5 7 9 11       1  3  5  6  7  9  11  13  14                  0 2 4 6 8 10 12    right
//       .                                            .


//
// 5  10  15  20  25  30  35  40  45  50                // 0 5
// 0  2   4   6   8   10  12  14  16  18  20  25
//


List& List::merge (List& right)
{
    Node* currentLeft = this->head_;
    Node* currentRight = right.head_;
    
    while (currentLeft != nullptr && currentRight != nullptr)
    {
        
        if (currentLeft->data_ > currentRight->data_)
        {
            int tempCurrentLeftData = currentLeft->data_; // элемент, перед которым нужно вставить, принимает значение вставляемого
            currentLeft->data_ = currentRight->data_;
            currentRight->data_ = tempCurrentLeftData;

            Node* tempCurrentLeftNext = currentLeft->pNext_; //запоминаем следующие за текущими элементы списков
            Node* tempCurrentRightNext = currentRight->pNext_;

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
                right.tail_ = right.head_;
            }
            else if (currentLeft->data_ == currentRight->data_)
            {
                Node* tempCurrentRightNext = currentRight->pNext_;
                delete currentRight;
                currentLeft->pNext_ = tempCurrentRightNext;
                right.head_ = nullptr;
                right.tail_ = right.head_;
            }
            break;
        }
        else if (currentLeft->data_ == currentRight->data_)
        {
            currentLeft = currentLeft->pNext_; // двигаем оба
            Node* tempCurrentRightNext = currentRight->pNext_;
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

List& operator& (const List& left, const List& right) // 1 2 4 7 9       right
{
    static List result;
    List::Node* currentLeft = left.head_;
    List::Node* currentRight = right.head_;

    while (currentLeft != nullptr && currentRight != nullptr)
    {
        if (currentLeft->data_ == currentRight->data_)
        {
            result += currentLeft->data_;

            if (currentLeft->pNext_ != nullptr && currentRight->pNext_ != nullptr)
            {
                currentLeft = currentLeft->pNext_;
                currentRight = currentRight->pNext_;
            }
            else
            {
                break;
            }
        }
        else if (currentLeft->data_ < currentRight->data_)
        {
            if (currentLeft->pNext_ == nullptr)
            {
                break;
            }
            currentLeft = currentLeft->pNext_;

        }
        else
        {
            if (currentRight->pNext_ == nullptr)
            {
                break;
            }
            currentRight = currentRight->pNext_;
        }
    }
    return result;
}


List& operator| (const List& left, const List& right)
{
    static List result;
    
    List::Node* currentLeft = left.head_;
    List::Node* currentRight = right.head_;
    
    while (currentLeft != nullptr || currentRight != nullptr)
    {
        
        if (currentLeft != nullptr && currentRight != nullptr)
        {

            result += currentLeft->data_;
            result += currentRight->data_;

            currentLeft = currentLeft->pNext_;
            currentRight = currentRight->pNext_;

        }
        else if (currentLeft == nullptr && currentRight != nullptr)
        {
            result += currentRight->data_;
            
            if (currentRight->pNext_ == nullptr)
            {
                break;
            }
            currentRight = currentRight->pNext_;
        }
        else if (currentLeft != nullptr && currentRight == nullptr)
        {
            result += currentLeft->data_;
            
            if (currentLeft->pNext_ == nullptr)
            {
                break;
            }
            currentLeft = currentLeft->pNext_;
        }
        else
        {
            break;
        }
    }
    return result;
}


List& List::operator= (List& other)
{
    if (this != &other)
    {
        this->~List();
        this->head_ = other.head_;
        this->tail_ = other.tail_;
        other.head_ = nullptr;
        other.tail_ = nullptr;
    }
    return *this;
}

ostream& operator<< (ostream& out, const List& list)
{
    List::Node* now = list.head_;
    while (now != nullptr)
    {
        out << now->data_ << endl;
        now = now->pNext_;
    }
    return out;
}

