/*
* 19.删除倒数第 N 个结点
*/

#include <iostream>
#include <algorithm>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 快慢指针
ListNode* removeNthFromEnd(ListNode* head, int n)
{
        if(head == NULL) return head;
        else if(head->next == NULL) return NULL;

        auto fast = head, slow = head;
        while(n--) fast = fast->next;
        if(fast == NULL) return head->next;
        while(fast->next != NULL)
                slow = slow->next, fast = fast->next;
        slow->next = slow->next->next;

        return head;
}

// 暴力解法
ListNode* removeNthFromEnd(ListNode* head, int n)
{
        ListNode* tempP = head;
        int count = 0;
        while(tempP != NULL)
        {
                count++;
                tempP = tempP->next;
        }

        count -= (n + 1);
        if(count < 0) return head->next;
        else {
                tempP = head;
                while(count--) tempP = tempP->next;
                tempP->next = tempP->next->next;
        }
        return head;
}

int main(void)
{



        return 0;
}
