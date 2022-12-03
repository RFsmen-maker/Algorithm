/*
 * 300. 最长上升子序列
 */
#include <iostream>
#include <vector>

using namespace std;

// 二分查找方法
int lengthOfLIS_Bin(vector<int> &nums)
{
        vector<int> res;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
                auto it = lower_bound(res.begin(), res.end(), nums[i]); // 不大于 nums[i] 的下一位置，替换 / 插入
                if (it == res.end()) res.push_back(nums[i]); // 插入
                else *it = nums[i]; // 替换
        }
        return res.size();
}

// 动规方法，T = O(n^2)
// 1. 状态定义：dp[i] 包括 nums[i] 的最长子序列的长度
int lengthOfLIS_DP(vector<int> &nums)
{
        int len = nums.size();
        int dp[len], maxLen = 1;
        dp[0] = 1;
        for (int i = 1; i < len; ++i) {
                int tempMax = 1;
                for (int j = 0; j < i; ++j) {
                        if (nums[i] > nums[j]) tempMax = max(dp[j] + 1, tempMax);
                }
                dp[i] = tempMax;
                maxLen = max(dp[i], maxLen);
        }
        return maxLen;
}

int main(void)
{
        vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18, 20};
        cout << lengthOfLIS_DP(nums);

        return 0;
}
