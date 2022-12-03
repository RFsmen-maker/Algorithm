#include <iostream>
#include <vector>

using namespace std;

int maximumDifference(vector<int>& nums)
{
        int len = nums.size();
        int ans = -1;
        int premin = nums[0];
        for (int i = 1; i < len; ++i)
        {
                if (nums[i] > premin) ans = max(ans, nums[i] - premin);
                else premin = nums[i];
        }
        return ans;
}

int main(void)
{
        vector<int> nums= {87,68,91,86,58,63,43,98,6,40};
        cout << maximumDifference(nums);
        return 0;
}
