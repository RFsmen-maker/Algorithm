#include <iostream>
#include <String>

using namespace std;

// 快慢指针
ListNode* middleNode(ListNOde* head)
{
        auto fast = head, slow = head;
        while(fast != NULL && fast->next != NULL)
                slow = slow->next, fast = fast->next->next;
        return slow;
}
// 数长度再走一半
ListNode* middleNode(ListNode* head)
{
        int len = 0;
        auto tempP = head;

        while(tempP != NULL) tempP = tempP->next, len++;
        len /= 2;

        tempP = head;
        while(len--) tempP = tempP->next;

        return tempP;
}

int main(void)
{

        cout << temp << endl;

        return 0;
}
