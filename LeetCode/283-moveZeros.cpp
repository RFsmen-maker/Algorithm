// 把零丢后面
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//简化版本
void moveZeroes(vector<int>& nums)
{
        int n = nums.size(), right = 0, left = 0;
        while(right < n)
        {
                if(nums[right]) {
                        swap(nums[right], nums[left]);
                        left++;
                }
                right++;
        }
}
// 找到一个零再往后找一个非零交换
void moveZeroes1(vector<int>& nums)
{
        if(nums.empty() || nums.size() == 1) return;
        for(int i = 0; i < nums.size(); i++)
        {
                if(nums[i] == 0) {
                        int nexInt = i+1;
                        while(nexInt < nums.size() && nums[nexInt++] == 0);
                        if(nums[nexInt-1] == 0) return ;
                        //cout << "this int index" << nexInt-1 << endl;
                        swap(nums[nexInt-1], nums[i]);
                }
        }
}
int main(void)
{
        vector<int> nums= {0, 1, 0, 3, 12};
        moveZeroes(nums);
        for(int num : nums)
                cout << num << endl;

        return 0;
}
