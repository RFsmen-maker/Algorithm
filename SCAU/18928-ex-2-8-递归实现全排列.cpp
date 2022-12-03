/*
 * 18928-ex2.8 递归实现全排列
 * times : 2
*/
#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[10]; // 1 <= n <= 9

void dfs(int cur, vector<int> seCase, vector<bool> visited) {
        if (cur == n) {
                for (int i : seCase) cout << i << ' ';
                cout << endl;
                return;
        }
        for (int i = 1; i <= n; ++i)
        {
                if (visited[i]) continue; // 上一层递归取用过直接跳过

                visited[i] = true;
                seCase.push_back(arr[i]);

                dfs(cur+1, seCase, visited);

                visited[i] = false; // 还原现场
                seCase.pop_back();
        }
}

int main(void)
{
        cin >> n;
        for (int i = 1; i <= n; ++i) arr[i] = i; // 1 ~ n

        vector<int> seCase;
        vector<bool> visited(n+1);
        dfs(0, seCase, visited);

        return 0;
}
