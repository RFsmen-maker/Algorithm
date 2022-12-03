/*
 * 18933. ex2.1 括号匹配问题
 * times : 2
 * 在相应位置，不能匹配的左括号用 $，右括号 ？
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

const char wL = '$';
const char wR = '?';
char s[205];
int len;

// 第一次做
void try1(void)
{
        while (scanf("%s", s) != EOF)
        {
                string str(s);
                len = str.size();
                string temp(len, ' ');
                stack<int> brack;
                for (int i = 0; i < len; ++i)
                {
                        if (str[i] == '(') brack.push(i);
                        if (str[i] == ')') {
                                if (brack.empty()) temp[i] = wR;
                                else brack.pop();
                        }
                }
                while (!brack.empty())
                {
                        temp[brack.top()] = wL;
                        brack.pop();
                }
                cout << str << endl << temp << endl;
        }
}

// 第二次做：提交前一定要自己编译一次！输入测例检查！
void try2(void)
{
        while (scanf("%s", s) != EOF) {
                string str(s); // 待检查的一行字符串
                len = str.size();
                string res(len, ' '); // 待修改输出的空格串

                stack<int> brack; // 记录左括号的下标位置，遇到右括号而非空时直接出栈，空时直接修改右括号下标位置空格符
                for (int i = 0; i < len; ++i) {
                        if (str[i] == '(') brack.push(i);
                        else if (str[i] == ')') {
                                if (!brack.empty()) brack.pop();
                                else res[i] = wR;
                        }
                        else continue; // 一般其他符号直接跳过
                }
                while (!brack.empty()) { // 剩下的左括号处理
                        res[brack.top()] = wL;
                        brack.pop();
                }
                cout << str << endl << res << endl; // 别忘了还要输出原字符串
        }
}

int main(void)
{
        try2();

        return 0;
}
