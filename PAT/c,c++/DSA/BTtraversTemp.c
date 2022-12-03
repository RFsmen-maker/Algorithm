#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};



int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}

BinTree CreatBinTree(void)
{

}

void InorderTraversal(BinTree BT)
{
        if(BT != NULL) {
                InorderTraversal(BT->Left);
                printf(" %c", BT->Data);
                InorderTraversal(BT->Right);
        }
}

void PreorderTraversal(BinTree BT)
{
        if(BT != NULL) {
                printf(" %c", BT->Data);
                PreorderTraversal(BT->Left);
                PreorderTraversal(BT->Right);
        }
}

void PostorderTraversal(BinTree BT)
{
        if(BT != NULL) {
                PostorderTraversal(BT->Left);
                PostorderTraversal(BT->Right);
                printf(" %c", BT->Data);
        }
}

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
