/*
 * 19044-ex2.9 平分物品
 * times : 2
*/
#include <iostream>
#include <vector>

using namespace std;

// 指数枚举，找扔最少，拿的越多，扔的越少，一定是看完所有东西后
void dfs(size_t n, vector<int> &stuff, size_t cur, int dump, int &record, int p1, int p2) {
        if (cur == n) {
                if (p1 != 0 && p2 != 0 && p1 == p2 && dump < record) record = dump;
                return;
        }
        dfs(n, stuff, cur+1, dump, record, p1 + stuff[cur], p2); // 给 p1
        dfs(n, stuff, cur+1, dump + stuff[cur], record, p1, p2); // 扔了
        dfs(n, stuff, cur+1, dump, record, p1, p2 + stuff[cur]); // 给 p2
}

int main(void)
{
        int T;
        cin >> T; // 多组测试数据
        for (int i = 0; i < T; ++i) {
                size_t n;
                cin >> n;
                vector<int> stuff(n);
                for (int &i : stuff) cin >> i;

                if (n == 1) {
                        cout << stuff[0] << endl;
                        continue;
                }

                int record = 100000; // 1 <= a[i] <= 100000
                dfs(n, stuff, 0, 0, record, 0, 0);
                cout << record << endl;
        }

        return 0;
}

