/*
* 206. 反转链表
*/
#include <iostream>

using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 递归方法
ListNode* reverseList1(ListNode* head)
{
        if(head == NULL || head->next == NULL) return head;
        // 让最后一个节点的指针一直保留在递归栈中
        ListNode* p = reverseList1(head->next); // 递归往下深入
        head->next->next = head;
        head->next = NULL;
        return p;
}

// 迭代方法
ListNode* reverseList(ListNode* head)
{
        if(head == NULL) return NULL;

        ListNode *next, *cur, *save;
        next = NULL;
        cur = head;
        while(cur->next != NULL)
        {
                save = cur->next;
                cur->next = next;
                next = cur;
                cur = save;
        }
        cur->next = next;

        return cur;
}

// 显示链表
void showList(ListNode *l)
{
        auto temp = l;
        while(temp != NULL)
        {
                cout << temp->val << endl;
                temp = temp->next;
        }
}

// 尾插法创建链表
#include <vector>
ListNode* initialize(vector<int> arr)
{
        int len = arr.size();
        if(len == 0) return NULL;
        ListNode *L = (ListNode *)malloc(sizeof(ListNode));
        L->val = arr[0];
        L->next = NULL;

        auto temp = L;
        for(int i = 1; i < len; i++)
        {
                ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
                newNode->val = arr[i];
                newNode->next = NULL;
                temp->next = newNode;
                temp = newNode;
        }
        return L;
}

int main(void)
{
        ListNode* l = initialize({1, 2, 3, 4, 5});
        showList(l);
        l = reverseList1(l);
        showList(l);

        return 0;
}
