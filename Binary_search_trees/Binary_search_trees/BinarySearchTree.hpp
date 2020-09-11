//
//  BinarySearchTree.hpp
//  Binary_search_trees
//
//  Created by zhozh on 01.03.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>
#include <iostream>
#include "BinarySearchTreeExceptions.hpp"

using std::ostream;
using std::max;
using std::cout;

template <class T>
class BinarySearchTree
{
public:
    
    // порядок объявления и определения методов соответствует порядку в задании
    // (под 'заданием' подразумевается пункт №4 - реализовать следующие возможности
    
    // public методы, указанные в задании, доступные пользователю для:
    
    BinarySearchTree (); // создания пустого дерева
    
    void insert(const T& key); // итеративного добавления нового элемента в дерево
    
    bool iterativeSearch(const T& key)  const; // итеративного поиска по ключу
    
    int findSuccsessor(const int data) const; // итеративного поиска следующего по значению
    
    int getCount() const; // рекурсивного подсчета узлов дерева
    
    int getHeight() const; // рекурсивного подсчета высоты дерева
    
    virtual ~BinarySearchTree (); // освобождения памяти
    
    bool deleteKey(const T& key); // удаления ключа
    
    T& searchByIndex(const int index) const; // рекурсивного поиска по номеру
    
    // public методы, не указанные в задании
    
    int getCountLessThan(const T& data) const; // рекурсивного подсчета узлов, ключи которых меньше заданного параментра
    
    int findMin() const; // итеративного поиска минимального значения
    
    int findMax() const; // итеративного поиска максимального значения
    
    void print(ostream& out) const; // вывода дерева на экран
    
    void printInOrder() const; // вывода дерева на экран в виде сортированного массива
    
private:
    
    struct Node // интерфейс узла
    {
        T key_;
        Node* left_;
        Node* right_;
        Node* p_;
        int index_;
        
        Node (const T& key = T(), Node* left = nullptr, Node* right = nullptr, Node* p = nullptr, int index = -1) :
            key_(key),
            index_(index),
            left_(left),
            right_(right),
            p_(p)
        {}
        
        Node (Node& other) :
            key_(other->key_),
            index_(other->index_),
            left_(other->left_),
            right_(other->right_),
            p_(other->p_)
        {}
    };
    
    Node* root_;
    
    // private (рабочие) методы, указанные в задании, используемые только внутри класса BinarySearchTree для:
    
    void insertNode(Node* node); // добавления узла

    Node* iterativeSearchNode(const T& key) const; // поиска по ключу
    
    Node* findSuccsessorNode(const T& data) const; // нахождения узла, следующего по значению
    
    int getCountSubTree(Node* node) const; // подсчета узлов поддерева

    int getHeightSubTree(Node* node) const; // подсчет высоты поддерева

    void deleteSubtree(Node* node); // удаления поддерева

    bool deleteNode(Node* node); // удаления узла
    
    Node* searchNodeByIndex(Node* node, const int index, Node* forCount) const; // поиска по номеру
        
    // private методы, не указанные в задании
    
    int getCountSubTreeLessThan(Node* node, const T &data) const; // подсчета узлов, меньших чем параметр
        
    Node* findMinNode(Node* node) const; // нахождения узла с минимальным значением
    
    Node* findMaxNode(Node* node) const; // нахождения узла с максимальным значением
    
    void printNode(ostream& out, Node* root) const; // вывода узла на экран
    
    void inorderWalk(Node* node) const; // вывода поддерева на экран в виде сортированного массива
        
    
};

// ---------------------------------------- реализация public методов --------------------------------------- //

template <class T>
BinarySearchTree<T>::BinarySearchTree() : // пустое дерево
    root_(nullptr)
{}

template <class T>
void BinarySearchTree<T>::insert(const T& key) // добавление нового
{
    insertNode(new Node(key));
}

template <class T>
bool BinarySearchTree<T>::iterativeSearch(const T& key) const // поиск по ключу
{
    return (iterativeSearchNode(key) != nullptr);
}

template <class T>
int BinarySearchTree<T>::findSuccsessor(const int data) const // поиск следующего за
{
    Node* successor = findSuccsessorNode(data);
    return ((successor == nullptr) ? 0 : successor->key_);
}

template <class T>
int BinarySearchTree<T>::getCount() const // количество узлов
{
    return getCountSubTree(this->root_);
}

template <class T>
int BinarySearchTree<T>::getHeight() const // высота дерева
{
    return getHeightSubTree(this->root_);
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() // освобождение памяти
{
    deleteSubtree(this->root_);
}

template <class T>
bool BinarySearchTree<T>::deleteKey(const T& key) // удаление по ключу
{
    Node* toDelete = iterativeSearchNode(key);
    
    return deleteNode(toDelete);
}

template <class T>
T& BinarySearchTree<T>::searchByIndex(const int index) const // поиск по номеру
{
    Node* forCount = new Node();
    Node* result = searchNodeByIndex(this->root_, index, forCount);
    
    if (result == nullptr)
    {
        throw IndexOutOfRange();
    }
    
    delete forCount;
    
    return result->key_;
}

template <class T>
int BinarySearchTree<T>::getCountLessThan(const T& data) const // кол-во меньших чем
{
    return getCountSubTreeLessThan(this->root_, data);
}

template <class T>
int BinarySearchTree<T>::findMin() const // минимальный элемент
{
    Node* min = findMinNode(this->root_);
    
    return ((min == nullptr) ? 0 : findMinNode(this->root_)->key_);
}

template <class T>
int BinarySearchTree<T>::findMax() const // максимальный элемент
{
    Node* max = findMaxNode(this->root_);
    
    return ((max == nullptr) ? 0 : findMaxNode(this->root_)->key_);
}

template <class T>
void BinarySearchTree<T>::print(ostream& out) const // вывод дерева на экран
{
    printNode(out, this->root_);
    out << "\n";
}

template <class T>
void BinarySearchTree<T>::printInOrder() const // вывод отсортированного дерева на экран
{
    inorderWalk(this->root_);
}
// --------------------------------------- реализация private методов --------------------------------------- //

template <class T>
void BinarySearchTree<T>::insertNode(Node* node) // добавление нового узла
{
    Node* current = this->root_;
    Node* parent = nullptr;
    
    while (current != nullptr)
    {
        parent = current;
        
        if (current->key_ == node->key_)
        {
            return;
        }
        
        current = (node->key_ < current->key_) ? current->left_ : current->right_;
    }
    
    node->p_ = parent;
    
    if (parent == nullptr)
    {
        this->root_ = node;
    }
    else
    {
        if (node->key_ < parent->key_)
        {
            parent->left_ = node;
        }
        else
        {
            parent->right_ = node;
        }
    }
}

template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::iterativeSearchNode(const T& key) const // поиск узла по ключу
{
    Node* current = this->root_;
    
    while (current != nullptr && current->key_ != key)
    {
        current = (key < current->key_) ? current->left_ : current->right_;
    }
    
    return current;
}

template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findSuccsessorNode(const T& data) const // ключ, следующий за
{
    Node* current = iterativeSearchNode(data);
    Node* successor = nullptr;
    
    if (current == nullptr)
    {
        return nullptr;
    }
    
    if (current->right_ != nullptr)
    {
        return findMinNode(current->right_);
    }
    
    successor = current->p_;
    
    while (successor != nullptr && current == successor->right_)
    {
            current = successor;
            successor = successor->p_;
    }
    
    return successor;
}

template <class T>
int BinarySearchTree<T>::getCountSubTree(Node* node) const // количество узлов поддерева
{
    if (node == nullptr)
    {
        return 0;
    }
    
    return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
}

template <class T>
int BinarySearchTree<T>::getHeightSubTree(Node* node) const // высота поддерева
{
    int leftHeight = 0;
    int rightHeight = 0;
    
    if (node == nullptr)
    {
        return 0;
    }
    
    if (node->left_)
    {
        leftHeight = getHeightSubTree(node->left_);
    }
    
    if (node->right_)
    {
        rightHeight = getHeightSubTree(node->right_);
    }
    
    return (max(leftHeight, rightHeight) + 1);
}

template <class T>
void BinarySearchTree<T>::deleteSubtree(Node* node) // удаление поддерева
{
    if (node != nullptr)
    {
        deleteSubtree(node->left_);
        deleteSubtree(node->right_);
        
        free(node);
        node = nullptr;
    }
}

template <class T>
bool BinarySearchTree<T>::deleteNode(Node *node) // удаление узла
{
    if (node == nullptr)
    {
        return false;
    }
    
    Node* toDelete = nullptr;
    Node* deleterChild = nullptr;
    
    toDelete = (node->left_ == nullptr || node->right_ == nullptr) ? node : findSuccsessorNode(node->key_);
    
    deleterChild = (toDelete->left_ != nullptr) ? toDelete->left_ : toDelete->right_;
    
    
    if (deleterChild != nullptr)
    {
        deleterChild->p_ = toDelete->p_;
    }
    
    if (toDelete->p_ == nullptr)
    {
        this->root_ = deleterChild;
    }
    else
    {
        if (toDelete == (toDelete->p_)->left_)
        {
            (toDelete->p_)->left_ = deleterChild;
        }
        else
        {
            (toDelete->p_)->right_ = deleterChild;
        }
    }
    
    node->key_ = (toDelete != node) ? toDelete->key_ : node->key_;
    
    return true;
    
}

template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::searchNodeByIndex(Node* node, const int index, Node* forCount) const // поиск по номеру
{
    
    if (node == nullptr)
    {
        return nullptr;
    }
    
    Node* leftResult = searchNodeByIndex(node->left_, index, forCount);
    
    if (leftResult != nullptr && leftResult->index_ == index) // если из левого поддерева вернулся узел с нужным номером,
    {                                                        //  то 'проталкиваем' его дальше навверх
        return leftResult;
    }
    
    forCount->index_++; // инкремент аккумулятора (сквозного счетчика)
    
    node->index_ = forCount->index_; // запись текущего значения аккумулятора в поле индекса текущего узла
    
    Node* rightResult = searchNodeByIndex(node->right_, index, forCount);
    
    if (rightResult != nullptr && rightResult->index_ == index) // если из правого поддерева вернулся узел с нужным номером,
    {                                                          //  то 'проталкиваем' его дальше навверх
        return rightResult;
    }
    
    if (this->root_ == node && node->index_ != index) // если рекурсия обошла все дерево (включая корень) и не нашла нужный номер, поиск завершается
    {                                                //  если узел с искомым номером это корень, то вернется сам корень
        return nullptr;
    }
    
    return node; // передача 'навверх' текущего узла
}



template <class T>
int BinarySearchTree<T>::getCountSubTreeLessThan(Node* node, const T &data) const // кол-во узлов, меньших чем
{
    if (node == nullptr)
    {
        return 0;
    }
    
    return (((node->key_ < data) ? 1 : 0) + getCountSubTreeLessThan(node->left_, data) + getCountSubTreeLessThan(node->right_, data));
}

template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findMinNode(Node* node) const // минимум
{
    if (this->root_ == nullptr)
    {
        return nullptr;
    }
    
    while(node->left_ != nullptr)
    {
        node = node->left_;
    }
    
    return node;
}

template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findMaxNode(Node* node) const // максимум
{
    if (this->root_ == nullptr)
    {
        return nullptr;
    }
    
    while(node->right_ != nullptr)
    {
        node = node->right_;
    }
    
    return node;
}

template <class T>
void BinarySearchTree<T>::printNode(ostream& out, Node* root) const // вывод поддерева
{
    out << '(';
    
    if (root)
    {
        out << root->key_;
        printNode(out, root->left_);
        printNode(out, root->right_);
    }
    
    out << ')';
}

template <class T>
void BinarySearchTree<T>::inorderWalk(Node* node) const // вывод отсортированного поддерева
{
    if (node != nullptr)
    {
        inorderWalk(node->left_);
        
        cout << node->key_<< " ";
        
        inorderWalk(node->right_);
    }
}

#endif /* BinarySearchTree_hpp */
