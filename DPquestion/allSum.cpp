#include <iostream>
#include <vector>

using namespace std;

// 迭代版
bool allSum(vector<int> nums, int target)
{
        int len = nums.size();
        int wid = target+1;
        bool flag[len][wid];
        for(int i = 0; i < len; ++i)
        {
                for(int j = 0; j < wid; ++j)
                {
                        if(j == 0) {
                                flag[i][j] = true;
                        }
                        else if(i == 0) {
                                if(nums[j] == j) flag[i][j] = true;
                                else flag[i][j] = false;
                        }
                        else {
                                if(nums[i] > j) flag[i][j] = flag[i-1][j];
                                else flag[i][j] = flag[i-1][j] || flag[i-1][j - nums[i]];
                        }
                }
        }
        return flag[len-1][wid-1];
}

// 递归版
bool allSum(vector<int> nums, int i, int target)
{
        if(target == 0) return true;
        else if(i == 0) return (nums[0] == target);
        else if(nums[i] > target) return allSum(nums, i-1, target);
        else {
                return (allSum(nums, i-1, target - nums[i])
                        || allSum(nums, i-1, target));
        }
}

int main(void)
{
        vector<int> nums = {3, 34, 4, 12, 5, 2};
        cout << allSum(nums, 13) << endl;
        cout << allSum(nums, 12) << endl;
        cout << allSum(nums, 11) << endl;
        cout << allSum(nums, 10) << endl;
        cout << allSum(nums, 9) << endl;

        return 0;
}
