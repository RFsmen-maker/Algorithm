/*
 * 19080-1.6 ��ת����
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
    /**< β�巨���������� */
    LNode *r, *p;
    r=L=new LNode;/**< ����ͷ��� */
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
    /**< һ���򵥵������������������̹����в���ʹ�� */
    L=L->next;
    while(L)
    {
        cout<<L->data<<' ';
        L=L->next;
    }
}
void reverseList(LNode * &L)
{
    LNode *pre = NULL;/**< ������ָ��ֱ��ʾǰ������ǰ����� */
    LNode *cur = L->next;/**< ��ǰ�ǵ�һ���ڵ�a1 */
    LNode *nex = NULL; /**<˼�������������ָ��ʵ�ַ�ת�����⣬����ָ��ҲҪͬ������ */
    while (cur)
    {
            // ���沢��ת
            nex = cur->next;
            cur->next = pre;
            pre = cur;

            // ����
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
