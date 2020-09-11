//
//  main.cpp
//  SortingAlgorithms
//
//  Created by zhozh on 22.03.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "List.hpp"

using std::cout;
using std::rand;
using std::ofstream;

template <class T>
bool isSorted(T* array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    
    return true;
}

void selectionSort(int *array, int size);

void insertionSort(int* array, int size);

void insertionBinarySearchSort(int* array, int size);

void countSort(int* array, int size, int exp);

void radixSort(int* array, int size);

void bucketSort(float *array, int size);

void shellSedgewickSort(int* array, long size);

void shellHibbardSort(int* array, int size);

void shellShellSort(int* array, int size);



const int ARRAY_SIZE = 10000;

const int RANDOM_RANGE = 600;

int COMPARES = 0;

int MOVES = 0;


int main()
{
    bool isSortedArray = false;
    
    ofstream out;
    out.open("/Users/zhozh/Desktop/projects/c++/aisd/SortingAlgorithms/SortingAlgorithms/analitics.txt");
    
    // out << "    name  |size|sorted|compares|moves|\n";
    
    // ======================================================================================= COUNTING SORT
    cout << "------------COUNT SORT------------" << "\n";
    int arrayForCounting[ARRAY_SIZE] = {0}; // = {8, 7, 5, 6, 5, 1, 0, 0, 9, 3};

    //cout << "unsorted array: " << " ";
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        arrayForCounting[i] = rand() % 10;
        // cout << arrayForCounting[i] << " ";
    }
    cout << "\n";
    
    
    countSort(arrayForCounting, ARRAY_SIZE, 1);
    
    
//    cout << "sorted with count sort:  " << " ";
//    for (size_t i = 0; i < ARRAY_SIZE; i++)
//    {
//        cout << arrayForCounting[i] << " ";
//    }
    
    isSortedArray = isSorted(arrayForCounting, ARRAY_SIZE);
    cout << "\n" << (isSortedArray ? "SORTED" : "NOT SORTED") << "\n";
    cout << "\n\n";
    
    // out << "countSort" << " " << ARRAY_SIZE << " " << (isSortedArray ? "SORTED" : "NOT SORTED") << " "
        // << COMPARES << " " << MOVES << "\n";
    
    COMPARES = 0;

    MOVES = 0;
    
    // ======================================================================================= SELECTION SORT
    cout << "------------SELECTION SORT------------" << "\n";
    int arrayForSelection[ARRAY_SIZE] = {0}; // {432, 356, 572, 937, 765, 709, 613, 143, 137, 148};

    //cout << "unsorted array: " << " ";
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        arrayForSelection[i] = rand() % RANDOM_RANGE;
        // cout << arrayForSelection[i] << " ";
    }
    cout << "\n";
    
    

    selectionSort(arrayForSelection, ARRAY_SIZE);
    
    

//    cout << "sorted with selection sort: " << " ";
//    for (size_t i = 0; i < ARRAY_SIZE_100; i++)
//    {
//        cout << arrayForSelection[i] << " ";
//    }
    
    isSortedArray = isSorted(arrayForSelection, ARRAY_SIZE);
    cout << "\n" << (isSortedArray ? "SORTED" : "NOT SORTED") << "\n";
    cout << "\n\n";
    
    out << "selection" << " " << ARRAY_SIZE << " " << (isSortedArray ? "SORTED" : "NOT SORTED") << " "
        << COMPARES << " " << MOVES << "\n";

    COMPARES = 0;

    MOVES = 0;



    // ======================================================================================= INSERTION SORT
    cout << "------------INSERTION SORT------------" << "\n";
    int arrayForInserion[ARRAY_SIZE] = {0}; // {432, 356, 572, 937, 765, 709, 613, 143, 137, 148};

    //cout << "unsorted array: " << " ";
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        arrayForInserion[i] = rand() % RANDOM_RANGE;
        // cout << arrayForInserion[i] << " ";
    }
    cout << "\n";
    

    
    insertionSort(arrayForInserion, ARRAY_SIZE);
    
    
    
//    cout << "sorted with insertion sort: " << " ";
//    for (size_t i = 0; i < ARRAY_SIZE_100; i++)
//    {
//        cout << arrayForInserion[i] << " ";
//    }

    
    isSortedArray = isSorted(arrayForInserion, ARRAY_SIZE);
    cout << "\n" << (isSortedArray ? "SORTED" : "NOT SORTED") << "\n";
    cout << "\n\n";
    
    out << "insertion" << " " << ARRAY_SIZE << " " << (isSortedArray ? "SORTED" : "NOT SORTED") << " "
        << COMPARES << " " << MOVES << "\n";

    COMPARES = 0;

    MOVES = 0;


    // ======================================================================================= RADIX SORT
    cout << "------------RADIX SORT------------" << "\n";
    int arrayForRadix[ARRAY_SIZE] = {0}; // {432, 356, 572, 937, 765, 709, 613, 143, 137, 148};

    //cout << "unsorted array: " << " ";
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        arrayForRadix[i] = rand() % RANDOM_RANGE;
        // cout << arrayForRadix[i] << " ";
    }
    cout << "\n";
    

    radixSort(arrayForRadix, ARRAY_SIZE);
    
    
    
//    cout << "sorted with radix sort: " << " ";
//    for (size_t i = 0; i < ARRAY_SIZE_100; i++)
//    {
//        cout << arrayForRadix[i] << " ";
//    }

    isSortedArray = isSorted(arrayForRadix, ARRAY_SIZE);
    cout << "\n" << (isSortedArray ? "SORTED" : "NOT SORTED") << "\n";
    cout << "\n\n";
    
    out << "radix" << " " << ARRAY_SIZE << " " << (isSortedArray ? "SORTED" : "NOT SORTED") << " "
        << COMPARES << " " << MOVES << "\n";

    COMPARES = 0;

    MOVES = 0;


    // =================================================================================================================================== BUCKET SORT
    cout << "------------BUCKET SORT------------" << "\n";
    float arrayForBucket[10] = {0.25, 0.36, 0.58, 0.41, 0.29, 0.22, 0.45, 0.79, 0.01, 0.69};

//    cout << "unsorted array: " << " ";
//    for (size_t i = 0; i < ARRAY_SIZE_10; i++)
//    {
//        // arrayForBucket[i] = rand() % RANDOM_RANGE;
//        //cout << arrayForBucket[i] << " ";
//    }
    cout << "\n";
    
    

    bucketSort(arrayForBucket, 10);
    
    

//    cout << "sorted with bucket sort: " << " ";
//    for (size_t i = 0; i < ARRAY_SIZE_10; i++)
//    {
//        cout << arrayForBucket[i] << " ";
//    }

    isSortedArray = isSorted(arrayForBucket, 10);
    cout << "\n" << (isSortedArray ? "SORTED" : "NOT SORTED") << "\n";
    cout << "\n\n";
    
    // out << "bucket" << " " << ARRAY_SIZE_10 << " " << (isSortedArray ? "SORTED" : "NOT SORTED") << " "
       // << COMPARES << " " << MOVES << "\n";

    COMPARES = 0;

    MOVES = 0;


    // =================================================================================================================================== INSERTION BINARY SEARCH SORT
    cout << "------------INSERTION BINARY SEARCH SORT------------" << "\n";
    int arrayForInsertionBinarySearch[ARRAY_SIZE] = {0}; // {432, 356, 572, 937, 765, 709, 613, 143, 137, 148};

    //cout << "unsorted array: " << " ";
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        arrayForInsertionBinarySearch[i] = rand() % RANDOM_RANGE;;
        // cout << arrayForInsertionBinarySearch[i] << " ";
    }
    cout << "\n";
    
    
    
    insertionBinarySearchSort(arrayForInsertionBinarySearch, ARRAY_SIZE);
    
    

//    cout << "sorted with insertion binary search sort: " << " ";
//    for (size_t i = 0; i < ARRAY_SIZE_100; i++)
//    {
//        cout << arrayForInsertionBinarySearch[i] << " ";
//    }

    isSortedArray = isSorted(arrayForInsertionBinarySearch, ARRAY_SIZE);
    cout << "\n" << (isSortedArray ? "SORTED" : "NOT SORTED") << "\n";
    cout << "\n\n";
    
    out << "insBinSearch" << " " << ARRAY_SIZE << " " << (isSortedArray ? "SORTED" : "NOT SORTED") << " "
        << COMPARES << " " << MOVES << "\n";

    COMPARES = 0;

    MOVES = 0;
    
//    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    cout << "\n" << (isSorted(array, 10) ? "sorted" : "not sorted") << "\n";
    
    // =================================================================================================================================== SHELL SORT by Robert Sedgewick
    cout << "------------SHELL SORT by Robert Sedgewick------------" << "\n";
    int arrayForShellSedgewick[ARRAY_SIZE] = {0}; // {432, 356, 572, 937, 765, 709, 613, 143, 137, 148};

    //cout << "unsorted array: " << " ";
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        arrayForShellSedgewick[i] = rand() % RANDOM_RANGE;;
        // cout << arrayForShellSedgewick[i] << " ";
    }
    cout << "\n";
    
    
    
    shellSedgewickSort(arrayForShellSedgewick, ARRAY_SIZE);
    
    

//    cout << "sorted with shell sort by Sedgewick: " << " ";
//    for (size_t i = 0; i < ARRAY_SIZE_100; i++)
//    {
//        cout << arrayForShellSedgewick[i] << " ";
//    }

    isSortedArray = isSorted(arrayForShellSedgewick, ARRAY_SIZE);
    cout << "\n" << (isSortedArray ? "SORTED" : "NOT SORTED") << "\n";
    cout << "\n\n";
    
    out << "Sedgewick" << " " << ARRAY_SIZE << " " << (isSortedArray ? "SORTED" : "NOT SORTED") << " "
        << COMPARES << " " << MOVES << "\n";

    COMPARES = 0;

    MOVES = 0;
    
    // =================================================================================================================================== SHELL SORT by Thomas Nathaniel Hibbard
    cout << "------------SHELL SORT by Thomas Nathaniel Hibbard------------" << "\n";
    int arrayForShellHibbard[ARRAY_SIZE] = {0}; // {432, 356, 572, 937, 765, 709, 613, 143, 137, 148};

    //cout << "unsorted array: " << " ";
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        arrayForShellHibbard[i] = rand() % RANDOM_RANGE;;
        // cout << arrayForShellHibbard[i] << " ";
    }
    cout << "\n";
    
    
    
    shellHibbardSort(arrayForShellHibbard, ARRAY_SIZE);
    
    

//    cout << "sorted with shell sort by Hibbard: " << " ";
//    for (size_t i = 0; i < ARRAY_SIZE_100; i++)
//    {
//        cout << arrayForShellHibbard[i] << " ";
//    }

    isSortedArray = isSorted(arrayForShellHibbard, ARRAY_SIZE);
    cout << "\n" << (isSortedArray ? "SORTED" : "NOT SORTED") << "\n";
    cout << "\n\n";
    
    out << "Hibbard" << " " << ARRAY_SIZE << " " << (isSortedArray ? "SORTED" : "NOT SORTED") << " "
        << COMPARES << " " << MOVES << "\n";
    
    COMPARES = 0;

    MOVES = 0;
    
    // =================================================================================================================================== SHELL SORT by Donald L. Shell
    cout << "------------SHELL SORT by Donald L. Shell------------" << "\n";
    int arrayForShellShell[ARRAY_SIZE] = {0}; // {432, 356, 572, 937, 765, 709, 613, 143, 137, 148};

    //cout << "unsorted array: " << " ";
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        arrayForShellShell[i] = rand() % RANDOM_RANGE;;
        // cout << arrayForShellShell[i] << " ";
    }
    cout << "\n";
    
    
    
    shellShellSort(arrayForShellShell, ARRAY_SIZE);
    
    
    
//    cout << "sorted with shell sort by Shell: " << " ";
//    for (size_t i = 0; i < ARRAY_SIZE_100; i++)
//    {
//        cout << arrayForShellShell[i] << " ";
//    }

    isSortedArray = isSorted(arrayForShellShell, ARRAY_SIZE);
    cout << "\n" << (isSortedArray ? "SORTED" : "NOT SORTED") << "\n";
    cout << "\n\n";
    
    out << "Shell" << " " << ARRAY_SIZE << " " << (isSortedArray ? "SORTED" : "NOT SORTED") << " "
        << COMPARES << " " << MOVES << "\n";
    
    COMPARES = 0;

    MOVES = 0;
    
    
    out.close();
    return 0;
}

//FILE OUTPUT EXAMPLE
//selection 10000 SORTED 49995000 69625
//insertion 10000 SORTED 24675290 24675290
//radix 10000 SORTED 9999 90030
//insBinSearch 10000 SORTED 119035 25080017
//Sedgewick 10000 SORTED 86733 172753
//Hibbard 10000 SORTED 25149848 25149848
//Shell 10000 SORTED 3878504 3878504

// CONSOLE OUTPUT EXAMPLE
//------------COUNT SORT------------
//
//
//SORTED
//
//
//------------SELECTION SORT------------
//
//
//SORTED
//
//
//------------INSERTION SORT------------
//
//
//SORTED
//
//
//------------RADIX SORT------------
//
//
//SORTED
//
//
//------------BUCKET SORT------------
//
//
//SORTED
//
//
//------------INSERTION BINARY SEARCH SORT------------
//
//
//SORTED
//
//
//------------SHELL SORT by Robert Sedgewick------------
//
//
//SORTED
//
//
//------------SHELL SORT by Thomas Nathaniel Hibbard------------
//
//
//SORTED
//
//
//------------SHELL SORT by Donald L. Shell------------
//
//
//SORTED
//
//
//Program ended with exit code: 0
