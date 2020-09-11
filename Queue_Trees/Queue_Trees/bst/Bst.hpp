//
//  Bst.hpp
//  Queue_Trees
//
//  Created by zhozh on 18.03.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef Bst_hpp
#define Bst_hpp

#include <stdio.h>
#include "BstExceptions.hpp"
#include "QueueList.hpp"
#include "StackList.hpp"

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
    
    void printLevelWolk(); // вывода дерева по уровням
    
    void printIterativWolk(); // вывода дерева в виде отсортированной последовательности (обход слева-направо)
    
    bool isSameWith(const BinarySearchTree<T>& rhs); // сравнения деревьев на равенство по ключам
    
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
    
    void levelWolk(Node* node); // итеративный обход в ширину
    
    void iterativWolkWithStack(Node* node); // итеративный обход слева-направо
    
    bool isSameTrees(const BinarySearchTree<T>& rhs); // итеративная проверка на равенство
    
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
    return ((successor == nullptr) ? -1 : successor->key_);
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

template <class T>
void BinarySearchTree<T>::printLevelWolk() // вывод по уровням
{
    levelWolk(this->root_);
}

template <class T>
void BinarySearchTree<T>::printIterativWolk() // вывод отсортированного дерева
{
    iterativWolkWithStack(this->root_);
}

template <class T>
bool BinarySearchTree<T>::isSameWith(const BinarySearchTree<T>& rhs) // проверка на равенство
{
    return isSameTrees(rhs);
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
    Node* successor = nullptr;
    Node* current  = this->root_;
    
    if (!this->root_)
    {
        return nullptr;
    }
    
    while (current->key_ != data)
    {
        if (current->key_ > data)
        {
          successor = current;
          current= current->left_;
        }
        else
        {
          current = current->right_;
        }
    }
    
    if (current && current->right_)
    {
        successor = findMinNode(current->right_);
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
        
        delete node;
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
void BinarySearchTree<T>::inorderWalk(Node* node) const // рекурсивный обход слева-направо
{
    if (node != nullptr)
    {
        inorderWalk(node->left_);
        
        cout << node->key_<< " ";
        
        inorderWalk(node->right_);
    }
}

template <class T>
void BinarySearchTree<T>::levelWolk(Node* node) // итеративный обход дерева в ширину с использованием очереди
{
    QueueList<Node*> queue;
    
    queue.enQueue(node);

    Node* current;

    while(!queue.isEmpty())
    {
        current = queue.deQueue();
        cout << current->key_ << " ";

        if (current->left_ != nullptr)
        {
            queue.enQueue(current->left_);
        }
        
        if (current->right_ != nullptr)
        {
            queue.enQueue(current->right_);
        }
    }
}

template <class T>
void BinarySearchTree<T>::iterativWolkWithStack(Node* node) // итеративный обход слева-направо с использованием стека
{
    StackList<Node*> stack;
    
    while (!stack.isEmpty() || node != nullptr)
    {
        if (node != nullptr)
        {
            stack.push(node);
            node = node->left_;
        }
        else
        {
            node = stack.pop();
            cout << node->key_ << " ";
            node = node->right_;
        }
    }
}

template <class T>
bool BinarySearchTree<T>::isSameTrees(const BinarySearchTree<T>& rhs) // итеративная проверка деревьев на равенство с использованием стеков
{
    if (rhs.root_ == this->root_)
    {
        return true;
    }
    
    StackList<Node*> stackLeft;
    StackList<Node*> stackRight;
    
    Node* currentLeft = this->root_;
    Node* currentRight = rhs.root_;
    
    while ((!stackLeft.isEmpty() || currentLeft != nullptr) && (!stackRight.isEmpty() || currentRight != nullptr))
    {
        if (currentLeft != nullptr)
        {
            stackLeft.push(currentLeft);
            currentLeft = currentLeft->left_;
        }
        
        if (currentRight != nullptr)
        {
            stackRight.push(currentRight);
            currentRight = currentRight->left_;
        }
        
        if ((currentLeft == nullptr) && (currentRight == nullptr))
        {
            currentLeft = stackLeft.pop();
            currentRight = stackRight.pop();
            
            if (currentLeft->key_ != currentRight->key_)
            {
                return false;
            }
            
            currentLeft = currentLeft->right_;
            currentRight = currentRight->right_;
        }
        
    }
    
    return stackLeft.isEmpty() && stackRight.isEmpty();
}


#endif /* Bst_hpp */

