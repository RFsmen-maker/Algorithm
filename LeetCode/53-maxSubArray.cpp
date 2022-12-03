/*
 * 53. 最大子段和
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 动态规划：若前一个元素大于 0，将其加到当前元素上
// 递推公式：f(i) = max(f(i-1) + num[i], num[i]);
int maxSubArray_DP(vector<int>& nums)
{
        int len = nums.size();
        if (len == 0) return INT_MIN;
        if (len == 1) return nums[0];

        // 初始化
        int maxSum, pre;
        maxSum = pre = nums[0];

        for (int i = 1; i < len; ++i)
        {
                nums[i] = max(nums[i-1] + nums[i], nums[i]);
                if (nums[i] > maxSum) maxSum = nums[i];
        }

        return maxSum;
}

// 分治，归并思想
int maxSubArray_Divid(vector<int>& nums)
{

}

// 贪心算法
int maxSubArray_Greedy(vector<int>& nums)
{
        int len = nums.size();
        if (len == 0) return INT_MIN;
        if (len == 1) return nums[0];

        int maxSum, temp;
        maxSum = temp = nums[0];
        for (int i = 1; i < len; ++i)
        {
                temp = max(nums[i], nums[i] + temp);
                maxSum = max(temp, maxSum);
        }

        return maxSum;
}

int main(void)
{
        vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
        cout << maxSubArray_DP(nums);

        return 0;
}
