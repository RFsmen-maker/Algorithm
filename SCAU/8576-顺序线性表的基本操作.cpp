/*
 * 8576. 顺序线性表的基本操作
 */
#include<stdio.h>
#include<malloc.h>

#define OK 1
#define ERROR 0

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef struct
{
	int *elem;
	int length;
	int listsize;
}SqList;

int InitList_Sq(SqList &L)
{
// 算法2.3，构造一个空的线性表L，该线性表预定义大小为LIST_INIT_SIZE
        L.elem = (int *)malloc(sizeof(int) * LIST_INIT_SIZE);
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;
        return OK;
}

int Load_Sq(SqList &L)
{
// 输出顺序表中的所有元素
	if(L.length == 0) printf("The List is empty!");  // 请填空
	else {
		printf("The List is: ");
		for(int i = 0; i < L.length; ++i) printf("%d ", L.elem[i]);  // 请填空
	}
	printf("\n");
	return OK;
}

int ListInsert_Sq(SqList &L,int i,int e)
{
// 算法2.4，在顺序线性表L中第i个位置之前插入新的元素e
// i的合法值为1≤i≤L.length +1
        if (i < 1 || i > L.length+1) return ERROR;
        else {
                if (L.length == L.listsize) { // 需要扩充
                        L.elem = (int *)realloc(L.elem, L.listsize + LISTINCREMENT);
                        L.listsize += LISTINCREMENT;
                }

                for (int k = L.length-1; k >= i-1; --k) L.elem[k+1] = L.elem[k];
                L.elem[i-1] = e;

                L.length++;
        }
        return OK;
}

int ListDelete_Sq(SqList &L,int i, int &e)
{
// 算法2.5,在顺序线性表L中删除第i个位置的元素，并用e返回其值
// i的合法值为1≤i≤L.length
        if (i < 1 || i > L.length) return ERROR;
        else {
                e = L.elem[i-1];
                for (int k = i-1; k < L.length - 1; ++k) L.elem[k] = L.elem[k+1];
                L.length--;
        }
        return OK;
}

int main()
{
	SqList T;
	int a, i;
	ElemType e, x;
	if(InitList_Sq(T) == OK)    // 判断顺序表是否创建成功
	{
		printf("A Sequence List Has Created.\n");
	}
	while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);
					if(ListInsert_Sq(T, i, x) == ERROR) printf("Insert Error!\n"); // 执行插入函数，根据返回值判断i值是否合法
					else printf("The Element %d is Successfully Inserted!\n", x);
					break;
			case 2: scanf("%d",&i);
					if(ListDelete_Sq(T, i, e) == ERROR) printf("Delete Error!\n"); // 执行删除函数，根据返回值判断i值是否合法
					else printf("The Element %d is Successfully Deleted!\n", e);
					break;
			case 3: Load_Sq(T);
					break;
			case 0: return 1;
		}
	}
}
