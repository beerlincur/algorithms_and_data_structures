//
//  functions.cpp
//  RedBlackTree
//
//  Created by zhozh on 25.04.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#include <fstream>
#include "String.hpp"
#include "List.hpp"

using std::cout;
using std::ifstream;
using std::ofstream;

const String NOT_ENGLISH_WORD = "\nSplit: not english word in a file: ";

char* getline(istream& in) // функция для считывания одной строки из файла
{
    const int BUF_LEN = 50;

    int len = BUF_LEN;
    int i = 0;

    char* str = (char*)malloc(BUF_LEN * sizeof(char)), c;

    while (in.get(c) && c != '\n')
    {
        if (i == len)
        {
            str = (char*)realloc(str, len += BUF_LEN);
        }
        str[i++] = c;
    }

    char* rez = new char[i + 1];
    for (int j = 0; j < i; ++j)
    {
        rez[j] = str[j];
    }
    rez[i] = 0;

    free(str);
    return rez;
}

List<String>& split(String& str, List<String>& list) // разбиение строки на слова и запись этих слов в переданный список
{
    String englishWord;
    String synonym;
    
    int j = 0;
    int LAST_SPACE = 0;
    int length = str.len();
    
    for (int i = 0; i < length; i++)
    {
        if (str[i] == ' ')
        {
            switch (j)
            {
                case 0:
                {
                    englishWord = str.substr(0, i);
                    
                    if (!englishWord.isLatin())
                    {
                        throw NOT_ENGLISH_WORD + englishWord + "\n";
                    }
                    
                    break;
                }
                    
                default:
                {
                    synonym = str.substr(LAST_SPACE + 1, i);
                    
                    if (!synonym.isLatin())
                    {
                        throw NOT_ENGLISH_WORD + synonym + "\n";
                    }
                    
                    list += synonym;
                    break;
                }
                    
            }
            
            j++;
            LAST_SPACE = i;
        }
    }
    
    synonym = str.substr(LAST_SPACE + 1, length);
    
    if (!synonym.isLatin())
    {
        throw NOT_ENGLISH_WORD + synonym + "\n";
    }
    
    list += synonym;
        
    list.pushFront(englishWord);
    
    return list;
}
