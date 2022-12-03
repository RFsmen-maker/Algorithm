/*
 * 2.6 表达式求值
 * 直接使用 STL
 * 自测没问题，但是华南 OJ WA
*/
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// 转换规则：遇到数字一律入队，cache 顶部优先级更高时弹出，入队
// 考虑先中缀表达式转成后缀表达式计算
int main(void)
{
        ios::sync_with_stdio(false);
        // 直接使用队列保存转换的得到的后缀表达式，借助一个缓存符号栈完成
        deque<pair<int, bool>> dest; // false 数字，true 运算符
        stack<pair<int, bool>> cache;
        char ch, last;
        while ((ch = cin.get()) != '=')
        {
                if (ch <= '9' && ch >= '0') { // 数都直接进去
                        int temp = static_cast<int>(ch - '0');
                        if (!dest.empty() && last <= '9' && last >= '0') {
                                temp += dest.back().first * 10;
                                dest.pop_back();
                        }
                        dest.push_back(pair<int, bool>(temp, false));
                }
                else {
                        switch(ch)
                        {
                        case '*': case '/': case '(': cache.push(pair<int, bool>(ch, true)); break;
                        case '+': case '-':
                                while (!cache.empty() && (cache.top().first == '*' || cache.top().first == '/'))
                                {
                                        dest.push_back(cache.top());
                                        cache.pop();
                                }
                                cache.push(pair<int, bool>(ch, true));
                                break;
                        case ')':
                                while (cache.top().first != '(')
                                {
                                        dest.push_back(cache.top());
                                        cache.pop();
                                }
                                cache.pop(); // 清除掉 '('
                                break;
                        }
                }
                last = ch;
        }
        // 剩下的处理
        while (!cache.empty())
        {
                dest.push_back(cache.top());
                cache.pop();
        }

        // 转换结果测试
        for (pair<int, bool> i : dest)
        {
                if (i.second) {
                        cout << static_cast<char>(i.first);
                } else cout << static_cast<int>(i.first);
        }
        cout << endl;

        // 进行计算，需要辅助数栈
        stack<int> num;
        for (auto it : dest)
        {
                if (it.second) {
                        int right = num.top();
                        num.pop();
                        int left = num.top();
                        num.pop();
                        int op = it.first;
                        switch(op)
                        {
                        case '+': num.push(left + right); break;
                        case '-': num.push(left - right); break;
                        case '*': num.push(left * right); break;
                        case '/': num.push(left / right); break;
                        }
                } else num.push(it.first);
        }
        cout << num.top() << endl;

        return 0;
}
