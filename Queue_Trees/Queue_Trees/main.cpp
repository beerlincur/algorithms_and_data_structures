//
//  main.cpp
//  Queue_Trees
//
//  Created by zhozh on 18.03.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

//#include "QueueArray.hpp"
#include "QueueArrayCyclic.hpp"
#include "QueueList.hpp"
#include "BST.hpp"

using std::cerr;

int main()
{
    
    try
    {
        // ===================================================================================== QUEUE ARRAY
        cout << "QUEUE ARRAY" << "\n";
        
        int queueArraySize = 5;
        cout << "creating queueArray with size: " << queueArraySize << "\n";
        QueueArray<int> queueArray(queueArraySize);

        cout << "queueArray is empty: " << ((queueArray.isEmpty() == 1) ? "yes" : "no") << "\n";

//        cout << "tryng to deQueue: " << "\n";
//        queueArray.deQueue();

        cout << "add 1" << "\n";
        queueArray.enQueue(1);

        cout << "add 2" << "\n";
        queueArray.enQueue(2);

        cout << "add 3" << "\n";
        queueArray.enQueue(3);

        cout << "add 4" << "\n";
        queueArray.enQueue(4);

//        cout << "add 5" << "\n";
//        queueArray.enQueue(5);
//
//        cout << "add 6" << "\n";
//        queueArray.enQueue(6);

        cout << "queueArray before deleting: ";
        queueArray.show();
        cout << "\n";

        int firstFromArrayQueue = queueArray.deQueue();
        cout << "deleted from queueArray: " << firstFromArrayQueue << "\n";

        cout << "queueArray after deleting: ";
        queueArray.show();
        cout << "\n";

        cout << "first element of queueArray after deleting: " << queueArray.peekFront() << "\n";

        cout << "deleting 3 times" << "\n";
        queueArray.deQueue();
        queueArray.deQueue();
        queueArray.deQueue();

        cout << "queueArray is empty: " << ((queueArray.isEmpty() == 1) ? "yes" : "no") << "\n";

        // ===================================================================================== QUEUE LIST
        cout << "\n\n\n";
        cout << "QUEUE LIST" << "\n";

        cout << "creating queueList: \n";
        QueueList<int> queueList;

        cout << "queueList is empty: " << ((queueArray.isEmpty() == 1) ? "yes" : "no") << "\n";

//        cout << "tryng to deQueue: " << "\n";
//        queueList.deQueue();

        cout << "add 1" << "\n";
        queueList.enQueue(1);

        cout << "add 2" << "\n";
        queueList.enQueue(2);

        cout << "add 3" << "\n";
        queueList.enQueue(3);

        cout << "add 4" << "\n";
        queueList.enQueue(4);

//        cout << "add 5" << "\n";
//        queueList.enQueue(5);
//
//        cout << "add 6" << "\n";
//        queueList.enQueue(6);

        cout << "queueList before deleting: ";
        queueList.show();
        cout << "\n";

        int firstFromListQueue = queueList.deQueue();
        cout << "deleted from queueList: " << firstFromListQueue << "\n";

        cout << "queueList after deleting: ";
        queueList.show();
        cout << "\n";

        cout << "first element of queueList after deleting: " << queueList.peekFront() << "\n";

        cout << "deleting 3 times" << "\n";
        queueList.deQueue();
        queueList.deQueue();
        queueList.deQueue();

        cout << "queueList is empty: " << ((queueArray.isEmpty() == 1) ? "yes" : "no") << "\n";
        cout << "\n\n";
        
        // ===================================================================================== BINARY SEARCH TREES
        cout << "BINARY SEARCH TREES" << "\n\n";
        
        cout << "the FIRST tree:\n"; // ===================================================================================== the FIRST tree

        BinarySearchTree<int> intTree1;

        cout << "Inserting some numbers in FIRST...\n";
        
        cout << "insert 7" << "\n";
        intTree1.insert(7);
        
        cout << "insert 5" << "\n";
        intTree1.insert(5);
        
        cout << "insert 9" << "\n";
        intTree1.insert(9);
        
        cout << "insert 4" << "\n";
        intTree1.insert(4);
        
        cout << "insert 10" << "\n";
        intTree1.insert(10);
        
        cout << "insert 8" << "\n";
        intTree1.insert(8);
        
        cout << "insert 6" << "\n";
        intTree1.insert(6);
        
        cout << "insert 3" << "\n";
        intTree1.insert(3);

        cout << "------------FIRST Recursive In order:------------\n\n";
        intTree1.printInOrder();
        cout << "\n\n";


        cout << "------------FIRST By level:------------\n\n";
        intTree1.printLevelWolk();
        cout << "\n\n";
        
        cout << "------------FIRST Iterative In Order:------------\n\n";
        intTree1.printIterativWolk();
        cout << "\n\n";
        
        cout << "------------FIRST Same to self:------------\n\n";
        cout << (intTree1.isSameWith(intTree1) ? "same" : "not same");
        cout << "\n\n";
        
        
        
        cout << "the SECOND tree:\n"; // ===================================================================================== the SECOND tree
        BinarySearchTree<int> intTree2;

        cout << "Inserting some numbers in SECOND...\n";
        
        cout << "insert 7" << "\n";
        intTree2.insert(7);
        
        cout << "insert 6" << "\n";
        intTree2.insert(6);
        
        cout << "insert 8" << "\n";
        intTree2.insert(8);
        
        cout << "insert 5" << "\n";
        intTree2.insert(5);
        
        cout << "insert 9" << "\n";
        intTree2.insert(9);
        
        cout << "insert 4" << "\n";
        intTree2.insert(4);
        
        cout << "insert 10" << "\n";
        intTree2.insert(10);
        
        cout << "insert 3" << "\n";
        intTree2.insert(3);

        cout << "------------SECOND Recursive In order:------------\n\n";
        intTree2.printInOrder();
        cout << "\n\n";


        cout << "------------SECOND By level:------------\n\n";
        intTree2.printLevelWolk();
        cout << "\n\n";
        
        cout << "------------SECOND Iterative In Order:------------\n\n";
        intTree2.printIterativWolk();
        cout << "\n\n";
        
        cout << "------------The FIRST and the SECOND trees are SAME by KEYS:------------\n\n";
        cout << (intTree1.isSameWith(intTree2) ? "same" : "not same");
        cout << "\n\n";
        
        cout << "the THIRD tree:\n"; // ===================================================================================== the THIRD tree
        BinarySearchTree<int> intTree3;

        cout << "Inserting some numbers in THIRD...\n";
        
        cout << "insert 7" << "\n";
        intTree3.insert(7);
        
        cout << "insert 5" << "\n";
        intTree3.insert(5);
        
        cout << "insert 3" << "\n";
        intTree3.insert(3);
        
        cout << "insert 4" << "\n";
        intTree3.insert(4);
        
        cout << "insert 6" << "\n";
        intTree3.insert(6);
        
        cout << "insert 8" << "\n";
        intTree3.insert(8);
        
        cout << "insert 9" << "\n";
        intTree3.insert(9);
        
        cout << "insert 10" << "\n";
        intTree3.insert(10);

        cout << "------------THIRD Recursive In order:------------\n\n";
        intTree3.printInOrder();
        cout << "\n\n";


        cout << "------------THIRD By level:------------\n\n";
        intTree3.printLevelWolk();
        cout << "\n\n";
        
        cout << "------------THIRD Iterative In Order:------------\n\n";
        intTree3.printIterativWolk();
        cout << "\n\n";
        
        cout << "------------The FIRST and the THIRD trees are SAME by KEYS:------------\n\n";
        cout << (intTree1.isSameWith(intTree3) ? "same" : "not same");
        cout << "\n\n";
        
        cout << "------------The SECOND and the THIRD trees are SAME by KEYS:------------\n\n";
        cout << (intTree2.isSameWith(intTree3) ? "same" : "not same");
        cout << "\n\n";
        
        cout << "the FOURTH tree:\n"; // ===================================================================================== the FOURTH tree
        BinarySearchTree<int> intTree4;

        cout << "Inserting some numbers in FOURTH...\n";
        
        cout << "insert 15" << "\n";
        intTree4.insert(7);
        
        cout << "insert 5" << "\n";
        intTree4.insert(5);
        
        cout << "insert 2" << "\n";
        intTree4.insert(2);
        
        cout << "insert 4" << "\n";
        intTree4.insert(4);
        
        cout << "insert 6" << "\n";
        intTree4.insert(6);
        
        cout << "insert 8" << "\n";
        intTree4.insert(8);
        
        cout << "insert 9" << "\n";
        intTree4.insert(9);
        
        cout << "insert 10" << "\n";
        intTree4.insert(10);

        cout << "------------FOURTH Recursive In order:------------\n\n";
        intTree4.printInOrder();
        cout << "\n\n";


        cout << "------------FOURTH By level:------------\n\n";
        intTree4.printLevelWolk();
        cout << "\n\n";
        
        cout << "------------FOURTH Iterative In Order:------------\n\n";
        intTree4.printIterativWolk();
        cout << "\n\n";
        
        cout << "------------The FIRST and the FOURTH trees are SAME by KEYS:------------\n\n";
        cout << (intTree1.isSameWith(intTree4) ? "same" : "not same");
        cout << "\n\n";
        
        cout << "------------The SECOND and the FOURTH trees are SAME by KEYS:------------\n\n";
        cout << (intTree2.isSameWith(intTree4) ? "same" : "not same");
        cout << "\n\n";
        
        cout << "------------The THIRD and the FOURTH trees are SAME by KEYS:------------\n\n";
        cout << (intTree3.isSameWith(intTree4) ? "same" : "not same");
        cout << "\n\n";
        
        
        BinarySearchTree<int> intTree5;
        
        intTree5.insert(1);
        
        intTree5.insert(2);
        
        intTree5.insert(3);
        
        
        intTree5.insert(4);
        
        intTree5.insert(5);
        
        BinarySearchTree<int> intTree6;
        
        intTree6.insert(1);
        
        intTree6.insert(2);
        
        intTree6.insert(3);
        
        
        intTree6.insert(4);
        
        intTree6.insert(5);
        
        intTree6.insert(6);
        
        
        cout << (intTree6.isSameWith(intTree5) ? "same" : "not same") << "\n";
        
        
        return 0;
    }
    catch (WrongQueueSize)
    {
        cerr << "Error: " << WrongQueueSize().what() << "\n";
        return -1;
    }
    catch (QueueOverflow)
    {
        cerr << "Error: " << QueueOverflow().what() << "\n";
        return -1;
    }
    catch (QueueUnderflow)
    {
        cerr << "Error: " << QueueUnderflow().what() << "\n";
        return -1;
    }
    catch (StackOverflow)
    {
        cerr << "Error: " << StackOverflow().what() << "\n";
        return -1;
    }
    catch (StackUnderflow)
    {
        cerr << "Error: " << StackUnderflow().what() << "\n";
        return -1;
    }
    catch (IndexOutOfRange)
    {
        cerr << "Error: " << IndexOutOfRange().what() << "\n";
        return -1;
    }
}

// OUTPUT EXAMPLE
//QUEUE ARRAY
//creating queueArray with size: 5
//queueArray is empty: yes
//add 1
//add 2
//add 3
//add 4
//queueArray before deleting: 1 2 3 4
//deleted from queueArray: 1
//queueArray after deleting: 2 3 4
//first element of queueArray after deleting: 2
//deleting 3 times
//queueArray is empty: yes
//
//
//
//QUEUE LIST
//creating queueList:
//queueList is empty: yes
//add 1
//add 2
//add 3
//add 4
//queueList before deleting: 1 2 3 4
//deleted from queueList: 1
//queueList after deleting: 2 3 4
//first element of queueList after deleting: 2
//deleting 3 times
//queueList is empty: yes
//
//
//BINARY SEARCH TREES
//
//the FIRST tree:
//Inserting some numbers in FIRST...
//insert 7
//insert 5
//insert 9
//insert 4
//insert 10
//insert 8
//insert 6
//insert 3
//------------FIRST Recursive In order:------------
//
//3 4 5 6 7 8 9 10
//
//------------FIRST By level:------------
//
//7 5 9 4 6 8 10 3
//
//------------FIRST Iterative In Order:------------
//
//3 4 5 6 7 8 9 10
//
//------------FIRST Same to self:------------
//
//same
//
//the SECOND tree:
//Inserting some numbers in SECOND...
//insert 7
//insert 6
//insert 8
//insert 5
//insert 9
//insert 4
//insert 10
//insert 3
//------------SECOND Recursive In order:------------
//
//3 4 5 6 7 8 9 10
//
//------------SECOND By level:------------
//
//7 6 8 5 9 4 10 3
//
//------------SECOND Iterative In Order:------------
//
//3 4 5 6 7 8 9 10
//
//------------The FIRST and the SECOND trees are SAME by KEYS:------------
//
//same
//
//the THIRD tree:
//Inserting some numbers in THIRD...
//insert 7
//insert 5
//insert 3
//insert 4
//insert 6
//insert 8
//insert 9
//insert 10
//------------THIRD Recursive In order:------------
//
//3 4 5 6 7 8 9 10
//
//------------THIRD By level:------------
//
//7 5 8 3 6 9 4 10
//
//------------THIRD Iterative In Order:------------
//
//3 4 5 6 7 8 9 10
//
//------------The FIRST and the THIRD trees are SAME by KEYS:------------
//
//same
//
//------------The SECOND and the THIRD trees are SAME by KEYS:------------
//
//same
//
//the FOURTH tree:
//Inserting some numbers in FOURTH...
//insert 15
//insert 5
//insert 2
//insert 4
//insert 6
//insert 8
//insert 9
//insert 10
//------------FOURTH Recursive In order:------------
//
//2 4 5 6 7 8 9 10
//
//------------FOURTH By level:------------
//
//7 5 8 2 6 9 4 10
//
//------------FOURTH Iterative In Order:------------
//
//2 4 5 6 7 8 9 10
//
//------------The FIRST and the FOURTH trees are SAME by KEYS:------------
//
//not same
//
//------------The SECOND and the FOURTH trees are SAME by KEYS:------------
//
//not same
//
//------------The THIRD and the FOURTH trees are SAME by KEYS:------------
//
//not same
//
//Program ended with exit code: 0
