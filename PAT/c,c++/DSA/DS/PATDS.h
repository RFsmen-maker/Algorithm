#ifndef PATDS_H_INCLUDED
#define PATDS_H_INCLUDED
/*
PAT-DSA series function question collection
*/

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

// 不含有头结点的链表
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List Read();                    // 通用创建链表函数，猜测为尾插法
void Print(List L);             // 通用打印链表函数

// 不带头结点二叉树遍历
#ifdef PATDS_6_9
BinTree CreatBinTree(); /* 实现细节忽略 */
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );
#endif

// 6-6 带头结点链式表操作集
#ifdef PATDS_6_6
List MakeEmpty();
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );
#endif

// 6-5 链式表操作集
Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

// 6-4 链式表按序号查找
ElementType FindKth(List L, int K);

// 6-3 求链式表表长
int Length(List L);

// 6-2 顺序表操作集
#ifdef PATDS_6_2
#define MAXSIZE 5
#define ERROR -1
typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};
// 创建并返回一个空的线性表
List MakeEmpty();
// 返回线性表中 X 的位置，找不到返回 ERROR
Position Find(List L, ElementType X);
// 将 X 插入在位置 P 并返回 true,
// 空间已满则打印 "FULL" 并返回 false;
// 如果参数 P 指向非法位置，则打印 "ILLEGAL POSITION" 并返回 false
bool Insert(List L, ElementType X, Position P);
// 将位置 P 的元素删除并返回 true。
// 若 P 指向非法位置，则打印 "POSITION P EMPTY" (P 是参数值) 并返回 false
#endif

// 6-1 单链表逆转
List Reverse(List L);

#endif // PATDS_H_INCLUDED
