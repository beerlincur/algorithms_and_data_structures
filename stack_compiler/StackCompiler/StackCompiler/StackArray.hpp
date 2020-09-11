//
//  StackArray.hpp
//  StackCompiler
//
//  Created by zhozh on 20.02.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef StackArray_hpp
#define StackArray_hpp

#include <stdio.h>
#include <iostream>
//#include <ostream>
#include "Stack.hpp"
#include "StackExceptions.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

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
    const int getTop();
    
    const T& operator[] (const int index) const;
    
    friend ostream& operator<< (ostream &os, StackArray<T>& stack)
    {
        for (int i = 0; i <= stack.getTop(); i++)
        {
            os << stack[i] << " ";
        }
        
        os << '\n';
        
        return os;
    }
    
    
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
        //fill(array_, array_ + size_, T());
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
    for (int i = 0; i <= top_; i++) {
        cout << array_[i] << " ";
    }
    cout << "\n";
}

template <class T>
const int StackArray<T>::getSize()
{
    return this->size_;
}

template <class T>
const int StackArray<T>::getTop()
{
    return this->top_;
}

template <class T>
const T& StackArray<T>::operator[] (const int index) const
{
    return array_[index];
}

#endif /* StackArray_hpp */
