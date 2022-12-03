#include <iostream>
#include <vector>

using namespace std;

// 求一个数组中，选取互不相邻的若干组数，这些数组中最大和值
// 如 4 1 1 9 1 得 13

int selectMax(vector<int> nums)
{
        int len = nums.size();
        int opt[len], pre[len], temp;

        for(int i = 0; i < len; ++i) pre[i] = i - 2;

        opt[0] = nums[0];
        for(int i = 1; i < len; ++i)
        {
                temp = nums[i] + (pre[i] < 0 ? 0 : opt[pre[i]]);
                opt[i] = opt[i-1] > temp ? opt[i-1] : temp;
        }

        return opt[len-1];
}

int main(void)
{
        vector<int> nums0 = {4, 1, 1, 9, 1}; // 13
        vector<int> nums1 = {1, 2, 4, 1, 7, 8, 3}; // 15
        cout << selectMax(nums1);

        return 0;
}
