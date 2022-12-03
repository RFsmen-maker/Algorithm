/*
 * 19080-1.6 反转链表
*/
#include <iostream>//C++

using namespace std;
struct LNode
{
    int data;
    LNode * next;
};
void createList(LNode * &L,int n)
{
    /**< 尾插法创建单链表 */
    LNode *r, *p;
    r=L=new LNode;/**< 创建头结点 */
    L->next=NULL;
    for(int i=1; i<=n; i++)
    {
        p=new LNode;
        cin>>p->data;
        p->next=NULL;
        r->next=p;
        r=p;
    }
}
void trv(LNode * L)
{
    /**< 一个简单的链表遍历函数，供编程过程中测试使用 */
    L=L->next;
    while(L)
    {
        cout<<L->data<<' ';
        L=L->next;
    }
}
void reverseList(LNode * &L)
{
    LNode *pre = NULL;/**< 用三个指针分别表示前驱，当前，后继 */
    LNode *cur = L->next;/**< 当前是第一个节点a1 */
    LNode *nex = NULL; /**<思考如何用这三个指针实现翻转，另外，三个指针也要同步后移 */
    while (cur)
    {
            // 保存并反转
            nex = cur->next;
            cur->next = pre;
            pre = cur;

            // 后移
            cur = nex;
    }
    L->next=pre;
}
int main()
{
    int n;
    LNode *L;
    cin>>n;
    createList(L,n);
    reverseList(L);
    trv(L);
    return 0;
}
