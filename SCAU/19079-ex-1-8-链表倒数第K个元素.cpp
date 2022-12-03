/*
 * 18063-ex1.8 链表倒数第 K 个元素
 * times : 2
*/
#include <iostream>//C++
using namespace std;
struct LNode
{
    int data;
    LNode * next;
};

void createList(LNode * &L,int n)
{/**< 尾插法创建单链表 */
    LNode *r, *p;
    r=L=new LNode;/**< 创建头结点 */
    L->next=NULL;
    for(int i=1;i<=n;i++)
    {
        p=new LNode;
        cin>>p->data;
        p->next=NULL;
        r->next=p;
        r=p;
    }
}
void trv(LNode * L)
{ /**< 一个简单的链表遍历函数，供编程过程中测试使用 */
    L=L->next;
    while(L)
    {
        cout<<L->data<<' ';
        L=L->next;
    }
}

// 输出倒数第 k 个结点，双指针法，由于带头结点，不用特意偏移
int getK(LNode * L,int k)
{
        auto left = L;
        auto right = L;
        while (k-- && right != nullptr) right = right->next;
        if (right == nullptr) return -1; // k > 链表结点数
        while (right != nullptr) right = right->next, left = left->next; // 等速前进
        return left->data;
}

int main()
{
    int n,k;
    LNode *L;
    cin>>n>>k;
    createList(L,n);
    //trv(L);
    cout<<getK(L,k);
    return 0;
}
