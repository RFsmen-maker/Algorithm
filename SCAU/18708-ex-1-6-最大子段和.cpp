/*
 * 18708. ex 1.6 最大子段和
 * 找出连续非空段使段和最大
 * 标签：Divide and Conquer, DP, Segment Tree, Greedy
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

// 动态规划：
// 1. 定义状态：dp[i]：[1, i] 之间，以 arr[i] 为结尾的子段中，最大的一个子段和，用 sum 更新记录
// 2. 状态转移条件：如果都是整数，显然一直加就是最大的，答案就是 dp[i]
//      遇到了负数，依照定义状态，必须加上这个负数
//      负数过后，如果遇到的元素比前面加起来的还要大，那么从这个从头开始
// 3. 转移方程：dp[i] = max(dp[i-1] + arr[i], arr[i]);
void dp(vector<int> &arr)
{
        int cur, sum;
        cur = sum = arr[0];
        for (int i = 1; i < n; ++i)
        {
                cur = max(cur + arr[i], arr[i]);
                if (cur > sum) sum = cur;
        }
        cout << sum;
}

// 贪心：其实跟动态规划没区别。。。

int main(void)
{
        ios::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
        cin >> n;
        if (n == 0) {
                cout << 0;
                return 0;
        }
        if (n == 1) {
                int temp;
                cin >> temp;
                cout << temp;
                return 0;
        }
        vector<int> arr(n);
        for (int &i : arr) cin >> i;

        dp(arr);

        return 0;
}
