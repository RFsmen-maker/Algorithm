/*
 * 18927. ex 1.3 前缀和
 * times: 2
*/
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;

int main(void)
{
        ios::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);

        cin >> n;
        vector<int> arr(n);
        for (int &i : arr) cin >> i;

        vector<long> preSum(n+1); // 计算前缀和，为了方便计算，进行偏移
        preSum[0] = 0;
        for (int i = 1; i <= n; ++i) preSum[i] = preSum[i-1] + arr[i-1];

        int m, L, R; // 查询次数，查询左右范围
        cin >> m;
        for (int i = 0; i < m; ++i) {
                cin >> L >> R;
                cout << preSum[R] - preSum[L - 1] << endl; // 已经偏移过，可以直接减得
        }

        return 0;
}

