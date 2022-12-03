/*
 * 18942-ex3.2 偏爱字母
 * 常规 dp 题
 */
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
        int len;
        cin >> len;
        string str;
        cin >> str;

        vector<int> nums(len); // 按照提示转换成 1, -1 数组
        for (int i = 0; i < len; ++i) nums[i] = (str[i] == 'E' ? 1 : -1);

        vector<int> dp(len, 0); // 定义状态：包含 str[i] 的子串的最大差数
        dp[0] = max(dp[0], nums[0]);
        int maxSub = dp[0];
        for (int i = 1; i < len; ++i) {
                dp[i] = max(nums[i] + dp[i-1], dp[i]); // 状态转移：遇到 E 直接增加，遇到 F，-1
                if (dp[i] > maxSub) maxSub = dp[i];
        }
        cout << maxSub;

        return 0;
}
