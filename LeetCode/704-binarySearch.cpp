// 二分查找
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& nums, int target) {
        int left, mid, right;
        left = 0;
        right = nums.size()-1;
        while(left <= right)
        {
                mid = (left + right) / 2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target) right = mid - 1;
                else if(nums[mid] < target) left = mid + 1;
        }
        return -1;
}

int main(void)
{
        vector<int> arr = {-1, 0, 3, 5, 9, 12};
        cout << binarySearch(arr, 9);

        return 0;
}
