#include <algorithm>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#define all(c) c.begin(), c.end()
#define MAX 1000

typedef unsigned long long ull;
typedef long double ld;
typedef double type;

using namespace std;

typedef string ElementType;
typedef string KeyType;
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

struct AvlNode {
    ElementType Element;
    KeyType Key; //ключ
    AvlTree Left; //левое поддерево
    AvlTree Right; //правое поддерево
    int Balance; //показатель баланса
    int Height; //высота поддерева
};

/*  Высота дерева */
int Height(Position P) {
    if(!P)
        return -1;
    else
        return P->Height;
}

/*  Наибольшая из двух высот */
int Max (int Lhs, int Rhs) {
    return Lhs > Rhs ? Lhs : Rhs;
}

/*  Удаление дерева */
AvlTree MakeEmpty(AvlTree T) {
    if(T) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

/*  Поиск по ключу в дереве */
Position Find(ElementType X, AvlTree T) {
    if(!T)
        return NULL;
    if(X < T->Element)
        return Find(X, T->Left);
    else if(X > T->Element)
        return Find(X, T->Right);
    else
        return T;
}

/*  Нахождение минимального элемента */
Position FindMin(AvlTree T) {
    if(!T)
        return NULL;
    else if(T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

/*  Нахождение максимального элемента */
Position FindMax(AvlTree T) {
    if(T)
        while(T->Right != NULL)
            T = T->Right;
    return T;
}

/*  Эту функцию можно вызывать только в том случае, когда у
    узла K2 есть левый ребенок. Функция выполняет поворот
    между узлом (K2) и его левым ребенком, корректирует
    высоты поддеревьев, после чего возвращает новый корень */
Position SingleRotateWithLeft(Position K2) {
    Position K1;
    /* выполнение поворота */
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;
    /* корректировка высот переставленных узлов */
    K2->Height = Max(Height(K2->Left), Height(K2->Right))+1;
    K1->Height = Max(Height(K1->Left), K2->Height) + 1;
    return K1; /* новый корень */
}

/*  Эту функцию можно вызывать только в том случае, когда у
    узла K1 есть правый ребенок. Функция выполняет поворот
    между узлом (K1) и его правым ребенком, корректирует
    высоты поддеревьев, после чего возвращает новый корень */
Position SingleRotateWithRight(Position K1) {
    Position K2;
    /* выполнение поворота */
    K2 = K1->Right;
    K1->Right = K2->Left;
    K2->Left = K1;
    /* корректировка высот переставленных узлов */
    K1->Height = Max(Height(K1->Left), Height(K1->Right))+1;
    K2->Height = Max(Height(K2->Right), K1->Height) + 1;
    return K2; /* новый корень */
}

/*  Эту функцию можно вызывать только тогда, когда
    у узла K3 есть левый ребенок, а у левого ребенка
    K3 есть правый ребенок. Функция выполняет двойной
    поворот LR, корректирует высоты поддеревьев, после
    чего возвращает новый корень */
Position DoubleRotateWithLeft(Position K3) {
    /* Поворот между K1 и K2 */
    K3->Left = SingleRotateWithRight(K3->Left);
    /* Поворот между K3 и K2 */
    return SingleRotateWithLeft(K3);
}

/*  Эту функцию можно вызывать только в том случае, когда у
    узла K1 есть правый ребенок, а у правого ребенка узла K1
    есть левый ребенок. Функция выполняет двойной поворот
    RL, корректирует высоты поддеревьев, после чего
    возвращает новый корень */
Position DoubleRotateWithRight(Position K1) {
    /* Поворот между K3 и K2 */
    K1->Right = SingleRotateWithLeft(K1->Right);
    /* Поворот между K1 и K2 */
    return SingleRotateWithRight(K1);
}

/*  Вставка элемента в дерево */
AvlTree Insert(ElementType X, KeyType K, AvlTree T) {
    if(!T) {
        /* создание дерева с одним узлом */
        T = new AvlNode;
        T->Element = X;
        T->Key = K;
        T->Height = 0;
        T->Left = T->Right = NULL;
    }
    else if(X < T->Element) {
            T->Left = Insert(X, K, T->Left);
        if(Height(T->Left) - Height(T->Right) == 2) {
            if(X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
            }
        }
    if(X > T->Element) {
        T->Right = Insert(X, K, T->Right);
            if(Height(T->Right) - Height(T->Left) == 2) {
                if(X > T->Right->Element)
                    T = SingleRotateWithRight(T);
                else
                    T = DoubleRotateWithRight(T);
            }
        }
    /* Иначе X уже в дереве и ничего не нужно делать; */
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

/*  Вывод дерева на экран в порядке обхода */
void Print(AvlTree T) {
    if (T->Left)
        Print(T->Left);
    cout << T->Element << " " << T->Key << " " << endl;;
    if (T->Right)
        Print(T->Right);
}

bool check(AvlTree T, int &h)
{
    if (!T)
    {
        h = 0;
        return true;
    }
    int h1, h2;
    if (!(check(T->Left, h1) && check(T->Right, h2)))
    {
        h = max(h1, h2) + 1;
        return false;
    }
    h = max (h1, h2) + 1;
    if (abs(h1 - h2) > 1)
        return false;
    return true;
}

int main() {
    AvlTree Tree = NULL;

    string command;
    string surname;
    string telephone;
    do {
        cin >> command;
        if (command == "FIND") {
            cin >> surname;
            AvlTree Found = Find(surname, Tree);
            if (Found)
                cout << Found->Key << endl;
            else
                cout << "NO" << endl;
        }
        if (command == "INSERT") {
            cin >> surname >> telephone;
//            cout << "finding..." << endl;
            AvlTree Found = Find(surname, Tree);
//            cout << "found" << endl;
            if (!Found) {
                cout << "inserting..." << endl;
                Tree = Insert(surname, telephone, Tree);
                cout << "OK" << endl;
            } else {
                cout << "Changed. Old value = " << Found->Key << endl;
                Found->Key = telephone;
            }
        }
        if (command == "PRINT") {
            Print(Tree);
        }
        if (command == "DELETE") {
            Tree = MakeEmpty(Tree);
            cout << "Deleted" << endl;
        }
        if (command == "CHECK") {
            int h;
            if (check(Tree, h))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    } while (command != "EXIT");

    return 0;
}
