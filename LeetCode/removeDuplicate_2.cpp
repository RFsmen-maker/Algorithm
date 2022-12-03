// 有序数组删重复，最多留两个
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
        int length = nums.size();

        if(nums.empty()) return 0;
        else if(length <= 2) return length;

        int tempCount = 0, count = 0;
        for(int i = 1; i < length; ++i)
        {
                if(nums[i] != nums[count]) {
                        nums[++count] = nums[i];
                        tempCount = 1;
                }
                else {
                        if(tempCount < 2) {
                                nums[++count] = nums[i];
                                tempCount = 2;
                        }
                }
        }

        return count+1;
}

int main(void)
{
        vector<int> nums= {1,1,1,2,2,3};
        int temp = removeDuplicates(nums);
        for(int i = 0; i < temp; ++i)
        {
                cout << nums[i] << endl;
        }

        return 0;
}
