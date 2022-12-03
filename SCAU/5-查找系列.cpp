/*
 * SCAU 查找系列
*/
#include <iostream>
#include <vector>
#include <algorithm>

#include"malloc.h" /* malloc()等 */
#include"stdio.h"
#include"stdlib.h"

using namespace std;

typedef int ElemType;
typedef struct /*静态查找表的顺序存储结构 */
{
	ElemType *elem; /* 数据元素存储空间基址，建表时按实际长度分配，0号单元留空 */
	int length; /* 表长度 */
}SSTable;

void Creat_Seq(SSTable &ST,int n)
{ /* 操作结果: 构造一个含n个数据元素的静态顺序查找表ST(数据来自数组r) */
	int i,temp;
	ST.elem=(ElemType *)malloc((n+1) * sizeof(ElemType)); /* 动态生成n个数据元素空间(0号单元不用) */
	if(!(ST).elem)
	{
		printf("ERROR\n");
		exit(0);
	} /*内存分配失败结束程序*/
	for(i=1;i<=n;i++) // 注意这里对元素获取进行了偏移
	{
		scanf("%d",&temp);
		*(ST.elem+i)=temp; /* 依次赋值给ST */
	}
	ST.length=n;
}

int Search_Seq(SSTable &ST,ElemType key)
{ /* 在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为 */
/* 该元素在表中的位置，否则为0。算法9.1 */
        int i = 1;
        while (i <= ST.length && ST.elem[i] != key) i++;
        if (i > ST.length) return 0;
        else return i;
}

// 1. 顺序查找
void seSearch(void)
{
	SSTable ST;
	int loc,key;
	int n;
	scanf("%d",&n);
	Creat_Seq(ST,n);
	//printf("Please input the key value：");
	scanf("%d",&key);
	loc = Search_Seq(ST,key);
	if(loc!=0)
		printf("The element position is %d.\n",loc);
	else
		printf("The element is not exist.\n");
}

// 2. 二分查找
void binarySearch(void)
{
        int n, key;
        cin >> n;
        vector<int> arr(n);
        for (int &i : arr) cin >> i;
        cin >> key;

        int left = 0, right = n - 1, mid;
        while (left <= right) {
                mid = left + (right - left) / 2;
                // cout << "mid : " << mid << endl;
                if (arr[mid] == key) {
                        cout << "The element position is "<< mid << '.';
                        return;
                }
                else if (arr[mid] > key) right = mid - 1;
                else left = mid + 1;
        }
        cout << "The element is not exist.";
        return;
}

// 3. 哈希查找
#define EQ(a,b) ((a)==(b))
#define SUCCESS 1
#define UNSUCCESS 0
#define NULLKEY -1 /*哈希表无元素时值为-1*/

typedef int ElemType;
int length;

typedef struct
{
   ElemType *elem; /* 数据元素存储基址，动态分配数组 */
   int count; /* 当前数据元素个数 */
}HashTable;

void InitHashTable(HashTable *H)
 { /* 操作结果: 构造一个长度为length的哈希表,length为全局变量 */
   int i;
   (*H).count=0; /* 当前元素个数为0 */
   (*H).elem=(ElemType*)malloc(length*sizeof(ElemType));
   if(!(*H).elem)
     exit(0); /* 存储分配失败 */
   for(i=0;i<length;i++)
     (*H).elem[i]=NULLKEY; /* 未填记录的标志 */
}

// 定址规则尚未明了探测方法：线性探测、平方探测、双散列
// 22 41 53 46 30 13 1 67
// -> 22 X 41 30 1 53 46 13 67 X X
unsigned Hash(ElemType K)
{ /* 一个简单的哈希函数*/
        // 从结果来看不太像
        return K % length;
}

void collision(int *p) /*线性探测再散列 */
{ /* 开放定址法处理冲突 */







}

int SearchHash(HashTable H,ElemType K,int *p,int *c)
{  /* 在开放定址哈希表H中查找关键码为K的元素,若查找成功,以p指示待查数据 */
   /* 元素在表中位置,并返回SUCCESS;否则,以p指示插入位置,并返回UNSUCCESS */
   /* c用以计冲突次数，其初值置零，供建表插入时参考。算法9.17 */
   *p=Hash(K); /* 求得哈希地址 */
   while(H.elem[*p]!=NULLKEY&&!EQ(K,H.elem[*p])) // 该位置中填有记录,并且关键字不相等
   {
     (*c)++;
     if(*c<length)
	   collision(p); /* 求得下一探查地址p */
     else
       break;
   }
   if EQ(K,H.elem[*p])
     return SUCCESS; /* 查找成功，p返回待查数据元素位置 */
   else
     return UNSUCCESS; /* 查找不成功(H.elem[p].key==NULLKEY)，p返回的是插入位置 */
}

int InsertHash(HashTable *H,ElemType e)
{ /* 查找不成功时插入数据元素e到开放定址哈希表H中，并返回查找长度 */
   int c,p;
   c=0;
   if(SearchHash(*H,e,&p,&c))   /* 表中已有与e有相同关键字的元素 */
     printf("哈希表中已有元素%d。\n",e);
   else{ /* 插入e */
     (*H).elem[p]=e;
     ++(*H).count;
   }
   return c+1; /*查找长度为冲突次数加1*/
}

void TraverseHash(HashTable H)
 { /* 按哈希地址的顺序打印哈希表，无元素位置用X表示 */
   int i;
   printf("HashTable Address:0～%d\n",length-1);
   for(i=0;i<length;i++)
     if(H.elem[i]==NULLKEY) /* 有数据 */
       printf("X ");
	 else
		 printf("%d ",H.elem[i]);
	 printf("\n");
}

// 暂略，看不懂怎么个哈希法
void hashSearch(void)
{
	float i=0,j=0;
	ElemType e;
	HashTable H;
         //printf("Input Table length:");
	scanf("%d",&length);
	InitHashTable(&H);
	//printf("Input key words sequence, -1 conclusion input：");
	scanf("%d",&e);
	while(e!=-1)
	{
		j ++;  /*j记录输入元素个数*/
		i += InsertHash(&H,e);  /*i记录查找长度的和*/
		scanf("%d",&e);
	}
	TraverseHash(H);
	printf("Average search length=%f\n",i/j);
}

// 4. 二叉排序树各种算法，暂略，先去刷其他算法

int main(void)
{


        return 0;
}

