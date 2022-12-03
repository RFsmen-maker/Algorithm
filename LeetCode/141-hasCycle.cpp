/*
* 141. 链表寻环
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

void makeCycle(ListNode *head, int dest)
{
        ListNode *tail, *aim;
        tail = aim = head;
        while (tail->next) tail = tail->next;
        while (--dest) aim = aim->next;
        tail->next = aim;
}

// 双指针法，不等速前进的指针迟早遇到
bool hasCycle1(ListNode *head)
{
        if(head == nullptr || head->next == nullptr) return false;

        ListNode *fast, *slow;
        fast = head->next;
        slow = head;
        while(fast && fast->next  && slow)
        {
                if(fast == slow) return true;
                fast = fast->next->next;
                slow = slow->next;
        }

        return false;
}

// 利用哈希表查找，S = O(n)
#include <unordered_set>
bool hasCycle(ListNode *head)
{
        if(head == nullptr || head->next == nullptr) return false;

        ListNode *temp = head;
        unordered_set<ListNode*> myHash;
        while(temp != nullptr)
        {
                if(myHash.count(temp)) return true;
                myHash.insert(temp);
                temp = temp->next;
        }
        return false;
}

// 显示链表
ostream& operator << (ostream& os, ListNode *l)
{
        auto temp = l;
        while(temp != NULL)
        {
                cout << temp->val << " -> ";
                temp = temp->next;
        }
        cout << "nullptr" << endl;
        return os;
}

// 显示部分有环链表
void showCycle(ListNode *l, int amount)
{
        auto temp = l;
        while(amount--)
        {
                cout << temp->val << " -> ";
                temp = temp->next;
        }
        cout << "nullptr" << endl;
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
        ListNode* l = initialize({3, 2, 0, 4});
        cout << l;
        makeCycle(l, 2);
        // showCycle(l, 10);
        cout << hasCycle1(l) << endl;

        return 0;
}
