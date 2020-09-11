//
//  main.cpp
//  AISD
//
//  Created by zhozh on 10.02.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#include "List.h"

int main()
{
    setlocale(LC_ALL, "RUSSIAN");

    List first;

//    first += 0;
//    first += 2;
//    first += 4;
//    first += 6;
//    first += 8;
//    first += 10;
//    first += 14;
//    
//    first += 1;
//    first += 3;
//    first += 5;
//    first += 8;
//    first += 13;
//    first += 24;
//    
//    first += 5;
//    first += 10;
//    first += 15;
//    first += 20;
//    first += 25;
//    first += 30;
//    first += 35;
//    first += 40;
//    first += 45;
//    first += 50;
//    
//    first += 0;
//    first += 1;
//    first += 2;
//    first += 4;
//    first += 6;
//    first += 8;
//    first += 10;
//    first += 12;
//    first += 13;
//    first += 24;
//    
//    first += 6;
//    first += 13;
//    first += 24;
//    
//    first += 1;
//    first += 3;
//    first += 5;
//    first += 7;
//    first += 9;
//    first += 11;
    
    first += 67;
    first += 48;
    first += 84;
    first += 91;
    first += 100;
    first += 83;
    first += 24;
    first += 31;
    first += 66;
    first += 36;
    first += 23;
    first += 12;
    first += 61;
    
//    first.addTail(5);
//    first.addTail(10);

    List second;

//    second += 1;
//    second += 3;
//    second += 5;
//    second += 7;
//    second += 9;
//    second += 11;
//    second += 12;
//
//    second += 6;
//    second += 13;
//    second += 24;
//
//    second += 0;
//    second += 2;
//    second += 4;
//    second += 6;
//    second += 8;
//    second += 10;
//    second += 12;
//    second += 14;
//    second += 16;
//    second += 18;
//    second += 20;
//    second += 25;
//
//    second += 1;
//    second += 3;
//    second += 5;
//    second += 6;
//    second += 7;
//    second += 8;
//    second += 9;
//    second += 11;
//    second += 13;
//    second += 14;
//
//    second += 0;
//    second += 2;
//    second += 4;
//    second += 6;
//    second += 8;
//    second += 10;
//    second += 12;
    
    second += 53;
    second += 11;
    second += 91;
    second += 57;
    second += 18;
    second += 93;
    second += 13;
    second += 25;
    second += 27;
    second += 71;
    second += 12;
    second += 99;
    second += 83;
    
//    second.addTail(5);
//    second.addTail(8);
    
//
//
    cout << endl << "the first list: " << endl;
    cout << first << endl;

    cout << "the second list: " << endl;
    cout << second << endl;

    cout << "==================================================" << endl;
    cout << "lists are equal: ";

    if (first == second)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    cout << "==================================================" << endl;

    List resultAnd;

    resultAnd = first & second;

    cout << "result of AND operator: " << endl;
    cout << resultAnd << endl;

    List resultOr;

    resultOr = first | second;

    cout << "result of OR operator: " << endl;
    cout << resultOr << endl;

    cout << "==================================================" << endl;

    first.merge(second);

    cout << "result of merge method to first list" << endl;

    cout << first << endl;
    
    cout << "==================================================" << endl;
    cout << "second list after merge:" << endl;
    cout << second << endl;
    
    return 0;
}
