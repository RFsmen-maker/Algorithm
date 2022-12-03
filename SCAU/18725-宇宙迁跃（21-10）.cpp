/*
 * 18725. 宇宙迁跃
 * 二分查找
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> &pre, const int step, const int k) {
        int len = pre.size(), cur = 0, count = 0, sum = 0;
        while (count < k && cur < len) {
                if (sum + pre[cur] <= step) sum += pre[cur++];
                else sum = 0, count++;
        }
        if (cur < len) return false; // 没到对岸
        else return true;
}
int main(void)
{
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int &i : arr) cin >> i;

        if (k == 1) { // 只跳一次
                cout << arr[n-1];
                return;
        }
        if (n == 1) { // 只有对岸
                cout << arr[0];
                return;
        }

        vector<int> pre(n); // 差数，便于计算
        pre[0] = arr[0];
        for (int i = 1; i < n; ++i) pre[i] = arr[i] - arr[i-1];

        if (k >= n) { // 跳跃次数多于等于石头，直接找最大间隔
                int res = pre[0];
                for (int i = 1; i < n; ++i) if (pre[i] > res) res = pre[i];
                cout << res;
                return;
        }

        int mid, left = arr[0] - 1, right = arr[n-1] + 1, minStep = arr[n-1];
        while (left + 1 != right) {
                mid = (right + left) / 2;
                if (check(pre, mid, k)) minStep = min(mid, minStep), right = mid; // 继续找更小的
                else left = mid; // 无法跳过肯定是不够大
        }
        // 只要够大，一定能跳过去！
        cout << minStep;

        return 0;
}
