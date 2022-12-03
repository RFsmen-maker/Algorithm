/*
 * 18959. 二叉树的之字形遍历
 */
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

// 根本不用建树！
int main(void)
{
        string str;
        cin >> str;
        if (str.empty()) {
                return 0;
        }

        deque<int> q;
        const char dummy = -1;
        q.push_back(1);
        q.push_back(dummy);
        cout << str[0];

        int len = str.size();
        bool flag = true;
        while (!(q.size() == 1 && q.front() == dummy)) { // 可能需要考虑去除多余的
                queue<int> output;
                if (flag) {
                        while (q.front() != dummy) {
                                int cur = q.front(), left = cur * 2, right = left + 1;
                                q.pop_front();
                                if (right <= len) {
                                        q.push_back(right);
                                        if (str[right-1] != '#') output.push(right);
                                }
                                if (left <= len) {
                                        q.push_back(left);
                                        if (str[left-1] != '#') output.push(left);
                                }
                        }
                }
                else {
                        while (q.back() != dummy) {
                                int cur = q.back(), left = cur * 2, right = left + 1;
                                q.pop_back();
                                if (left <= len) {
                                        q.push_front(left);
                                        if (str[left-1] != '#') output.push(left);
                                }
                                if (right <= len) {
                                        q.push_front(right);
                                        if (str[right-1] != '#') output.push(right);
                                }
                        }
                }
                if (!output.empty()) cout << endl;
                while (!output.empty()) cout << str[output.front() - 1] << ' ', output.pop();
                flag = !flag;
        }

        return 0;
}
