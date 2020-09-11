//
//  main.cpp
//  StackCompiler
//
//  Created by zhozh on 20.02.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#include "StackArray.hpp"

using std::string;
using std::cerr;

//StackArray<char>& toReversePolishNotation (const char* text);
string toReversePolishNotation (const char* text);
int calculateReversePolishNotation(const string reversePolishNotation);

int main()
{
    try
    {
        const char* test0 = "(1+2)*(2+3)";
        string reversePolish0 = toReversePolishNotation(test0);
        int result0 = calculateReversePolishNotation(reversePolish0);
        cout << "Entered expression: " << test0 << ". Result as reverse polish notation: " << reversePolish0 << ". It's equals to: " << result0 << "\n";
        
        const char* test1 = "(4*(6-3))+((8-6)/2)";
        string reversePolish1 = toReversePolishNotation(test1);
        int result1 = calculateReversePolishNotation(reversePolish1);
        cout << "Entered expression: " << test1 << ". Result as reverse polish notation: " << reversePolish1 << ". It's equals to: " << result1 << "\n";

        const char* test2 = "4*(6-3)+(8-6)/2";
        string reversePolish2 = toReversePolishNotation(test2);
        int result2 = calculateReversePolishNotation(reversePolish2);
        cout << "Entered expression: " << test2 << ". Result as reverse polish notation: " << reversePolish2 << ". It's equals to: " << result2 << "\n";

        
        const char* test3 = "((1+2)*(2+3))^2";
        string reversePolish3 = toReversePolishNotation(test3);
        int result3 = calculateReversePolishNotation(reversePolish3);
        cout << "Entered expression: " << test3 << ". Result as reverse polish notation: " << reversePolish3 << ". It's equals to: " << result3 << "\n";
        
//        const char* test4 = "1+2*3";
//        const char* test4 = "1*2+3";
        const char* test4 = "1*2/3";
//        const char* test4 = "1*2/3*4";
//        const char* test4 = "(5+2)/(3-3)";
        
        string reversePolish4 = toReversePolishNotation(test4);
        int result4 = calculateReversePolishNotation(reversePolish4);
        cout << "Entered expression: " << test4 << ". Result as reverse polish notation: " << reversePolish4 << ". It's equals to: " << result4 << "\n";
        
        return 0;
    }
    catch (WrongOperation)
    {
        cerr << WrongOperation().what() << '\n';
        return -1;
    }
    catch (WrongStackSize)
    {
        cerr << WrongStackSize().what() << '\n';
        return -1;
    }
    catch (ZeroDivision)
    {
        cerr << ZeroDivision().what() << '\n';
        return -1;
    }
    catch (WrongBracketBalance)
    {
        cerr << WrongBracketBalance().what() << '\n';
        return -1;
    }
    catch (StackOverflow)
    {
        cerr << StackOverflow().what() << '\n';
        return -1;
    }
    catch (StackUnderflow)
    {
        cerr << StackUnderflow().what() << '\n';
        return -1;
    }
    
}
