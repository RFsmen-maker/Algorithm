//搜索插入位置：找目标，找不到找插入位置
// 注意边界问题即可

#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
        if(target < nums[0]) return 0;
        else if(target > nums[nums.size()-1]) return nums.size();
        int low = 0, high = nums.size()-1;
        while(low <= high)
        {
                int mid = low + (high - low) / 2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target) high = mid-1;
                else if(nums[mid] < target) low = mid+1;
        }
        return low;
}
int main(void)
{
        vector<int> nums = {1, 3, 5, 6};
        cout << searchInsert(nums, 7);

        return 0;
}


