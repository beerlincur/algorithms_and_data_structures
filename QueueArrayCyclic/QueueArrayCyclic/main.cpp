//
//  main.cpp
//  QueueArrayCyclic
//
//  Created by zhozh on 05.04.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#include <iostream>
#include "QueueArrayCyclic.hpp"

using std::cout;
using std::cerr;

int main()
{
    try
    {
        QueueArray<int> q1(5);
        
        cout << (q1.isEmpty() ? "its empty" : "its not empty") << "\n"; // its empty
        
        q1.enQueue(1);
        q1.enQueue(2);
        q1.enQueue(3);
        q1.enQueue(4);
        q1.enQueue(5);
        
        cout << (q1.isEmpty() ? "its empty" : "its not empty") << "\n"; // its not empty
        q1.show(); // 1 2 3 4 5
        
        cout << "\n";
        
        q1.deQueue();
        
        q1.show(); // 2 3 4 5
        
        cout << "\n";
        
        q1.enQueue(6);
        
        q1.show(); // 2 3 4 5 6
        
        cout << "\n";
        
        q1.deQueue();
        q1.enQueue(7);
        
        q1.deQueue();
        q1.enQueue(8);
        
        q1.deQueue();
        q1.enQueue(9);
        
        q1.deQueue();
        q1.enQueue(10);
        
        QueueArray<int> q2(q1);
        
        q2.show(); // 6 7 8 9 10
        cout << "\n";
        
        cout << (q1.isEmpty() ? "its empty" : "its not empty") << "\n"; // its not empty
        q1.show(); // 6 7 8 9 10
        
        q1.deQueue();
        q1.deQueue();
        q1.deQueue();
        q1.deQueue();
        q1.deQueue();
        
        q1.show(); // ________
        cout << "\n";
        cout << (q1.isEmpty() ? "its empty" : "its not empty") << "\n"; // its empty
        
        cout << "\n";
        
        return 0;
    }
    catch (QueueOverflow)
    {
        cerr << QueueOverflow().what() << "\n";
        return -1;
    }
    catch (QueueUnderflow)
    {
        cerr << QueueUnderflow().what() << "\n";
        return -1;
    }
    catch (WrongQueueSize)
    {
        cerr << WrongQueueSize().what() << "\n";
        return -1;
    }
}

// OUTPUT EXAMPLE
//its empty
//its not empty
//1 2 3 4 5
//2 3 4 5
//2 3 4 5 6
//6 7 8 9 10
//its not empty
//6 7 8 9 10
//its empty
