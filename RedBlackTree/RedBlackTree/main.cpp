//
//  main.cpp
//  RedBlackTree
//
//  Created by zhozh on 13.04.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#include <fstream>
#include "String.hpp"
#include "RBT.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::ifstream;
using std::istream;

// описание необходимых ошибок
const String INVALID_AMOUNT_OF_CELLS = "\nMain: invalid amount of cells!\
    It must be 1-100.\n";

const String FILE_NOT_OPEN = "\nMain: cannot open a file.\n";
const String INVALID_MENU_OPTION = "\nMain: invalid menu option,\
    please, enter only a number from a list below.\n";

const String EMPTY_FILE = "\nMain: empty input file!\n";

// текст главного интерактивного меню
const String MAIN_MENU_MESSAGE = "\n\nIt is a main menu of the program, please,\
    choose and enter a number from a list below:\n\n";

const String MAIN_MENU_OPTIONS = "1. Search\n2. Print in order\n\
    3. Print by level\n4. Insert\n5. Delete\n0. Exit\nYour choice: ";

// считывание строки из текстового файла
char* getline(istream& in);

// разбиение строки на слова и запись в переданный список
List<String>& split(String& str, List<String>& list);

int main()
{
    try
    {
        RBTree tree;

        ifstream in;
        
        // файл для считывания
        in.open("/Users/zhozh/Desktop/projects/c++/aisd/RedBlackTree/RedBlackTree/addToDictionary.txt");

        if (!in)
        {
            throw FILE_NOT_OPEN;
        }

        // считывание первой строки
        String str = getline(in);
        
        // проверка на пустоту файла
        if (str == "")
        {
            throw EMPTY_FILE;
        }
        
        String englishWord;
        
        // формирование ячейки и запись в словарь
        while (str != "")
        {

            List<String> synonymicWords;

            List<String>* toAdd;
            
            // разбиение строки на слова и проверка
            englishWord = split(str, synonymicWords).popFront();
                                                                
            toAdd = new List<String>(synonymicWords);
            
            // запись считанной ячейки в словарь
            tree.insert(englishWord, toAdd);
            
            // получение новой строки
            str = getline(in);

        }

        in.close();
        
        cout << "Dictionary was successully formed!\n";
        
        cout << "\n\n";
        
        // переменная для выбора пользователя
        int choosenOption = -1;

        while (choosenOption != 0)
        {
            
            // вывод меню на экран
            cout << MAIN_MENU_MESSAGE << MAIN_MENU_OPTIONS;

            // получение выбора пользователя
            cin >> choosenOption;

            if (choosenOption < 0 || choosenOption > 5)
            {
                cout << INVALID_MENU_OPTION;
                continue;
            }

            switch (choosenOption)
            {
                case 1:
                {
                    // слово для поиска
                    String toSearchString = "1";
                    
                    while (!toSearchString.isLatin())
                    {
                        cout << "Please, enter english word you want to search for: ";
                        
                        // получение слова для поиска
                        cin >> toSearchString;
                        
                        if (toSearchString.isLatin())
                        {
                            cout << "Here is synonyms we've found for '"
                                << toSearchString << "' in our dictionary: ";
                            
                            // вывод найденных синонимов
                            tree.search(toSearchString).show();
                        }
                        else
                        {
                            // неверное слово
                            cout << "Please, enter an english word in lowercase.\n";
                        }
                    }
                    break;
                }
                case 2:
                {
                    cout << "Dictionary in order:\n";
                    
                    // вывод упорядоченного дерева на экран
                    tree.printInOrder();
                    cout << "\n";
                    break;
                }
                case 3:
                {
                    cout << "Dictionary by level:\n";
                    
                    // вывод дерева по родословным уровням на экран
                    tree.printLevelOrder();
                    cout << "\n";
                    break;
                }
                case 4:
                {
                    // слово для вставки (английское)
                    String englishToInsert = "1";
                    
                    while (!englishToInsert.isLatin())
                    {
                        cout << "Please, enter english word you want to insert: ";
                        
                        // получение слова для вставки
                        cin >> englishToInsert;
                        
                        if (englishToInsert.isLatin())
                        {
                            // строка, содержащая количество синонимов
                            String amountOfSynonymsStr = "-1";
                            
                            
                            while (!amountOfSynonymsStr.isCorrectAmount())
                            {
                                cout << "Please, enter amount of synonyms for '"
                                    << englishToInsert << "': ";
                                
                                // получение количества синонимов
                                cin >> amountOfSynonymsStr;
                                
                                if (amountOfSynonymsStr.isCorrectAmount())
                                {
                                
                                    // перезапись в целое число
                                    int amountOfSynonymsInt = amountOfSynonymsStr.toInt();
                                    
                                    List<String> synonymsToAdd;
                                    
                                    // цикл для получения списка синонимов
                                    for (int i = 0; i < amountOfSynonymsInt; i++)
                                    {
                                        String synonymToInsert = "1";
                                        
                                        while (!synonymToInsert.isLatin())
                                        {
                                            cout << "\nPlease, enter a synonym for '"
                                                << englishToInsert << "' number "
                                                << i + 1 << ": ";
                                            
                                            cin >> synonymToInsert;
                                            
                                            if (synonymToInsert.isLatin())
                                            {
                                                synonymsToAdd += synonymToInsert;
                                            }
                                            else
                                            {
                                                // неверное слово
                                                cout << "\nPlease, enter an english word in lowercase.\n";
                                            }
                                        }
                                    }
                                    
                                    List<String>* newSynonyms = new List<String>(synonymsToAdd);
                                    
                                    // вставка в словарь
                                    tree.insert(englishToInsert, newSynonyms);
                                    
                                    cout << "Succesfully inserted '"
                                        << englishToInsert << "' | ";
                                    newSynonyms->show();
                                }
                                else
                                {
                                    // неверное количество
                                    cout << "\nPlease, enter amount of synonyms \
                                        you want to add (between 1 and 10).\n";
                                }
                            }
                        }
                        else
                        {
                            // неверное слово
                            cout << "Please, enter an english word in lowercase.\n";
                        }
                    }
                    break;
                }
                case 5:
                {
                    
                    // англ слово для удаления
                    String englishToDelete = "1";
                    
                    while (!englishToDelete.isLatin())
                    {
                        cout << "Please, enter english word you want to be deleted: ";
                        // получение слова для удаления
                        cin >> englishToDelete;
                        
                        if (englishToDelete.isLatin())
                        {
                            // флаг удаления (полностью или конкретного синонима)
                            String isDeletingFull = "1";
                            
                            while (!(isDeletingFull == "Yes" || isDeletingFull == "No"))
                            {
                                cout << "Please, enter 'Yes', \
                                    if you want to delete full cell with '"
                                    << englishToDelete
                                    << "' or enter 'No', if you want to \
                                    enter a synonym and delete only this variant: ";
                                
                                cin >> isDeletingFull;
                                
                                if (isDeletingFull == "No")
                                {
                                    // синоним для удаления
                                    String synonymToDelete = "1";
                                    
                                    while (!synonymToDelete.isLatin())
                                    {
                                        
                                        cout << "Please, enter a synonym to delete from '"
                                            << englishToDelete << "' | ";
                                        
                                        tree.search(englishToDelete).show();
                                        cout << ": ";
                                        cin >> synonymToDelete;
                                        
                                        if (synonymToDelete.isLatin())
                                        {
                                            // удаление конкретного синонима
                                            if (tree.deleteByValue(englishToDelete, false, synonymToDelete))
                                            {
                                                cout << "\n\n'"
                                                    << synonymToDelete
                                                    << "' was successully deleted from '"
                                                    << englishToDelete
                                                    << "' list of synonyms.\n";
                                                
                                                cout << "\n";
                                            }
                                            else
                                            {
                                                // безуспешное удаление синонима
                                                cout << "\n\n'"
                                                    << synonymToDelete
                                                    << "' doesn't exist in '"
                                                    << englishToDelete
                                                    << "' list of synonyms.\n";
                                            }
                                        }
                                        
                                    }
                                }
                                else if (isDeletingFull == "Yes")
                                {
                                    // удаление всей ячейки
                                    if (tree.deleteByValue(englishToDelete))
                                    {
                                        cout << "\n'"
                                            << englishToDelete
                                            << "' was successully deleted.\n";
                                        
                                        cout << "\n";
                                    }
                                    else
                                    {
                                        // безуспешное удаление
                                        cout << "\n'"
                                            << englishToDelete
                                            << "' doesn't exist in a dictionary.\n";
                                    }
                                }
                                else
                                {
                                    // неверный флаг
                                    cout << "Please, enter 'Yes' or 'No'.\n";
                                }
                            }
                            
                        }
                    }
                    break;
                }
            }
        }
        return 0;
    } // обработка ошибок
    catch (const String err)
    {
        cerr << err;
        return -1;
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
}
