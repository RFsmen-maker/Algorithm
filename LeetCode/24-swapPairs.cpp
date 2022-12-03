/*
* 24.两两反转
* 1 -> 2 -> 3 -> 4 => 2 -> 1 -> 4 -> 3
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

ListNode* swapPairs(ListNode* head)
{
        if (head == NULL || head->next == NULL) return head;

        ListNode *cur, *save, *last, *dest;
        cur = last = head;
        save = NULL;
        dest = cur->next;
        while (cur && cur->next)
        {
                last->next = cur->next;
                save = cur->next->next;
                cur->next->next = cur;
                cur->next = save;
                last = cur;
                cur = save;
        }

        return dest;
}

// 显示链表
ostream& operator << (ostream& os, ListNode *l)
{
        auto temp = l;
        while(temp != NULL)
        {
                cout << temp->val << endl;
                temp = temp->next;
        }
        return os;
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
        ListNode* l = initialize({1, 2, 3, 4});
        cout << l << endl;
        l = swapPairs(l);
        cout << l << endl;

        return 0;
}
