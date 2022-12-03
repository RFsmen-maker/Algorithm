// 旋转数组，三种方法尝试
#include <iostream>
#include <vector>

using namespace std;

// 借助辅助数组
void rotate1(vector<int>& nums, int k)
{
        int tempArr[nums.size()];
        k %= nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
                tempArr[((k + i) % nums.size())] = nums[i];
        }
        for(int i = 0; i < nums.size(); i++)
        {
                nums[i] = tempArr[i];
        }
}

// 一次一次往后推
void rotate2(vector<int>& nums, int k)
{
        k %= nums.size();
        int temp;
        while(k--)
        {
                int temp = nums[nums.size()-1];
                for(int i = nums.size()-1; i > 0; --i)
                {
                        nums[i] = nums[i-1];
                }
                nums[0] = temp;
        }
}

// 多次反转
//void reverse(vector<int> &nums, int st, int ed)
//{
//        int temp;
//        for(int i = 0; i < (ed-st)/2; i++)
//        {
//                temp = nums[st+i];
//                nums[st+i] = nums[ed-i-1];
//                nums[ed-i-1] = temp;
//        }
//}
void reverse(vector<int> &nums, int st, int ed)
{
        int temp;
        int half = (st + ed) / 2;
        for(int i = st; i < half; i++)
        {
                temp = nums[i];
                nums[i] = nums[ed - (i - st)];
                nums[ed - (i - st)] = temp;
        }
}
void rotate3(vector<int>& nums, int k)
{
        k %= nums.size();
        reverse(nums, 0, nums.size());
        reverse(nums, 0, k);
        reverse(nums, k, nums.size());
}

int main(void)
{
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
        rotate3(nums, 3);
        for(auto it = nums.begin(); it != nums.end(); it++)
        {
                cout << *it << endl;
        }

        return 0;
}
