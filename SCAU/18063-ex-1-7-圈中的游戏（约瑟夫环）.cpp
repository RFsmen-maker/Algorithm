/*
 * 18063-ex 1.6 圈中游戏
 * times : 2
 * 指定人数，每次报数到 3 退圈
 * 输出留下人的编号
 * 递推公式：pos = ((0 + m) % n + m) % (n + 1) ...
*/
#include <iostream>
#include <list>

using namespace std;

void formula(int n)
{
        int s = 0;
        for (int i = 2; i <= n; ++i) s = (s + 3) % i;
        cout << s+1;
}

// 链表暴力模拟，显然超时
void bruteList(int n)
{
        list<int> L; // 以数组模拟链表
        for (int i = 0; i < n; ++i) L.push_back(i+1);

        int count = 1;
        auto cur = L.begin();
        while (L.size() != 1) {
                cur++, count++;
                if (cur == L.end()) cur = L.begin(); // 手动调循环
                if (count == 3) {
                        // cout << "erase : " << *cur << endl;
                        count = 1, cur = L.erase(cur);
                }
                if (cur == L.end()) cur = L.begin(); // 手动调循环
        }
        cout << *(L.begin());
}

int main(void)
{
        int n;
        cin >> n;

        if (n == 1) {
                cout << 1;
                return 0;
        }

        formula(n);

        return 0;
}
