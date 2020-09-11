//
//  RBT.hpp
//  RedBlackTree
//
//  Created by zhozh on 25.04.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef RBT_hpp
#define RBT_hpp

#include "Queue.hpp"
#include "String.hpp"
#include "List.hpp"

class RBTree
{
    
public:
    
    // конкструктор
    RBTree() { root_ = nullptr; }

    // вставка ключа и значения в дерево
    RBTree& insert(const String& englishWord, List<String>* synonymicWords);
    
    // поиск по ключу
    List<String>& search(const String& englishWord) const;

    // удаление всей ячейки по ключу или удаление синонима (зависит от флага)
    bool deleteByValue(const String& englishWord, const bool isDeletingFull = true, const String& synonymicWord = "");

    // обход дерева слева направо и вывод на экран
    void printInOrder();

    // обход дерева по уровням и вывод на экран
    void printLevelOrder();

private:
    
    enum Color { RED, BLACK }; // цвета узлов
    
    class Node // интерфейс узла дерева
    {
        
    public:
        
        String key_; // ключ - английское слово
        List<String>* value_; // указатель на список синонимов
        
        Color color_; // цвет узла
        
        Node* left_; // указатель на левое поддерево
        Node* right_; // указатель на правое поддерево
        Node* parent_; // указатель на родителя
        
        // конструктор
        Node (const String& key = String(),
              List<String>* value = nullptr,
              Color color = RED,
              Node* left = nullptr,
              Node* right = nullptr,
              Node* parent = nullptr) :
        
            key_(key),
            value_(value),
            color_(color),
            left_(left),
            right_(right),
            parent_(parent)
        {}

        // возвращает указатель дядю узла или nullptr
        Node* getUncle()
        {
            // если нет родителя или дедущки, значит нет и дяди
            if (parent_ == nullptr || parent_->parent_ == nullptr)
            {
                return nullptr;
            }

            if (parent_->isOnLeft())
            {
                // дядя справа
                return parent_->parent_->right_;
            }
            else
            {
                // дядя слева
                return parent_->parent_->left_;
            }
        }

        // проверяет является ли узел левым ребенком своего родителя
        bool isOnLeft() { return this == parent_->left_; }

        // возвращает указатель на брата или nullptr
        Node* getSibling()
        {
            // если нет родителя, нет и брата
            if (parent_ == nullptr)
            {
                return nullptr;
            }

            if (isOnLeft())
            {
                // если текущий узел слева, то брат справа
                return parent_->right_;
            }

            return parent_->left_;
        }

        // перемещает текущий узел вниз и ставит переданный узел на свое место
        void moveDown (Node* nodeParent)
        {
            if (parent_ != nullptr)
            {
                if (isOnLeft())
                {
                    parent_->left_ = nodeParent;
                }
                else
                {
                    parent_->right_ = nodeParent;
                }
            }
            
            nodeParent->parent_ = parent_;
            parent_ = nodeParent;
        }
        
        // проверяет, если ли у узла хотя бы один красный ребенок
        bool hasRedChild()
        {
            return (left_ != nullptr && left_->color_ == RED) ||
                (right_ != nullptr && right_->color_ == RED);
        }
    };
    
    Node* root_; // указатель на корень дерева
    
    Node* getRoot() { return root_; } // возвращает указатель на корень дерева

    // выполняет поиск по переданному значению
    // если находит, то возвращает указатель на узел (используется при удалении)
    // если не находит, возвращает указатель на последний пройденный узел (используется при вставке)
    Node* searchNode(const String& englishWord);
    
    // выполняет поиск по переданному значению
    // если находит, возвращает указатль на узел
    // если не находит, возвращает nullptr
    Node* iterativeSearchNode(const String& englishWord) const;

    // выполняет левый поворот узла
    void leftRotate(Node *x);

    // выполняет правый поворот узла
    void rightRotate(Node *x);

    // обменивает два узла цветами
    void swapColors(Node *x1, Node *x2);

    // обменивает два узла ключами и значениями
    void swapKeysAndValues(Node *u, Node *v);

    // исправляет ситуацию, когда два красных узла идут подряд
    void fixRedRed(Node *x);

    // поиск следующего по значению
    Node* findSuccessor(Node *x);

    // ищет замещающий узел
    Node* findBstReplace(Node *x);

    // удаляет переданный узел
    void deleteNode(Node *v);

    // исправляет ситуацию, когда после удаления черного узла,
    // возникает "дважды черный" узел
    void fixDoubleBlack(Node *x);

    // обход по уровням
    void levelOrder(Node *x);

    // обход слева на право
    void inorder(Node *x);
    
};


#endif /* RBT_hpp */
