/*
* 142. 链表找到环起始位置
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

// 真正的双指针法
// 设头到入口距离 x
// 设相遇时，入口点到相遇点距离 y，相遇到入口距离 z，fast 指针走过 n 圈环
// 由简单代数推导可得 x = (y+z)*n + z
// 即有：从相遇点再走过 n 圈再到入口的距离，相当于链表头到入口点距离
ListNode *detectCycle2(ListNode *head)
{
        if(head == nullptr || head->next == nullptr) return NULL;

        ListNode *fast, *slow;
        slow = fast = head;
        while(fast && fast->next)
        {
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow) {
                        ListNode* dest = head;
                        while(dest != slow)
                        {
                                dest = dest->next;
                                slow = slow->next;
                        }
                        return dest;
                }
        }
        return NULL;
}

// 略微改进
// 双指针法，不等速前进的指针迟早遇到
// 把环入哈希表，再重头开始找起始位置
// S = O(m), m = cycle.size()
#include <unordered_set>
ListNode *detectCycle1(ListNode *head)
{
        if(head == nullptr || head->next == nullptr) return NULL;

        unordered_set<ListNode*> cycle;
        ListNode *fast, *slow;
        fast = head->next;
        slow = head;
        while(fast && fast->next  && slow)
        {
                if(fast == slow) { // 找到环
                        cycle.insert(slow);
                        fast = slow->next;
                        while (fast != slow) // 把整个环入哈希表
                        {
                                cycle.insert(fast);
                                fast = fast->next;
                        }
                        fast = head; // 从头开始找起始位置
                        while(!cycle.count(fast))
                        {
                                fast = fast->next;
                        }
                        return fast;
                }
                fast = fast->next->next;
                slow = slow->next;
        }
        return NULL;
}

// 利用哈希表查找，S = O(n), T = O(n)
#include <unordered_set>
ListNode *detectCycle(ListNode *head)
{
        if(head == nullptr || head->next == nullptr) return NULL;

        ListNode *temp;
        temp = head;
        unordered_set<ListNode*> myHash;
        while(temp != nullptr)
        {
                if (myHash.count(temp)) { // 当前的这一个 temp 已经重复
                        return temp;
                }
                myHash.insert(temp);
                temp = temp->next;
        }
        return NULL;
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
        ListNode* dest = detectCycle2(l);
        if(dest) {
                cout << "dest : " << dest->val << endl;
        }
        else {
                cout << "no cycle" << endl;
        }

        return 0;
}
