/*
 * 152. 乘积最大子数组
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct_DP(vector<int>& nums)
{
        // 1. 状态定义，DP[i]：[0, i] 之中最大 subProduct
        // 2. 状态转移方程：全正数时，越乘越大，DP[i] = DP[i-1] * nums[i]
        // 但在负数的时候，乘上就变成最小，要找一个最小的 min，因此还要多存一个数
        // 题目要求连续，因此加入对 nums 的判断以截断
        int len = nums.size();
        if (len < 2) return nums[0];

        int maxMul, minMul, res;
        res = maxMul = minMul = nums[0];
        for (int i = 1; i < len; ++i)
        {
                int tempMax = maxMul * nums[i];
                int tempMin = minMul * nums[i];
                maxMul = max({tempMax, tempMin, nums[i]});
                minMul = min({tempMax, tempMin, nums[i]});

                if (maxMul > res) res = maxMul;
        }

        return res;
}

// try1：暴力解乘积最大子序列，显然超时，但是 182 / 188 pass
void helper_Brute(vector<int> &nums, int pos, int &maxMul, int curMul)
{
        if (curMul > maxMul) maxMul = curMul;

        int len = nums.size();
        if (pos == len) return ;

        helper_Brute(nums, pos+1, maxMul, nums[pos]); // 不乘，而且截断
        helper_Brute(nums, pos+1, maxMul, nums[pos] * curMul); // 乘
}
int maxProduct_Brute(vector<int>& nums)
{
        if (nums.size() == 1) return nums[0]; // 题目特殊要求

        int maxMul = INT_MIN;
        int curMul = nums[0];
        helper_Brute(nums, 1, maxMul, curMul);
        return maxMul;
}

int main(void)
{
        vector<int> nums = {-2, 0, -1};
        cout << maxProduct_DP(nums) << endl;


        return 0;
}
