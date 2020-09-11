//
//  String.hpp
//  RedBlackTree
//
//  Created by zhozh on 25.04.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef String_hpp
#define String_hpp

#include <iostream>

using std::ostream;
using std::istream;

class String
{
    char* data_;
    unsigned length_;
        
public:
    String ();
    String(char cr);
    String(const char* cPtr);
    String(const String& str);

    int toInt();
    bool isEmpty() const;
    unsigned len() const; // получение длины
    int index(char c) const; // получение индекса элемента
    char& operator[] (unsigned j);
    String substr(const unsigned first);
    String substr(const unsigned first, const unsigned last);
    char  operator[] (unsigned j) const;
    String& operator= (const String& str); // присваивание
    String& operator+= (const String& str); // +=
    void upcase(unsigned first, unsigned last); // к верхнему регистру
    void downcase(unsigned first, unsigned last); // к нижнему регистру
    void togglecase(unsigned first, unsigned last); // верхние - к нижнему и наоборот
    bool isLatin() const; // проверка на латинские символы
    bool isCorrectAmount() const; // проверка строки на наличие числа от 1 до 9

    friend ostream& operator<< (ostream& os, const String& str); //вывод
    friend istream& operator>> (istream& is, String& str); //ввод

    friend String operator+ (const String& left, const String& right); // сложение
    friend String operator+ (const String& left, char          right);
    friend String operator+ (const String& left, const char*   right);
    friend String operator+ (char          left, const String& right);
    friend String operator+ (const char*   left, const String& right);

    friend bool operator==  (const String& left, const String& right); // равенство
    friend bool operator==  (const String& left, char          right);
    friend bool operator==  (const String& left, const char*   right);
    friend bool operator==  (char          left, const String& right);
    friend bool operator==  (const char*   left, const String& right);

    friend bool operator>   (const String& left, const String& right); // больше
    friend bool operator>   (const String& left, char          right);
    friend bool operator>   (const String& left, const char*   right);
    friend bool operator>   (char          left, const String& right);
    friend bool operator>   (const char*   left, const String& right);

    friend bool operator!=  (const String& left, const String& right); // не равно
    friend bool operator!=  (const String& left, char          right);
    friend bool operator!=  (const String& left, const char*   right);
    friend bool operator!=  (char          left, const String& right);
    friend bool operator!=  (const char*   left, const String& right);

    friend bool operator<   (const String& left, const String& right); // меньше
    friend bool operator<   (const String& left, char          right);
    friend bool operator<   (const String& left, const char*   right);
    friend bool operator<   (char          left, const String& right);
    friend bool operator<   (const char*   left, const String& right);

    friend bool operator<=  (const String& left, const String& right); // меньше либо равно
    friend bool operator<=  (const String& left, char          right);
    friend bool operator<=  (const String& left, const char*   right);
    friend bool operator<=  (char          left, const String& right);
    friend bool operator<=  (const char*   left, const String& right);

    friend bool operator>=  (const String& left, const String& right); // больше либо равно
    friend bool operator>=  (const String& left, char          right);
    friend bool operator>=  (const String& left, const char*   right);
    friend bool operator>=  (char          left, const String& right);
    friend bool operator>=  (const char*   left, const String& right);

    ~String();

};


#endif /* String_hpp */
