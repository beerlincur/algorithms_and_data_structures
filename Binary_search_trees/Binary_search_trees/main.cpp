//
//  main.cpp
//  Binary_search_trees
//
//  Created by zhozh on 01.03.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#include "BinarySearchTree.hpp"

using std::cerr;

int main()
{
    try
    {
        BinarySearchTree<int> intTree;
        
        cout << "Inserting some numbers...\n\n";
        
        intTree.insert(10);
        intTree.insert(3);
        intTree.insert(20);
        intTree.insert(15);
        intTree.insert(30);
        intTree.insert(2);
        intTree.insert(5);
        intTree.insert(32);
        intTree.insert(22);
        
        intTree.insert(5);
        
        cout << "The TREE:\n";
        intTree.print(cout);
        cout << "\n";
        
        int toFind = 15;
        bool keyFound = intTree.iterativeSearch(toFind);
        cout << "The key " << toFind << " has been found: " << (keyFound ? "yes" : "no") << "\n";
        cout << "\n";
        
        int toDelete = 20;
        bool isDeleted = intTree.deleteKey(toDelete);
        cout << "The key " << toDelete << " is deleted: " << (isDeleted ? "yes" : "no") << "\n";
        cout << "\n";
        
        cout << "The TREE:\n";
        intTree.print(cout);
        cout << "\n";
        
        int toDelete1 = 40;
        bool isDeleted1 = intTree.deleteKey(toDelete);
        cout << "The key " << toDelete1 << " is deleted: " << (isDeleted1 ? "yes" : "no") << "\n";
        cout << "\n";
        
        cout << "The smallest key of the tree: " << intTree.findMin() << "\n";
        cout << "\n";
        
        cout << "The biggest key of the tree: " << intTree.findMax() << "\n";
        cout << "\n";

        cout << "Height of the tree: " << intTree.getHeight() << "\n";
        cout << "\n";
        
        cout << "Amount of nodes: " << intTree.getCount() << "\n";
        cout << "\n";
        
        int numberThatGreater = 4;
        cout << "Amount of number that less than " << numberThatGreater << " is equal to: " << intTree.getCountLessThan(numberThatGreater) << "\n";
        cout << "\n";
        
        cout << "------------In order:------------\n\n";
        intTree.printInOrder();
        cout << "\n\n";
        
        cout << "------------Searching by different indices:------------\n\n";
        
        for (int i = 0; i < intTree.getCount(); i++)
        {
            cout << "An element with index = " << i << " is " << intTree.searchByIndex(i) << "\n";
            cout << "\n";
        }
        
        int numbersToFindSuccessor[9] = {10, 3, 20, 15, 30, 2, 5, 32, 22};
        
        cout << "------------Finding successors:------------\n\n"; // 0 - наследник не найден
        for (int i : numbersToFindSuccessor)
        {
            cout << "The successor of " << i << " is: " << intTree.findSuccsessor(i) << "\n";
            cout << "\n";
        }
        
        return 0;
    }
    catch(IndexOutOfRange)
    {
        cerr << IndexOutOfRange().what() << "\n";
        return -1;
    }
}


// OUTPUT 
//Inserting some numbers...
//
//The TREE:
//(10(3(2()())(5()()))(20(15()())(30(22()())(32()()))))
//
//The key 15 has been found: yes
//
//The key 20 is deleted: yes
//
//The TREE:
//(10(3(2()())(5()()))(22(15()())(30()(32()()))))
//
//The key 40 is deleted: no
//
//The smallest key of the tree: 2
//
//The biggest key of the tree: 32
//
//Height of the tree: 4
//
//Amount of nodes: 8
//
//Amount of number that less than 4 is equal to: 2
//
//------------In order:------------
//
//2 3 5 10 15 22 30 32
//
//------------Searching by different indices:------------
//
//An element with index = 0 is 2
//
//An element with index = 1 is 3
//
//An element with index = 2 is 5
//
//An element with index = 3 is 10
//
//An element with index = 4 is 15
//
//An element with index = 5 is 22
//
//An element with index = 6 is 30
//
//An element with index = 7 is 32
//
//------------Finding successors:------------
//
//The successor of 10 is: 15
//
//The successor of 3 is: 5
//
//The successor of 20 is: 0
//
//The successor of 15 is: 22
//
//The successor of 30 is: 32
//
//The successor of 2 is: 3
//
//The successor of 5 is: 10
//
//The successor of 32 is: 0
//
//The successor of 22 is: 30
//
//Program ended with exit code: 0
