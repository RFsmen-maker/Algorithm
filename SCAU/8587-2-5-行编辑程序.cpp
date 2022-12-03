/*
 * 8587-2.5 行编辑程序
 * times : 2
 * 不填空，直接用容器
 * 由于输出又要从栈底开始，直接用双端队列
*/
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
        int n;
        cin >> n;
        getchar(); // 过滤回车符
        deque<char> s;
        for (int i = 0; i < n; ++i) {
                string str;
                getline(cin, str, '\n');
                for (char ch : str) {
                        switch (ch)
                        {
                                case '#' : s.pop_back(); break;
                                case '@' : s.clear(); break;
                                default : s.push_back(ch);
                        }
                }
                while (!s.empty()) {
                        cout << s.front();
                        s.pop_front();
                }
                cout << endl;
        }

        return 0;
}
