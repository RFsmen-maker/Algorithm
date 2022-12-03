/*
 * ex2.6 递归实现指数型枚举
 * times : 2
*/
#include <iostream>

using namespace std;

int n;
int arr[11];

void dfs(int cur, int sum) { // DFS 枚举
        if (cur == n + 1) return;
        cout << sum + arr[cur] << endl;
        dfs(cur+1, sum + arr[cur]); // 选
        dfs(cur+1, sum); // 不选3
}

int main(void)
{
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> arr[i];
        dfs(1, 0);

        return 0;
}
