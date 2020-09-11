//
//  Stack.hpp
//  StackCompiler
//
//  Created by zhozh on 20.02.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
// =============================================================
// Шаблон класса Stack представляет понятие абстрактного стека
//==============================================================

template <class T>
class Stack
{
public:
    
    Stack() = default; // конструктор
    Stack(const Stack&) = delete;
    
    virtual ~Stack() = default;// Виртуальный - для переопределения
    // Абстрактные операции со стеком
    
    virtual void push(const T& e) = 0; // Добавление элемента в стек
    
    virtual const T& pop() = 0;// Удаление и возвращение верхнего элемента.
    // Если элементов нет, может возникнуть StackUnderflow
    
    virtual bool isEmpty() = 0; // Проверка стека на пустоту

};
#endif /* Stack_hpp */
