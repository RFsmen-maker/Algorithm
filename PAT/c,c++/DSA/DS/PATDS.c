#include "PATDS.h"

// ��Ŀ��β�巨
List Read(void)
{
        // ��ͷ����
        List L = (List)malloc(sizeof(struct LNode));
        L->Next = NULL;
        PtrToLNode tempNode = L;
        ElementType tempIn;
        scanf("%d", &tempIn);
        while(tempIn != -1)
        {
                PtrToLNode newNode = (PtrToLNode)malloc(sizeof(struct LNode));
                newNode->Data = tempIn;
                tempNode->Next = newNode;
                tempNode = tempNode->Next;
                scanf("%d", &tempIn);
        }
        tempNode->Next = NULL;

        return L;
}

// ��ӡ����
void Print(List L)
{
        while(L != NULL)
        {
                printf("%d ", L->Data);
                L = L->Next;
        }
}

/*
* DSA_6-1 ��������ת
*/
List Reverse(List L)
{
        List tempL, tempNext;

        tempL = NULL;

        while(L != NULL)
        {
                tempNext = L->Next;

                L->Next = tempL;
                tempL = L;

                L = tempNext;
        }

        return tempL;
}

/*
* DSA_6-2 ˳��������
*/
#ifdef PAT_6_2
List MakeEmpty()
{
        List L;
        L = (List)malloc(sizeof(struct LNode));
        L->Last = -1;

        return L;
}

Position Find(List L, ElementType X)
{
        Position i;
        for(i = 0; L->Data[i] != X && i <= L->Last; ++i);
        if(i > L->Last) {
                return ERROR;
        }
        else {
                return i;
        }
}

bool Insert( List L, ElementType X, Position P )
{
        if(L->Last == MAXSIZE-1) {
                printf("FULL");
                return false;
        }
        if(P < 0 || P > L->Last+1) {
                printf("ILLEGAL POSITION");
                return false;
        }
        for(int i = L->Last; i >= P; --i)
        {
                L->Data[i+1] = L->Data[i];
        }
        L->Data[P] = X;
        L->Last++;
        return true;
}

bool Delete( List L, Position P )
{
        if(P < 0 || P > L->Last) {
                printf("POSITION %d EMPTY", P);
                return false;
        }
        else {
                for(int i = P; i < L->Last; ++i)
                {
                        L->Data[i] = L->Data[i+1];
                }
                L->Last--;
                return true;
        }
}
#endif

/*
* 6-3 ����ʽ���
*/
int Length(List L)
{
        int count = 0;

        while(L != NULL)
        {
                count++;
                L = L->Next;
        }

        return count;
}

/*
* DSA_6-4 ��ʽ����Ų���
* �������⣺
* ����֪����û��ͷ���
* ������鿴���ϴ𰸣�û��ͷ���
*/
ElementType FindKth(List L, int K)
{
        while(--K && L != NULL)
        {
                L = L->Next;
        }
        if(L != NULL) return L->Data;
        else return ERROR;
}

// DSA_6-5 ��ʽ�������
// ���ⲻ��
Position Find(List L, ElementType X)
{
        while(L != NULL && L->Data != X)
        {
                L = L->Next;
        }
        return L;
}

// ����������Ƿ�����������ʾ�䶼�л��з�
/*
* ���������
* 0. �������
* 1. �Ƿ�����ձ����
* 2. �Ƿ�嵽ͷ֮ǰ��λ��
* 3. P == NULL ʱ��β�巨
* 4. P ָ��Ƿ��������ָ P ָ��ͷ�������ڴ�λ�� (P != NULL)
*/
List Insert(List L, ElementType X, Position P)
{
        // P ָ�������ѷ����ڴ�
        if(P != NULL && P != L) {
                printf("Wrong Position for Insertion\n");
                return ERROR;
        }
        // �ձ�
        if(L == NULL) {
                L = (PtrToLNode)malloc(sizeof(struct LNode));
                L->Data = X;
                L->Next = NULL;
                return L;
        }
        // ͷ�巨
        if(L == P) {
                PtrToLNode newNode = (PtrToLNode)malloc(sizeof(struct LNode));
                newNode->Data = X;
                newNode->Next = P;
                L = newNode;
                return L;
        }
        PtrToLNode tempNode = L;
        PtrToLNode newNode = (PtrToLNode)malloc(sizeof(struct LNode));
        newNode->Data = X;
        // β�巨
        if(P == NULL) {
                while(tempNode->Next != NULL)
                {
                        tempNode = tempNode->Next;
                }
                newNode->Next = NULL;
        }
        else { // �����巨
                while(tempNode != NULL && tempNode->Next != P)
                {
                        tempNode = tempNode->Next;
                }
                newNode->Next = P;
        }
        tempNode->Next = newNode;

        return L;
}

/*
* ���������
* 0. �������
* 1. �Ƿ�ɾ��ͷ
* 2. ���ڷǷ���� P ��һ���� NULL ���п�����ָ��������������ڴ�λ��
*/
List Delete(List L, Position P)
{
        if(L == P) {
                L = L->Next;
                free(P);
                return L;
        }
        if(P == NULL) {
                printf("Wrong Position for Deletion\n");
                return ERROR;
        }
        PtrToLNode tempNode = L;
        while(tempNode != NULL && tempNode->Next != P)
        {
                tempNode = tempNode->Next;
        }
        if(tempNode == NULL) {
                printf("Wrong Position for Deletion\n");
                return ERROR;
        }
        else {
                tempNode->Next = P->Next;
                free(P);
                return L;
        }
}

// DSA_6-6 ��ͷ�����ʽ�������
#ifdef PATDS_6_6
List MakeEmpty(void)
{
        List L = (List)malloc(sizeof(struct LNode));
        L->Data = -1;
        L->Next = NULL;

        return L;
}

Position Find(List L, ElementType X)
{
        Position P = L->Next;
        while(P != NULL && P->Data != X)
        {
                P = P->Next;
        }
        if(P == NULL) return ERROR;
        else return P;
}

bool Insert(List L, ElementType X, Position P)
{
        if(P == L->Next) {
                PtrToLNode newNode = (PtrToLNode)malloc(sizeof(struct LNode));
                newNode->Data = X;
                newNode->Next = L->Next;
                L->Next = newNode;
                return true;
        }
        else if(P == NULL) {
                PtrToLNode newNode = (PtrToLNode)malloc(sizeof(struct LNode));
                newNode->Data = X;
                while(L->Next != NULL)
                {
                        L = L->Next;
                }
                newNode->Next = NULL;
                L->Next = newNode;
                return true;
        }
        else {
                while(L->Next != NULL && L->Next != P)
                {
                        L = L->Next;
                }
                if(L->Next == NULL) {
                        printf("Wrong Position for Insertion\n");
                        return false;
                }
                PtrToLNode newNode = (PtrToLNode)malloc(sizeof(struct LNode));
                newNode->Data = X;
                newNode->Next = L->Next;
                L->Next = newNode;
                return true;
        }
}

bool Delete(List L, Position P)
{
        while(L->Next != NULL && L->Next != P)
        {
                L = L->Next;
        }
        if(L->Next == NULL) {
                printf("Wrong Position for Deletion\n");
                return false;
        }
        else {
                L->Next = P->Next;
                free(P);
                return true;
        }
}
#endif

/*
* DSA_6-7 ��һ��������ʵ��������ջ
* ��Ŀ��⣺˫ͷջ����
* �������⣺���Ե� 1��2 ������ֻ��һ�ߵĶ�ջ Push �����
*/
#ifdef PATDS_6_7


#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize );
bool Push( Stack S, ElementType X, int Tag );
ElementType Pop( Stack S, int Tag );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Tag ); /* details omitted */

int main()
{
    int N, Tag, X;
    Stack S;
    int done = 0;

    // �����¶�ջ��ָ�����ߴ�
    scanf("%d", &N);
    S = CreateStack(N);

    while ( !done ) {
        // ����ָ�����ö�����ͽ��д���
        switch( GetOp() ) {
        case push: // ��ջ��ָ�� Tag ��ջ�� X
            scanf("%d %d", &Tag, &X);
            if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
            break;
        case pop: // ��ջ��ָ�� Tag ��ջ
            scanf("%d", &Tag);
            X = Pop(S, Tag);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Tag);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}

Operation GetOp(void)
{
        char str[10];
        scanf("%s", &str);
        if(str[1] == 'u') return 0;
        else if(str[1] == 'o') return 1;
        else if(str[1] == 'n') return 2;
}

void PrintStack(Stack S, int Tag)
{
        printf("Pop from Stack %d:", Tag);
        if(Tag == 1) {
                for(int i = S->Top1; i >= 0; i--)
                        printf(" %d", S->Data[i]);
        }
        else if(Tag == 2) {
                for(int i = S->Top2; i < S->MaxSize; i++)
                        printf(" %d", S->Data[i]);
        }
        printf("\n");
}

Stack CreateStack(int MaxSize)
{
        Stack newStack = (Stack)malloc(sizeof(struct SNode));
        newStack->Data = (ElementType *)malloc(sizeof(ElementType));
        newStack->MaxSize = MaxSize;
        newStack->Top1 = -1;
        newStack->Top2 = newStack->MaxSize;

        return newStack;
}

bool Push(Stack S, ElementType X, int Tag)
{
        if(S->Top1 + 1 == S->Top2) {
                printf("Stack Full\n");
                return false;
        }
        else {
                if(Tag == 1) {
                        ++S->Top1;
                        S->Data[S->Top1] = X;
                }
                else {
                        --S->Top2;
                        S->Data[S->Top2] = X;
                }
                return true;
        }
}

ElementType Pop(Stack S, int Tag)
{
        if(Tag == 1) {
                if(S->Top1 == -1) {
                        printf("Stack %d Empty\n", Tag);
                        return ERROR;
                }
                else {
                        S->Top1--;
                        return S->Data[S->Top1+1];
                }
        }
        else {
                if(S->Top2 == S->MaxSize) {
                        printf("Stack %d Empty\n", Tag);
                        return ERROR;
                }
                else {
                        S->Top2++;
                        return S->Data[S->Top2-1];
                }
        }
}

#endif // PATDS_6_7

// PATDS_6_8 ��������߶ȣ��ݹ��㷨
int GetHeight(BinTree BT)
{
        if(BT == NULL) return 0;
        else {
                int leftHeight = GetHeight(BT->Left);
                int rightHeight = GetHeight(BT->Right);
                return leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;
        }
}

// PATDS_6_9 ����������
#ifdef PATDS_6_9
// �������
void InorderTraversal(BinTree BT)
{
        if(BT != NULL) {
                InorderTraversal(BT->Left);
                printf(" %c", BT->Data);
                InorderTraversal(BT->Right);
        }
}

// �������
void PreorderTraversal(BinTree BT)
{
        if(BT != NULL) {
                printf(" %c", BT->Data);
                PreorderTraversal(BT->Left);
                PreorderTraversal(BT->Right);
        }
}

// �������
void PostorderTraversal(BinTree BT)
{
        if(BT != NULL) {
                PostorderTraversal(BT->Left);
                PostorderTraversal(BT->Right);
                printf(" %c", BT->Data);
        }
}

// �������
void LevelorderTraversal(BinTree BT)
{
        if(BT != NULL) {
                const int tempMax = 10000;
                struct TNode *tempNode[tempMax];
                int tempCo, tempHead;
                tempCo = tempHead = 0;
                tempNode[tempCo++] = BT;
                while(tempCo != tempHead)
                {
                        printf(" %c", tempNode[tempHead]->Data);
                        BT = tempNode[tempHead++];
                        if(BT->Left != NULL) tempNode[tempCo++] = BT->Left;
                        if(BT->Right != NULL) tempNode[tempCo++] = BT->Right;
                }
        }
}
#endif
