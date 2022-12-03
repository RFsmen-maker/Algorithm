/*
* 25. 括号匹配
*/

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

bool isValid(string s)
{
        if(s.size() % 2) return false; // 过滤不可能匹配的奇数情况

        // 查找表建立，左边是键，右边是值
        // 右括号作为键，遇到后要与栈顶比较匹配
        unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> myStack;

        for (char ch : s)
        {
                if (pairs.count(ch)) { // 遇到右括号查栈
                                if (myStack.empty() || myStack.top() != pairs[ch]) {
                                return false;
                        }
                        myStack.pop();
                }
                else {
                        myStack.push(ch);
                }
        }

        return myStack.empty();
}

int main(void)
{
        cout << isValid("()[]{}") << endl;

        return 0;
}
