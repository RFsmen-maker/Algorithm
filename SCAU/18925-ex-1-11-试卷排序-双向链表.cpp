/*
 * 18925-ex1.11 试卷排序-双向链表
 * times : 2
*/
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

// 迭代器数组秒杀
int main(void)
{
        int n;
        cin >> n;

        list<int> L;
        L.push_back(1);
        vector<list<int>::iterator> itArr(n+1); // 偏移，方便使用
        itArr[1] = L.begin();

        int x, p;
        for (int i = 2; i <= n; ++i) {
                cin >> x >> p;
                auto it = itArr[x]; // x 一定已经在链表里
                if (p) it++; // p 为 1 在右边插入
                itArr[i] = L.insert(it, i); // insert 之后返回的是 insert 位置的指针（迭代器）
        }
        for (int i : L) cout << i << ' ';
}
