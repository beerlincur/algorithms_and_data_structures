//
//  toReversePolishNotation.cpp
//  StackCompiler
//
//  Created by zhozh on 23.02.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#include <stdio.h>
#include "StackArray.hpp"
#include "Operator.hpp"
#include <cmath>

using std::string;
using std::pow;

string toReversePolishNotation (const char* text)
{
    string result = "\0";
    
    StackArray<Operator>* operators = new StackArray<Operator>;
    
    
    char cText = '\0';
    
    for (int i = 0; (cText = text[i]) != '\0'; i++)
    {
        switch (cText)
        {
            case '(':
            {
                Operator openingBracket = Operator(cText);
                operators->push(openingBracket);
                break;
            }
            case '+': case '-': case '*': case '/': case '^':
            {
                Operator currentOperator = Operator(cText);
                
                if (operators->isEmpty())                     // убрал try-catch, теперь проверяю на наличие элементов стека
                {                                             // и (ниже) отлавливаю корректность скобок
                    operators->push(currentOperator);
                    break;
                }
                
                Operator previousOperator = operators->pop();
                
                
                while (previousOperator.getPriority() >= currentOperator.getPriority())
                {
                    result += previousOperator.getOperation();
                    if (operators->isEmpty())
                    {
                        break;
                    }
                    previousOperator = operators->pop();
                }
                
                operators->push(previousOperator);
                operators->push(currentOperator);
                
                break;
                
            }
            case ')':
            {
                Operator closingBracket = Operator(cText);
                
                if (operators->isEmpty())
                {
                    throw WrongBracketBalance(); // появилась дополнительная проверка на корректность скобок
                }
                
                Operator previousOperator = operators->pop();
                while (previousOperator.getPriority() > closingBracket.getPriority())
                {
                    result += previousOperator.getOperation();
                    
                    if (operators->isEmpty())
                    {
                        break;
                    }
                    previousOperator = operators->pop();
                }
                
                break;
                
            }
            default:
            {
                result += cText;
                break;
            }
        }
    }
    
    char lastestOperation = '\0';
    
    for (int i = 0; i <= operators->getTop(); i++)
    {
        lastestOperation = operators->pop().getOperation();
        
        if (lastestOperation == '(' or lastestOperation == ')')
        {
            throw WrongBracketBalance(); // еще проверка на скобки
        }
        
        result += lastestOperation;
    }
    
    return result;
}

int calculateReversePolishNotation(const string reversePolishNotation)
{
    StackArray<int>* operands = new StackArray<int>;

    for (int i = 0; i < reversePolishNotation.length(); i++) // можно было бы написать перед switch получение из стека правого и левого операнда,
    {                                                       //  но это будет происходить и тогда, когда из строки пришла цифра -> StackUnderFlow -
                                                            //  поэтому я пришел к такому решению
        switch (reversePolishNotation[i])
        {
            case '+':
            {
                operands->push(operands->pop() + operands->pop());
                break;
            }
            case '-':
            {
                operands->push((-operands->pop()) + operands->pop()); // использую унарный минус
                break;
            }
            case '*':
            {
                operands->push(operands->pop() * operands->pop());
                break;
            }
            case '/':
            {
                int divider = operands->pop();

                if (divider == 0)
                {
                    throw ZeroDivision();
                }

                operands->push(operands->pop() / divider);
                break;
            }
            case '^':
            {
                int power = operands->pop(); // приходится использовать темповые переменные,
                                             // тк по другому поддержать порядок исполнения невозможно
                int base = operands->pop();

                operands->push(pow(base, power));
                break;
            }
            default:
            {
                operands->push((reversePolishNotation[i] - '0')); // перевод в целое число
                break;
            }
        }
    }
    return operands->pop();
}

// ВЫВОД

//Entered expression: (1+2)*(2+3). Result as reverse polish notation: 12+23+*. It's equals to: 15
//Entered expression: (4*(6-3))+((8-6)/2). Result as reverse polish notation: 463-*86-2/+. It's equals to: 13
//Entered expression: 4*(6-3)+(8-6)/2. Result as reverse polish notation: 463-*86-2/+. It's equals to: 13
//Entered expression: ((1+2)*(2+3))^2. Result as reverse polish notation: 12+23+*2^. It's equals to: 225
//Division by zero!
