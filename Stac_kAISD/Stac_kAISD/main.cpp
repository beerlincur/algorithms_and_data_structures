//
//  main.cpp
//  Stac_kAISD
//
//  Created by zhozh on 13.02.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//


//пример вывода 
// ok : right
//( ) ok : right
//(([])) ok: right
//(([{}[]([])])) OK: right
//(([{}[]([])])) ) extra right parenthesis: wrong
//( ( [{ }[ ]([ ])] ) extra left parenthesis : wrong
//( ( [{ ][ ]([ ])]) ) unpaired bracket : wrong
//
// ok : 0
//( ) ok : 1
//(([])) ok: 3
//(([{}[]([])])) OK: 5
//(([{}[]([])])) ) extra right parenthesis: -1
//( ( [{ }[ ]([ ])] ) extra left parenthesis : -1
//( ( [{ ][ ]([ ])]) ) unpaired bracket : -1
//(([{}([])[]])) OK: 5
//: 0
//Program ended with exit code: 0


#include "StackArray.hpp"
#include "StackList.hpp"

bool testBalanceBrackets(const char* text, int typeOfStack = 0, int maxDeep = 30); // 0 - массив | 1 - список

int countMaxNesting(const char* text, int typeOfStack = 0, int maxDeep = 30); // 0 - массив | 1 - список

int main()
{
    try
    {
        const char* text00 = " ok ";
        cout << text00 << ": " << (testBalanceBrackets(text00, 0) ? "right" : "wrong") << endl;

        const char* text01 = "( ) ok ";

        cout << text01 << ": " << (testBalanceBrackets(text01, 1) ? "right" : "wrong") << endl;

        const char* text02 = "(([])) ok";
        cout << text02 << ": " << (testBalanceBrackets(text02, 0) ? "right" : "wrong") << endl;

        const char* text03 = "(([{}[]([])])) OK";
        cout << text03 << ": " << (testBalanceBrackets(text03, 1) ? "right" : "wrong") << endl;

        const char* text04 = "(([{}[]([])])) ) extra right parenthesis";
        cout << text04 << ": " << (testBalanceBrackets(text04, 0) ? "right" : "wrong") << endl;

        const char* text05 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
        cout << text05 << ": " << (testBalanceBrackets(text05, 1) ? "right" : "wrong") << endl;

        const char* text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
        cout << text06 << ": " << (testBalanceBrackets(text06, 0) ? "right" : "wrong") << endl;
        
        cout << "\n";
        
        const char* text07 = " ok ";
        cout << text07 << ": " << countMaxNesting(text07, 0) << endl;
        
        const char* text08 = "( ) ok ";
        
        cout << text08 << ": " << countMaxNesting(text08, 1) << endl;
        
        const char* text09 = "(([])) ok";
        cout << text09 << ": " << countMaxNesting(text09, 0) << endl;
        
        const char* text10 = "(([{}[]([])])) OK";
        cout << text10 << ": " << countMaxNesting(text10, 1) << endl;
        
        const char* text11 = "(([{}[]([])])) ) extra right parenthesis";
        cout << text11 << ": " << countMaxNesting(text11, 0) << endl;
        
        const char* text12 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
        cout << text12 << ": " << countMaxNesting(text12, 1) << endl;
        
        const char* text13 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
        cout << text13 << ": " << countMaxNesting(text13, 0) << endl;
        
        const char* text14 = "(([{}([])[]])) OK";
        cout << text14 << ": " << countMaxNesting(text14, 1) << endl;
        
        const char* text15 = "";
        cout << text15 << ": " << countMaxNesting(text15, 0) << endl;
        
        return 0;
    }
    catch (WrongStackType)
    {
        cerr << "\n" << WrongStackType().what() << "\n";
        return -1;
    }
    catch (WrongStackSize)
    {
        cerr << "\n" << WrongStackSize().what() << "\n";
        return -1;
    }
    
}
