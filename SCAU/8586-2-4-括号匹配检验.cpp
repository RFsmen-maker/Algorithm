/*
 * 8586-2.4 括号匹配检验
*/
#include <iostream>
#include <cstdio>
#include <cstdlib> // exit()
#include <cmath>
#include"malloc.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define STACK_INIT_SIZE 10 // 存储空间初始分配量
#define STACKINCREMENT 2 // 存储空间分配增量

typedef char SElemType;
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
struct SqStack
{
 SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
 SElemType *top; // 栈顶指针
 int stacksize; // 当前已分配的存储空间，以元素为单位
 }; // 顺序栈

Status InitStack(SqStack &S)
{
        S.stacksize = STACK_INIT_SIZE;
        S.top = new SElemType(STACK_INIT_SIZE + 1);
        S.base = S.top + S.stacksize;
        S.top = S.base;
        return OK;
}

Status StackEmpty(SqStack S)
{
        if (S.top == S.base) return TRUE;
        else return FALSE;
}

Status Push(SqStack &S,SElemType e)
{
// 在栈S中插入元素e为新的栈顶元素
        if (S.base - S.stacksize == S.top) { // 栈满，需要增加容量
                // std::cout << "Overlap" << std::endl;
                SElemType *extend = new SElemType(S.stacksize + STACKINCREMENT + 1);
                extend += STACKINCREMENT;
                auto cur = S.top;
                while (cur != S.base)
                {
                        *(extend) = *(cur);
                        cur++;
                }
                // memcpy(extend, S.top, S.stacksize);
                delete[] S.top;
                S.top = extend;
                S.base = S.top + S.stacksize;
                S.stacksize += STACKINCREMENT;
        }
        S.top--;
        *(S.top) = e;

        return OK;
}

 Status Pop(SqStack &S,SElemType &e)
{
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
        if (S.top == S.base) return ERROR;
        e = *(S.top);
        S.top++;
        return OK;
}

void check()
 { // 对于输入的任意一个字符串，检验括号是否配对
   SqStack s;
   SElemType ch[80],*p,e;
   if(InitStack(s)) // 初始化栈成功
   {
    //printf("请输入表达式\n");
     gets(ch);
     p=ch;
     while(*p) // 没到串尾
       switch(*p)
       {
         case '(':
         case '[': Push(s, *(p)); p++;
                  break; // 左括号入栈，且p++
         case ')':
         case ']':
                 if(!StackEmpty(s)) { // 栈不空
                        Pop(s, e); // 弹出栈顶元素
                        if((*p == ')' && e != '(') ||(*p == ']' && e != '[') ) { // 弹出的栈顶元素与*p不配对
                                printf("isn't matched pairs\n");
                                exit(ERROR);
                        } else {
                                p++;
                                break; // 跳出switch语句
                        }
                } else { // 栈空
                        printf("lack of left parenthesis\n");
                        exit(ERROR);
                }
         default: p++; // 其它字符不处理，指针向后移
       }
        // 字符串结束时栈空
        if(StackEmpty(s)) printf("matching\n");
        else printf("lack of right parenthesis\n");
   }
 }
int main()
 {
   check();
 }
