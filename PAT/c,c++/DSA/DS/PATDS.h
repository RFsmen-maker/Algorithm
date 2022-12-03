#ifndef PATDS_H_INCLUDED
#define PATDS_H_INCLUDED
/*
PAT-DSA series function question collection
*/

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

// ������ͷ��������
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List Read();                    // ͨ�ô������������²�Ϊβ�巨
void Print(List L);             // ͨ�ô�ӡ������

// ����ͷ������������
#ifdef PATDS_6_9
BinTree CreatBinTree(); /* ʵ��ϸ�ں��� */
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );
#endif

// 6-6 ��ͷ�����ʽ�������
#ifdef PATDS_6_6
List MakeEmpty();
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );
#endif

// 6-5 ��ʽ�������
Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

// 6-4 ��ʽ����Ų���
ElementType FindKth(List L, int K);

// 6-3 ����ʽ���
int Length(List L);

// 6-2 ˳��������
#ifdef PATDS_6_2
#define MAXSIZE 5
#define ERROR -1
typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};
// ����������һ���յ����Ա�
List MakeEmpty();
// �������Ա��� X ��λ�ã��Ҳ������� ERROR
Position Find(List L, ElementType X);
// �� X ������λ�� P ������ true,
// �ռ��������ӡ "FULL" ������ false;
// ������� P ָ��Ƿ�λ�ã����ӡ "ILLEGAL POSITION" ������ false
bool Insert(List L, ElementType X, Position P);
// ��λ�� P ��Ԫ��ɾ�������� true��
// �� P ָ��Ƿ�λ�ã����ӡ "POSITION P EMPTY" (P �ǲ���ֵ) ������ false
#endif

// 6-1 ��������ת
List Reverse(List L);

#endif // PATDS_H_INCLUDED
