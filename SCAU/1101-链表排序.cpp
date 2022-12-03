/*
 * 1101. 链表排序
 */
#include <iostream>
#include "stdio.h"
#include "malloc.h"
#define LEN sizeof(struct student)

using namespace std;

struct student
{
     long num;
     int score;
     struct student *next;
};

struct student *create(int n)
{
     struct student *head=NULL,*p1=NULL,*p2=NULL;
     int i;
     for(i=1;i<=n;i++)
     {  p1=(struct student *)malloc(LEN);
        scanf("%ld",&p1->num);
        scanf("%d",&p1->score);
        p1->next=NULL;
        if(i==1) head=p1;
        else p2->next=p1;
        p2=p1;
      }
      return(head);
}

void print(struct student *head)
{
    struct student *p;
    p=head;
    while(p!=NULL)
    {
        printf("%8ld%8d",p->num,p->score);
        p=p->next;
        printf("\n");
    }
}

struct student *insert(struct student *head, struct student *stud)
{  struct student *p0,*p1,*p2;
    p1=head;  p0=stud;
    if(head==NULL)
      {head=p0;}
    else
   { while( (p0->num > p1->num) && (p1->next!=NULL) )
       { p2=p1;     p1=p1->next;}
     if( p0->num <= p1->num )
      {  if( head==p1 ) head=p0;
           else p2->next=p0;
         p0->next=p1; }
     else {  p1->next=p0;}
     }
    return(head);
}

struct student *del(struct student *head,long num)
{
    struct student *p1,*p2;
    p1=head;
    while(p1!=NULL)
    {
        if(p1->num == num)
        {
          if(p1 == head) head=p1->next;
          else p2->next=p1->next;
          free(p1);
          break;
        }
        p2=p1;
        p1=p1->next;
    }
    return(head);
}

struct student *sort(struct student *head) // 按照学号从小到大，初定使用简单选择排序，链表不带头结点
{
        student *tempHead = (struct student*)malloc(LEN);
        tempHead->next = head;

        student *pre = tempHead;
        student *iter, *minNode;
        while (pre->next->next != nullptr) { // 最后一个结点不用管
                minNode = pre; // pre 待交换位置，minNode 最小结点标记位置
                iter = pre->next; // 从待交换位置的下一个开始找最小结点

                while (iter->next != nullptr) { // 直到最后一个结点
                        if (minNode->next->num > iter->next->num) minNode = iter;
                        iter = iter->next;
                }

                if (minNode != pre) { // 改变过才需要交换
                        student *x = pre->next, *y = minNode->next;
                        if (pre->next == minNode) { // 相邻结点的交换方式不同！
                                pre->next = y;
                                x->next = y->next;
                                y->next = x;
                        }
                        else {
                                minNode->next = x;
                                pre->next = y;
                                student *temp = x->next;
                                x->next = y->next;
                                y->next = temp;
                        }
                }

                pre = pre->next;
        }

        return tempHead->next;
}

main()
{
    struct student *head,*stu;
    int n;
    scanf("%d",&n);
    head=create(n);
    print(head);
    head=sort(head);
    print(head);
}
