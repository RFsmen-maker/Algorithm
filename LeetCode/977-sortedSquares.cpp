// 有序数组平方
// 要想有一个 S = O(1)
// 需要在每次选到最大值后局部交换排序，导致 T = O(nlog2n)
// 还不如直接全部平方再快排
#include <iostream>
#include <vector>

using namespace std;

// 双指针办法
vector<int> sortedSquares2(vector<int>& nums)
{
        vector<int> tempArr(nums.size());
        for(int left = 0, right = nums.size()-1, pos = right; left <= right; )
        {
                if(nums[left] * nums[left] >= nums[right] * nums[right])
                        tempArr[pos--] = nums[left] * nums[left++];
                else
                        tempArr[pos--] = nums[right] * nums[right--];
        }
        return tempArr;
}

// 归并办法，代码太冗长
vector<int> sortedSquares1(vector<int>& nums)
{
        int minIndex = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
                nums[i] *= nums[i];
                if(nums[i] < nums[minIndex]) minIndex = i;
        }

        vector<int> tempArr;
        if(minIndex == 0) return nums;
        else {
                int left = minIndex - 1, right = minIndex+1;
                tempArr.push_back(nums[minIndex]);
                while(left >= 0 && right < nums.size())
                {
                        if(nums[left] >= nums[right])
                                tempArr.push_back(nums[right++]);
                        else tempArr.push_back(nums[left--]);
                }
                while(left >= 0) tempArr.push_back(nums[left--]);
                while(right < nums.size()) tempArr.push_back(nums[right++]);
        }
        return tempArr;
}
int main(void)
{
        cout << "try" << endl;
        vector<int> nums = {-5, -3, -2, -1};
        auto temp = sortedSquares3(nums);
        for(int i = 0; i < temp.size(); i++)
                cout << temp[i] << endl;

        return 0;
}
