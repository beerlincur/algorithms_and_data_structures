//
//  StackArray.hpp
//  Stac_kAISD
//
//  Created by zhozh on 13.02.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef StackArray_hpp
#define StackArray_hpp

#include <stdio.h>
#include <iostream>
#include "Stack.hpp"
#include "StackExceptions.hpp"

using std::cout;
using std::cerr;
using std::endl;

template <class T>
class StackArray : public Stack<T>
{
public:
    
    StackArray (int size = 100);
    StackArray (const StackArray<T>& other);
    
    virtual ~StackArray()
    {
        delete[] array_;
    }
    
    void push (const T& data) override;
    const T& pop() override;
    bool isEmpty() override;
    void peek();
    const int getSize();
    
    
private:
    
    T* array_; // массив элементов списка
    int top_ = 0; // элемент, занесенный в стек последним
    int size_; // размер стека
};

template <class T>
StackArray<T>::StackArray (int size)
{
    try
    {
        array_ = new T[size_ = size];// пытаемся заказать память под элементы стека...
    }
    catch (...)
    {                           // если что-то случилось (например, размер слишком большой
        throw WrongStackSize(); // или отрицательный) - возникает исключительная top_ = 0;
    }
}

template <class T>
StackArray<T>::StackArray (const StackArray<T>& other)
{
    try
    {
        array_ = new T[size_ = other.size_];
    }
    catch (...)
    {
        throw WrongStackSize();
    }
    
    for (int i = 0; i < other.size_; i++)
    {
        array_[i] = other.array_[i];
    }
    
    top_ = other.top_;
}

template <class T>
void StackArray<T>::push (const T& data)
{
    if (top_ == size_)
    {
        throw StackOverflow();
    }
    
    //top_++;
    array_[++top_] = data;
}

template <class T>
const T& StackArray<T>::pop()
{
    if (top_ == 0)
    {
        throw StackUnderflow();
    }
    
    return array_[top_--];
}

template <class T>
bool StackArray<T>::isEmpty()
{
    return (top_ == 0);
}

template <class T>
void StackArray<T>::peek()
{
    for (int i = 0; i < size_; i++) {
        cout << array_[i] << " ";
    }
    cout << "\n";
}

template <class T>
const int StackArray<T>::getSize()
{
    return size_;
}


#endif /* StackArray_hpp */
