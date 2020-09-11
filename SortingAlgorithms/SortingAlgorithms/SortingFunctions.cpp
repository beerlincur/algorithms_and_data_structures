//
//  SortingFunctions.cpp
//  SortingAlgorithms
//
//  Created by zhozh on 22.03.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//
#include "List.hpp"
#include <cmath>

extern int COMPARES;

extern int MOVES;


// ============================================================================================ SELECTION SORT
void selectionSort(int *array, int size) // функция сортировки прямым выбором
{
    int minimum = 0; // минимальный элемент
    
    for (int i = 0; i < size - 1; i++)
    {
        minimum = i; // запоминаем индекс текущего элемента
        
        // ищем минимальный элемент, чтобы поместить на место i-ого
        for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
        {
            COMPARES++;
            if (array[j] < array[minimum]) // если элемент меньше минимального
            {
                minimum = j; // запоминаем его индекс в min
                MOVES++;
            }
            
        }
        
        
        int temp = array[i];      // меняем местами i-ый и минимальный элементы
        array[i] = array[minimum];
        array[minimum] = temp;
        MOVES++;
    }
}

// ============================================================================================ INSERTION SORT
void insertionSort(int* array, int size) // функция сортировки простыми вставками
{
    for (int i = 1; i < size; i++) // идем по неотсортированной части
    {
        for (int j = i; j > 0 && array[j-1] > array[j]; j--) // ищем место в отсортированной части
        {
            COMPARES++;
            int temp = array[j-1]; // вставляем элемент
            array[j-1] = array[j];
            array[j] = temp;
            MOVES++;
        }
    }
}


// ============================================================================================ COUNT SORT
void countSort(int* array, int size, int exp)
{
    int result[size]; // массив для результата сортировки
    
    int i = 0; // переменная цикла
    
    int count[10] = {0}; // массив счетчиков
  
    for (i = 0; i < size; i++) // частотный анализ
    {
        count[ (array[i] / exp) % 10 ]++;
        MOVES++;
    }
  
    for (i = 1; i < 10; i++) // изменяем count[i] так, чтобы count[i] содержал действительную позицию цифры для вывода
    {
        count[i] += count[i - 1];
        MOVES++;
    }
  
    for (i = size - 1; i >= 0; i--) // формируем результирующий массив
    {
        result[count[ (array[i] / exp) % 10 ] - 1] = array[i];
        MOVES++;
        count[ (array[i] / exp) % 10 ]--;
    }
  
    for (i = 0; i < size; i++) // переносим данные из результирующего массива в исходный
    {
        array[i] = result[i];
        MOVES++;
    }
}

// ============================================================================================ RADIX SORT
void radixSort(int* array, int size)
{
    int maximum = array[0]; // устанавливаем значение максимума - первый элемент
    
    for (int i = 1; i < size; i++) // находим максимальный элемент, чтобы узнать кол-во разрядов
    {
        COMPARES++;
        if (array[i] > maximum)
        {
            maximum = array[i];
            MOVES++;
        }
    }
  
    // exp - 10^i, где i номер текущего разряда
    
    for (int exp = 1; maximum / exp > 0; exp *= 10) // выполняем сортировку подсчетом по каждому разряду
    {
        countSort(array, size, exp);
    }
}

// ============================================================================================ BUCKET SORT
void bucketSort(float *array, int size)
{
    List<float>* buckets = new List<float>[size]; // список карманов
    
    for (int i = 0; i < size; i++)
    {
        buckets[int(size*array[i])] += array[i]; // заполняем карманы (оператор += - сортирующее добавление)
        MOVES++;
    }

    int index = 0;
    for (int i = 0; i < size; i++) // перезаписываем в исходный массив "выворачивая" карманы
    {
        while(!buckets[i].isEmpty())
        {
            array[index++] = buckets[i].popFront();
            MOVES++;
        }
    }
}

// ============================================================================================ INSERTION SORT WITH BINARY SEARCH
void insertionBinarySearchSort(int* array, int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = array[i]; // захватываем текущий элемент
        
        int left = 0; // тк отсортированная часть слева, всегда начинаем с нуля
        int right = i; // конец отсортированной части - текущий элемент
        
        while (left < right) // выполняем бинарный поиск места для вставки в отсортированной части
        {
            int middle = (right + left) / 2; // середина
            
            COMPARES++;
            if (key < array[middle]) // сравнение со средним элементом
            {
                right = middle; // если текущий элемент меньше, то сдвигаем правую границу
            }
            else
            {
                left = middle + 1; // если больше либо равен - левую
            }
        }
        
        for (int j = i; j > left; --j) // сдвигаем все элементы массива (до найденной позиции) вправо
        {
            array[j] = array[j-1];
            MOVES++;
        }
        
        array[left] = key; // вставляем элемент в найденное место
        MOVES++;
    }
}

// ============================================================================================ SHELL SORT by Robert Sedgewick
int sedgewickIncrement(int* increments, long size) // функция для вычисления инкрементов по Седжвику
{
    int p1 = 1; // параметры для формулы Седжвика
    int p2 = 1;
    int p3 = 1;
    
    int s = -1; // размер массива инкрементов
    
    do // заполняем массив элементов по формулам Седжвика
    {
        if (++s % 2) // проверка номера инкремента на четность
        {
            increments[s] = 8 * p1 - 6 * p2 + 1; // если четный
        }
        else
        {
            increments[s] = 9 * p1 - 9 * p3 + 1; // если нечетный
            p2 *= 2;
            p3 *= 2;
        }
        
        MOVES++;
        COMPARES++;
        
        p1 *= 2;

    } while (3 * increments[s] < size); // заполняем массив, пока текущия инкремент хотя бы в 3 раза меньше количества элементов в массиве
    
    COMPARES++;

    return (s > 0 ? --s : 0); // возвращаем количество элементов в массиве
}


void shellSedgewickSort(int* array, long size)
{
    int increments[40] = {0}; // массив инкрементов
    
    int s = sedgewickIncrement(increments, size); // заполняем массив инкрементов и получаем его размер
    
    while (s >= 0) // пока есть инкременты
    {
        int increment = increments[s--]; //извлекаем из массива очередной инкремент

        for (int i = increment; i < size; i++) // сортировка вставками с текущим инкрементом
        {
            int temp = array[i];
            
            int j = 0;
            for (j = i - increment; j >= 0 && array[j] > temp; j -= increment) // сдвигаем элементы до тех пор, пока не дойдем до конца или не упорядочим в нужном порядке
            {
                COMPARES++;
                array[j + increment] = array[j];
                MOVES++;
            }

            array[j + increment] = temp; // вставляем элемент в нужное место
            MOVES++;
        }
    }
}

// ============================================================================================ SHELL SORT by Thomas Nathaniel Hibbard
void shellHibbardSort(int* array, int size)
{
    for (int i = 1; i < size; i++)
    {
        int increment = exp2(i) - 1; // вычисляем текущий инкремент по формуле Хиббарда
        
        if (increment <= size) // проверка, что текущий инкремент не превосходит размер массива
        {
        
            for (int k = 0; k < size - increment; k++) // сортировка вставками с текущим инкрементом
            {
                int j = k;
                while (j >= 0 && array[j] > array[j + increment])
                {
                    COMPARES++;
                    int temp = array[j];
                    array[j] = array[j + increment];
                    array[j + increment] = temp;
                    MOVES++;
                    j--;
                }
            }
        }
    }
}

// ============================================================================================ SHELL SORT by Donald L. Shell
void shellShellSort(int* array, int size)
{
    int increment = size / 2; // вычисляем начальный инкремент по формуле Шелла
 
    while (increment > 0) // пока инкремент больше 0
    {
        for (int i = 0; i < size - increment; i++) // сортировка вставками с текущим инкрементом
        {
            int j = i;
            while (j >= 0 && array[j] > array[j + increment])
            {
                COMPARES++;
                int temp = array[j];
                array[j] = array[j + increment];
                array[j + increment] = temp;
                MOVES++;
 
                j--;
            }
        }
        
        increment = increment / 2; // уменьшаем значение текущего инкремента
    }
}
