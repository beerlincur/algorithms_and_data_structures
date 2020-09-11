//
//  RBT.cpp
//  RedBlackTree
//
//  Created by zhozh on 25.04.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#include "RBT.hpp"

// поиск по значению
List<String>& RBTree::search(const String& englishWord) const
{
    Node* finded = iterativeSearchNode(englishWord); // поиск узла по значению
    
    List<String> empty;
    
    return ((finded == nullptr) ? empty : (*finded->value_)); // возвращает найденный или пустой список
}

// вставка ключа и значения в дерево
RBTree& RBTree::insert(const String& englishWord, List<String>* synonymicWords)
{
    Node* newNode = new Node(englishWord, synonymicWords);
    
    if (root_ == nullptr)
    {
        // если дерево пустое
        newNode->color_ = BLACK;
            
        root_ = newNode;
    }
    else
    {
        Node* current = searchNode(englishWord); // поиск в дереве
        

        if (current->key_ == englishWord) // проверка на наличие в дереве
        {
            
            current->value_->merge(*synonymicWords); // добавление переданного списка синонимов
            
            return *this;
        }

        // если узел не был найден, то current - это место для вставки узла

        // связывает новый узел с местом для вставки
        newNode->parent_ = current;

        if (englishWord < current->key_) // вставка влево или вправо
        {
            current->left_ = newNode;
        }
        else
        {
            current->right_ = newNode;
        }

        // исправление ситуации двух красных узлов подряд
        fixRedRed(newNode);
        
    }
    
    return *this; // возврат дерева после вставки
}

// удаление всего узла или варианта синонима, зависит от флага
bool RBTree::deleteByValue(const String& englishWord, const bool isDeletingFull, const String& synonimicWord)
{
    if (root_ == nullptr)
    {
        // пустое дерево
        return false;
    }
    
    Node* toDelete = searchNode(englishWord); // поиск узла для удаления

    if (toDelete->key_ != englishWord) // если узел не найден
    {
        return false;
    }
    
    if (isDeletingFull) // если удаляется вся ячейка словаря
    {
        deleteNode(toDelete);
        return true;
    }
    else // удаление конкретного синонима
    {
        return toDelete->value_->deleteByValue(synonimicWord); // возвращает true - если удалил успешно
    }

    
}

// обход слева направо
void RBTree::printInOrder()
{
    if (root_ == nullptr)
    {
        cout << "Dictionary is empty" << "\n";
    }
    else
    {
        inorder(root_); // вызов внутренней функции
    }
}

// обход по уровням
void RBTree::printLevelOrder()
{
    if (root_ == nullptr)
    {
        cout << "Tree is empty" << "\n";
    }
    else
    {
        levelOrder(root_); // вызов внутренней функции
    }
}

// поиск узла по значению, возвращает указатель на найденный узел,
// либо указатель на последний просмотренный
RBTree::Node* RBTree::searchNode(const String& englishWord)
{
    Node* current = root_;
    
    while (current != nullptr)
    {
        if (englishWord < current->key_)
        {
            if (current->left_ == nullptr)
            {
                break;
            }
            else
            {
                current = current->left_;
            }
        }
        else if (englishWord == current->key_)
        {
            break;
        }
        else
        {
            if (current->right_ == nullptr)
            {
                break;
            }
            else
            {
                current = current->right_;
            }
        }
    }
    
    return current;
}

// поиск узла по значению, если найдено - возвращает указатель на узел,
// если нет - nullptr
RBTree::Node* RBTree::iterativeSearchNode(const String& englishWord) const // поиск узла по ключу
{
    Node* current = this->root_;
    
    while (current != nullptr && current->key_ != englishWord)
    {
        current = (englishWord < current->key_) ? current->left_ : current->right_;
    }
    
    return current;
}

// левый поворот узла
void RBTree::leftRotate(Node *x)
{
    // новый родитель - правый ребенок узла
    Node* newParent = x->right_;

    // обновление корня, если текущий узел был корнем
    if (x == root_)
    {
        root_ = newParent;
    }

    x->moveDown(newParent); // сдвиг узла вниз

    // связывает узел с левым ребенком нового родителя
    x->right_ = newParent->left_;
    
    if (newParent->left_ != nullptr)
    {
        // связывает левого ребенка нового родителя с узлом
        newParent->left_->parent_ = x;
    }

    // связывает нового родителя с узлом
    newParent->left_ = x;
}

void RBTree::rightRotate(Node *x)
{
    // новый родитель - левый ребенок узла
    Node* newParent = x->left_;

    // обновление корня, если текущий узел был корнем
    if (x == root_)
    {
        root_ = newParent;
    }

    x->moveDown(newParent); // сдвиг узла вниз

    // связывает узел с правым ребенком нового родителя
    x->left_ = newParent->right_;
    
    if (newParent->right_ != nullptr)
    {
        // связывает правого ребенка нового родителя с узлом
        newParent->right_->parent_ = x;
    }

    // связывает нового родителя с узлом
    newParent->right_ = x;
}

// обменивает цветами два узла
void RBTree::swapColors(Node *x1, Node *x2)
{
    Color temp;
    temp = x1->color_;
    x1->color_ = x2->color_;
    x2->color_ = temp;
}

// обменивает два узла ключами и значениями
void RBTree::swapKeysAndValues(Node *u, Node *v)
{
    String tempKey;
    List<String>* tempValue;
    
    tempKey = u->key_;
    u->key_ = v->key_;
    v->key_ = tempKey;
    
    tempValue = u->value_;
    u->value_ = v->value_;
    v->value_ = tempValue;
}

// исправляет ситуацию двух красных узлов подряд
void RBTree::fixRedRed(Node *x)
{
    // если это корень - просто перекрашивает в черный
    if (x == root_)
    {
        x->color_ = BLACK;
        return;
    }

    // родитель, дедушка и дядя узла
    Node* parent = x->parent_;
    Node* grandparent = parent->parent_;
    Node* uncle = x->getUncle();

    if (parent->color_ != BLACK)
    {
        if (uncle != nullptr && uncle->color_ == RED)
        {
            // uncle red, perform recoloring and recurse
            // дядя красный, значит перекрашиваем и повторяем для дедушки
            parent->color_ = BLACK;
            uncle->color_ = BLACK;
            grandparent->color_ = RED;
            fixRedRed(grandparent);
        }
        else
        {
            // в противном случае, применяем LR, LL, RL, RR
            if (parent->isOnLeft())
            {
                if (x->isOnLeft())
                {
                    // левый правый
                    swapColors(parent, grandparent);
                }
                else
                {
                    leftRotate(parent);
                    swapColors(x, grandparent);
                }
                // для левый левый и левый правый
                rightRotate(grandparent);
            }
            else
            {
                if (x->isOnLeft())
                {
                    // правый левый
                    rightRotate(parent);
                    swapColors(x, grandparent);
                }
                else
                {
                    swapColors(parent, grandparent);
                }

                // для правый правый и правый левый
                leftRotate(grandparent);
            }
        }
    }
}

// поиск следующего по значению
RBTree::Node* RBTree::findSuccessor(Node *x)
{
    Node* current = x;

    while (current->left_ != nullptr)
    {
        current = current->left_;
    }

    return current;
}

// поиск замещающего узла
RBTree::Node* RBTree::findBstReplace(Node *x)
{
    // если есть два ребенка
    if (x->left_ != nullptr && x->right_ != nullptr)
    {
        return findSuccessor(x->right_);
    }

    // если узел это лист
    if (x->left_ == nullptr && x->right_ == nullptr)
    {
        return nullptr;
    }

    // если один ребенок
    if (x->left_ != nullptr)
    {
        return x->left_;
    }
    else
    {
        return x->right_;
    }
}

// удаление узла
void RBTree::deleteNode(Node *v)
{
    Node* u = findBstReplace(v); // замещающий узел

    // true, если u и v - черные
    bool uvBlack = ((u == nullptr || u->color_ == BLACK) && (v->color_ == BLACK));
    
    Node* parent = v->parent_;

    if (u == nullptr)
    {
        // u == nullptr, значит v это лист
        if (v == root_)
        {
            // v - это корень, значит зануляем корень
            root_ = nullptr;
        }
        else
        {
            if (uvBlack)
            {
                // u и v - черные
                // v - это лист, исправляем двойную черноту для v
                fixDoubleBlack(v);
            }
            else
            {
                // u или v - красный
                if (v->getSibling() != nullptr)
                {
                    // брат существует - красим брата в красный
                    v->getSibling()->color_ = RED;
                }
            }

            // удаление v из дерева
            if (v->isOnLeft())
            {
                parent->left_ = nullptr;
            }
            else
            {
                parent->right_ = nullptr;
            }
        }
        delete v;
        return;
    }

    if (v->left_ == nullptr || v->right_ == nullptr)
    {
        // у v только один ребенок
        if (v == root_)
        {
            // v - корень, присваиваем u в v и удаляем u
            v->key_ = u->key_;
            v->value_ = u->value_;
            v->left_ = v->right_ = nullptr;
            delete u;
        }
        else
        {
            // удаление v и сдвиг u вверх
            if (v->isOnLeft())
            {
                parent->left_ = u;
            }
            else
            {
                parent->right_ = u;
            }
            
            delete v;
            u->parent_ = parent;
            
            if (uvBlack)
            {
                // u и v - черные, исправляем двойную черноту для u
                fixDoubleBlack(u);
            }
            else
            {
                // u или v - красный, красим u в черный
                u->color_ = BLACK;
            }
        }
        
        return;
    }

    // v имеет двух детей, обмениваем значениями с след. по значению и повторяем рекурсивно для u
    swapKeysAndValues(u, v);
    deleteNode(u);
}

void RBTree::fixDoubleBlack(Node *x)
{
    if (x == root_)
    {
        // достигли корня
        return;
    }

    Node* sibling = x->getSibling();
    Node* parent = x->parent_;
    
    if (sibling == nullptr)
    {
        // двойная чернота
        fixDoubleBlack(parent);
    }
    else
    {
        if (sibling->color_ == RED)
        {
            // брат - красный
            parent->color_ = RED;
            sibling->color_ = BLACK;
            
            if (sibling->isOnLeft())
            {
                // левый случай
                rightRotate(parent);
            }
            else
            {
                // правый случай
                leftRotate(parent);
            }
            
            // двойная чернота
            fixDoubleBlack(x);
        }
        else
        {
            // брат - черный
            if (sibling->hasRedChild())
            {
                // хотя бы один красный
                if (sibling->left_ != nullptr && sibling->left_->color_ == RED)
                {
                    if (sibling->isOnLeft())
                    {
                        // левый левый
                        sibling->left_->color_ = sibling->color_;
                        sibling->color_ = parent->color_;
                        rightRotate(parent);
                    }
                    else
                    {
                        // правый левый
                        sibling->left_->color_ = parent->color_;
                        rightRotate(sibling);
                        leftRotate(parent);
                    }
                }
                else
                {
                    if (sibling->isOnLeft())
                    {
                        // левый правый
                        sibling->right_->color_ = parent->color_;
                        leftRotate(sibling);
                        rightRotate(parent);
                    }
                    else
                    {
                        // правый правый
                        sibling->right_->color_ = sibling->color_;
                        sibling->color_ = parent->color_;
                        leftRotate(parent);
                    }
                }
                parent->color_ = BLACK;
            }
            else
            {
                // два черных ребенка
                sibling->color_ = RED;
                if (parent->color_ == BLACK)
                {
                    fixDoubleBlack(parent);
                }
                else
                {
                    parent->color_ = BLACK;
                }
            }
        }
    }
}

// обход по уровням
void RBTree::levelOrder(Node* x)
{
    if (x == nullptr)
    {
        // выход, если пусто
        return;
    }

    // инициализация очереди для обхода по уровням
    QueueList<Node*> q;
    Node* current;

    // запись первого считанного узла
    q.enQueue(x);

    while (!q.isEmpty())
    {
        // пока очередь не пуста
        current = q.deQueue(); // достаем из очереди

        cout << current->key_ << " "; // вывод на экран

        // запись левого ребенка в очередь
        if (current->left_ != nullptr)
        {
            q.enQueue(current->left_);
        }
        
        // запись правого ребенка в очередь
        if (current->right_ != nullptr)
        {
            q.enQueue(current->right_);
        }
    }
}

// обход дерева слева направо
void RBTree::inorder(Node* x)
{
    // выход, если пусто
    if (x == nullptr)
    {
        return;
    }
    
    // рекурсивный вызов для левого ребенка
    inorder(x->left_);
    
    // вывод на экран
    cout << x->key_ << " | ";
    x->value_->show();
    cout << "\n";
    
    // рекурсивный вызов для правого ребенка
    inorder(x->right_);
}
