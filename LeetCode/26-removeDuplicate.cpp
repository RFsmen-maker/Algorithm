// 删除排序数组重复项
#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
        if(nums.empty()) return 0;
        int cur = 0;
        for(int i = 1; i < nums.size(); i++)
        {
                if(nums[i] != nums[cur]) nums[++cur] = nums[i];
        }
        return cur+1;
}
int main(void)
{
        vector<int> nums = {0,1,1,1,2,2,3,3,4};
        int temp = removeDuplicates(nums);
        for(int i = 0; i < temp; ++i)
                cout << nums[i] << endl;

        return 0;
}
