//
//  String.cpp
//  RedBlackTree
//
//  Created by zhozh on 25.04.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#include "String.hpp"

using std::ostream;
using std::istream;
using std::cout;

const String WRONG_INDEX = "String: Trying to take an element with wrong index.";

String::String()
{
    length_ = 0;
    data_ = new char[0];
}

String::String(char c)
{
    length_ = 1;
    data_ = new char(c);
}

String::String(const char* cPtr)
{
    if (cPtr)
    {
        unsigned num = 0;
        while (cPtr[num] != '\0')
        {
            num++;
        }
        length_ = num;
        data_ = new char[num];
        for (size_t j = 0; j < num; j++)
        {
            data_[j] = cPtr[j];
        }
    }
    else
    {
        length_ = 0;
        data_ = new char[0];
    }
}

String::String(const String& str)
{
    length_ = str.len();
    data_ = new char[length_];
    for (size_t j = 0; j < length_; j++)
    {
        data_[j] = str[j];
    }
}

unsigned String::len() const // метод для получения длины строки
{
    return length_;
}

int String::index(char c) const // метод для получения индекса элемента строки
{
    for (size_t j = 0; j < length_; j++)
    {
        if (data_[j] == c)
        {
            return (int)j;
        }
    }
    return -1;
}

void String::upcase(unsigned first, unsigned last) // к верхнему регистру
{
    if ((first >= last) || (last > length_))
    {
        throw WRONG_INDEX;
    }

    for (size_t j = first; j < last; j++)
    {
        if ('a' <= data_[j] && data_[j] <= 'z')
        {
            data_[j] -= ('a' - 'A');
        }
    }
}

void String::downcase(unsigned first, unsigned last) // к нижнему регистру
{
    if ((first >= last) || (last > length_))
    {
        throw WRONG_INDEX;
    }

    for (size_t j = first; j < last; j++)
    {
        if ('A' <= data_[j] && data_[j] <= 'Z')
        {
            data_[j] += ('a' - 'A');
        }
    }
}

void String::togglecase(unsigned first, unsigned last) // верхние к нижнему, нижние к верхнему
{
    if ((first >= last) || (last > length_))
    {
        throw WRONG_INDEX;
    }

    for (size_t j = first; j < last; j++)
    {
        if ('A' <= data_[j] && data_[j] <= 'Z')
        {
            data_[j] += ('a' - 'A');
        }
        else if ('a' <= data_[j] && data_[j] <= 'z')
        {
            data_[j] -= ('a' - 'A');
        }
    }
}

String String::substr(const unsigned first, const unsigned last) // получение подстроки
{
    if ((first >= last) || (last > length_))
    {
        return "";
    }


    String res;
    res.data_ = new char[last - first];
    for (size_t i = first; i < last; i++)
    {
        res.data_[i - first] = data_[i];
    }
    
        
    res.length_ = last - first;
    return res;

}

String String::substr(const unsigned first)
{
    if (first >= length_)
    {
        return "";
    }

    String res;
    res.data_ = new char[length_ - first];
    for (size_t i = first; i < length_; i++)
    {
        res.data_[i - first] = data_[i];
    }
    
    res.length_ = length_ - first;
    return res;
}

bool String::isEmpty() const // проверка на пустоту
{
    return (length_ == 0);
}


ostream& operator<< (ostream& os, const String& str) // вывод
{
    if (str.len() > 0)
    {
        for (size_t j = 0; j < str.len(); j++)
        {
            os << str[j];
        }
    }
    else
    {
        os << "";
    }

    return os;
}

istream& operator>> (istream& is, String& str) // ввод
{
    char* ch = new char[1000];
    is >> ch;
    str = String(ch);
    delete[] ch;
    
    return is;
}

char String::operator[] (unsigned j) const // получение элемента строки по индексу
{
    if (j > length_)
    {
        throw WRONG_INDEX;
    }
    return data_[j];
}

char& String::operator[] (unsigned j)
{
    if (j > length_)
    {
        throw WRONG_INDEX;
    }
    return data_[j];
}

String& String::operator= (const String& str) // присваивание
{
    if (this == &str)
    {
        return *this;
    }

    delete[] data_;
    length_ = str.len();
    data_ = new char[length_];
    for (size_t j = 0; j < length_; j++)
    {
        data_[j] = str[j];
    }
    return *this;
}

int String::toInt() // приведение строки к целому числу
{
    int pw = 1;
    int res = 0;
    for (int i = length_ - 1; i >= 0; i--)
    {
        res += (data_[i] - '0') * pw;
        pw *= 10;
    }
    return res;
}

String& String::operator+= (const String& s) // +=
{
    unsigned len = length_ + s.len();
    char* str = new char[len];

    for (size_t j = 0; j < length_; j++)
    {
        str[j] = data_[j];
    }

    for (size_t i = 0; i < s.len(); i++)
    {
        str[length_ + i] = s[i];
    }

    delete[] data_;
    length_ = len;
    data_ = str;
    return *this;
}


String operator+ (const String& left, const String& right) // конкатенация строк
{
    return String(left) += right;
}

String operator+ (const String& left, char right)
{
    return String(left) += String(right);
}

String operator+ (const String& left, const char* right)
{
    return String(left) += String(right);
}

String operator+ (char left, const String& right)
{
    return String(left) += right;
}
String operator+ (const char* left, const String& right)
{
    return String(left) += right;
}



bool operator== (const String& left, const String& right) // проверка на равенство
{
    if (left.len() != right.len())
    {
        return false;
    }

    unsigned cap = left.len();
    unsigned n = 0;
    while ((n < cap) && (left[n] == right[n]))
    {
        n++;
    }
    return (n == cap);
}

bool operator== (const String& left, char right)
{
    return (left == String(right));
}

bool operator== (const String& left, const char* right)
{
    return (left == String(right));
}

bool operator== (char left, const String& right)
{
    return (String(left) == right);
}

bool operator== (const char* left, const String& right)
{
    return (String(left) == right);
}



bool operator> (const String& left, const String& right) // больше
{
    unsigned cap = (left.len() < right.len()) ? left.len() : right.len();
    unsigned n = 0;
    while ((n < cap) && (left[n] == right[n]))
    {
        n++;
    }
    if (n == cap)
    {
        return (left.len() > right.len());
    }

    if ((('A' <= left[n] && left[n] <= 'Z') || ('a' <= left[n] && left[n] <= 'z')) &&
        (('A' <= right[n] && right[n] <= 'Z') || ('a' <= right[n] && right[n] <= 'z')))
    {
        char A = (left[n] & ~32);
        char B = (right[n] & ~32);
        if (A != B)
        {
            return (A > B);
        }
    }
    return left[n] > right[n];
}

bool operator> (const String& left, char right)
{
    return (left > String(right));
}

bool operator> (const String& left, const char* right)
{
    return (left > String(right));
}

bool operator> (char left, const String& right)
{
    return (String(left) > right);
}

bool operator> (const char* left, const String& right)
{
    return (String(left) > right);
}



bool operator!= (const String& left, const String& right) // проверка на неравенство
{
    return !(left == right);
}

bool operator!= (const String& left, char right)
{
    return !(left == right);
}

bool operator!= (const String& left, const char* right)
{
    return !(left == right);
}

bool operator!= (char left, const String& right)
{
    return !(left == right);
}

bool operator!= (const char* left, const String& right)
{
    return !(left == right);
}



bool operator< (const String& left, const String& right) // меньше
{
    return !(left == right) && !(left > right);
}

bool operator< (const String& left, char right)
{
    return !(left == right) && !(left > right);
}

bool operator< (const String& left, const char* right)
{
    return !(left == right) && !(left > right);
}

bool operator< (char left, const String& right)
{
    return !(left == right) && !(left > right);
}

bool operator< (const char* left, const String& right)
{
    return !(left == right) && !(left > right);
}



bool operator<= (const String& left, const String& right) // меньше либо равно
{
    return !(left > right);
}

bool operator<= (const String& left, char right)
{
    return !(left > right);
}

bool operator<= (const String& left, const char* right)
{
    return !(left > right);
}

bool operator<= (char left, const String& right)
{
    return !(left > right);
}

bool operator<= (const char* left, const String& right)
{
    return !(left > right);
}



bool operator>= (const String& left, const String& right) // больше либо равно
{
    return (left == right) || (left > right);
}

bool operator>= (const String& left, char right)
{
    return (left == right) || (left > right);
}

bool operator>= (const String& left, const char* right)
{
    return (left == right) || (left > right);
}

bool operator>= (char left, const String& right)
{
    return (left == right) || (left > right);
}

bool operator>= (const char* left, const String& right)
{
    return (left == right) || (left > right);
}

bool String::isLatin() const // проверка строки на латинские символы
{
    for (int i = 0; i < length_; i++)
    {
        if (data_[i] < 'a' || data_[i] > 'z')
        {
            return false;
        }
    }
    
    return true;
}

bool String::isCorrectAmount() const // прроверка строки на наличие числа от 1 до 9
{
    return ((data_[0] > '0' && data_[0] < '10') ? true : false);
}

String::~String() // очистка памяти
{
    delete[] data_;
}
