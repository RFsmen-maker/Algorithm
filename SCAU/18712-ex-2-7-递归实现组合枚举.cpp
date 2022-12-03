/*
 * 18712-ex2.7 递归实现组合枚举
*/
#include <iostream>
#include <vector>

using namespace std;

int m, k;
int arr[11]; // +1 偏移

void dfs(int cur, vector<int> pick) {
        if (static_cast<int>(pick.size()) == k) {
                for (int i : pick) cout << i << ' ';
                cout << endl;
                return;
        }
        if (cur > m) return;

        pick.push_back(arr[cur]);
        dfs(cur+1, pick);
        pick.pop_back();
        dfs(cur+1, pick);
}

int main(void)
{
        cin >> m >> k;
        for (int i = 1; i <= m; ++i) arr[i] = i; // 偏移
        vector<int> pick;
        dfs(1, pick);

        return 0;
}
