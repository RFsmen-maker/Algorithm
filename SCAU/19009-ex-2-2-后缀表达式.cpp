/*
 * ex2.2 后缀表达式
*/
#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
        stack<int> nums, ops;
        char ch;
        while ((ch = getchar()) != '@')
        {
                if (ch <= '9' && ch >= '0') {
                        nums.push(static_cast<int>(ch - '0'));
                }
                else {
                        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') continue;
                        int right = nums.top();
                        nums.pop();
                        int left = nums.top();
                        nums.pop();
                        switch (ch) {
                        case '+': nums.push(left + right); break;
                        case '-': nums.push(left - right); break;
                        case '*': nums.push(left * right); break;
                        case '/': nums.push(left / right); break;
                        }
                }
        }
        cout << nums.top();

        return 0;
}
