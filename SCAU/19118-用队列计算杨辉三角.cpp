/*
 * 19118. 用队列计算杨辉三角
*/
#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
        ios::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
        queue<size_t> q({1, 0});
        size_t n;
        cin >> n;

        if (n == 1) {
                cout << 1;
                return 0;
        }

        // 初始化
        size_t cur, count = 1, last = 0;
        while (count < n) {
                cur = q.front();
                q.push((cur + last) % 1000000007);
                if (cur == 0) {
                        q.push(0);
                        count++;
                }
                last = cur;
                q.pop();
        }

        while (!q.empty())
        {
                if (q.front() != 0) cout << q.front() << ' ';
                q.pop();
        }

        return 0;
}

