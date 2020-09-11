//
//  testFunc.cpp
//  Stac_kAISD
//
//  Created by zhozh on 18.02.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#include <stdio.h>
#include "StackArray.hpp"
#include "StackList.hpp"

bool testBalanceBrackets(const char* text, int typeOfStack = 0, int maxDeep = 30) // 0 - массив | 1 - список
{
    Stack<char>* stack;

    if (typeOfStack == 0)
    {
        stack = new StackArray<char>(maxDeep);
    }
    else if (typeOfStack == 1)
    {
        stack = new StackList<char>();
    }
    else
    {
        throw WrongStackType();
    }


    bool isBalanceBrackets = true; // изменим на false при обнаружении ошибки
   // если в структуре скобок есть ошибки,
   // может возникнуть прерывание при работе со стеком
    try
    {
        char cText = '\0'; // очередной символ текста
        // Цикл анализа текста: учитываются только скобки, остальные символы -
        // Цикл завершается при достижении конца текста или обнаружении первогопропускаются. несоответствия скобок.
        for (int i = 0; ((cText = text[i]) != '\0') && (isBalanceBrackets == true); i++)
        {
            switch (cText)
            {
                case '(': case '[': case '{':
                    stack->push(cText); // любая левая скобка помещается в стек
                    break;

                case ')': // правая скобка проверяется на соответствие со скобкой в вершине стека
                    if (stack->pop() != '(')
                    {
                        isBalanceBrackets = false;
                    }
                    break;

                case ']':
                    if (stack->pop() != '[')
                    {
                        isBalanceBrackets = false;
                    }
                    break;

                case '}':
                    if (stack->pop() != '{')
                    {
                       isBalanceBrackets = false;
                    }
                    break;

            }
        }
        isBalanceBrackets = isBalanceBrackets && stack->isEmpty();
    }

// Достигнут конец текста. Все в порядке, если стек пуст и есть баланс скобок
    catch (StackUnderflow)
    {
        isBalanceBrackets = false;
    }

    catch (StackOverflow)
    {
        isBalanceBrackets = false;
    }

    delete stack;

    return isBalanceBrackets;

}



int countMaxNesting(const char* text, int typeOfStack = 0, int maxDeep = 30) // 0 - массив | 1 - список
{
    int nesting = 0;
    int maxNesting = 0;
    
    Stack<char>* stack;
    
    if (typeOfStack == 0)
    {
        stack = new StackArray<char>(maxDeep);
    }
    else if (typeOfStack == 1)
    {
        stack = new StackList<char>();
    }
    else
    {
        throw WrongStackType();
    }
    
    
    bool isBalanceBrackets = true; // изменим на false при обнаружении ошибки
   // если в структуре скобок есть ошибки,
   // может возникнуть прерывание при работе со стеком
    try
    {
        char cText = '\0'; // очередной символ текста
        // Цикл анализа текста: учитываются только скобки, остальные символы -
        // Цикл завершается при достижении конца текста или обнаружении первогопропускаются. несоответствия скобок.
        for (int i = 0; ((cText = text[i]) != '\0') && (isBalanceBrackets == true); i++)
        {
            switch (cText)
            {
                case '(': case '[': case '{':
                    stack->push(cText); // любая левая скобка помещается в стек
                    nesting++;
                    
                    maxNesting = nesting > maxNesting ? nesting : maxNesting;
                    break;
                    
                case ')': // правая скобка проверяется на соответствие со скобкой в вершине стека
                    if (stack->pop() != '(')
                    {
                        isBalanceBrackets = false;
                    }
                    nesting--;
                    break;
                    
                case ']':
                    if (stack->pop() != '[')
                    {
                        isBalanceBrackets = false;
                    }
                    nesting--;
                    break;
                    
                case '}':
                    if (stack->pop() != '{')
                    {
                        isBalanceBrackets = false;
                    }
                    nesting--;
                    break;

            }
        }
        isBalanceBrackets = isBalanceBrackets && stack->isEmpty();
    }
        
// Достигнут конец текста. Все в порядке, если стек пуст и есть баланс скобок
    catch (StackUnderflow)
    {
        isBalanceBrackets = false;
    }
    
    catch (StackOverflow)
    {
        isBalanceBrackets = false;
    }
    
    maxNesting = isBalanceBrackets == false ? -1 : maxNesting;
    
    delete stack;
    
    return maxNesting;

}
 
