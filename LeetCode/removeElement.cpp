// 移除元素
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
        int count = 0;
        int length = nums.size();
        for(int i = 0; i < length; ++i)
        {
                if(nums[i] != val) nums[count++] = nums[i];
        }
        return count;
}

int main(void)
{
        vector<int> nums= {3,2,2,3};
        int temp = removeElement(nums, 3);
        for(int num : nums)
                cout << num << endl;

        return 0;
}
