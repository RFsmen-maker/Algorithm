/*
* 234.判断是否回文链表
*/
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 空间复杂度 O(n), 读取判断
bool isPalindrome(ListNode* head)
{
        vector<int> arr;
        auto temp = head;
        while(temp != NULL)
        {
                arr.push_back(temp->val);
                temp = temp->next;
        }
        if(arr.empty()) return false;
        else if(arr.size() == 1) return true;
        int len = arr.size();
        for(int i = 0; i < len; i++)
        {
                if(arr[i] != arr[len - 1 - i]) return false;
        }
        return true;
}

void reverseList(ListNode *head, ListNode *stop)
{
        ListNode *temp = head;
        ListNode *next = NULL;
        while(next != stop)
        {
                auto tempCur = temp->next;
                temp->next = next;
                next = temp;
                temp = tempCur;
        }
}
// 空间复杂度 O(1) 算法
bool isPalindrome1(ListNode* head)
{
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
                len++;
                temp = temp->next;
        }
        if(len == 0) return false;
        else if(len == 1) return true;
        else if(len == 2) return head->val == head->next->val;

        int half = len / 2 - 1;
        temp = head;
        while(half--) temp = temp->next;
        ListNode *back = temp;
        ListNode *forward = (len % 2) ? temp->next->next : temp->next;

        reverseList(head, back);

        while(back != NULL && forward != NULL)
        {
                if(back->val != forward->val) return false;
                back = back->next;
                forward = forward->next;
        }

        return true;
}

// 尾插法创建链表
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
        vector<int> arr = {1, 0, 1};
        struct ListNode *L = initialize(arr);
        if(isPalindrome1(L)) cout << "True.";
        else cout << "False.";

        return 0;
}
