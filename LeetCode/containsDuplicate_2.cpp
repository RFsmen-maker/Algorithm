#include <iostream>
#include <algorithm>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

// 判断是否存在重复元素
/* 肯定不是用 O(n^2) 的暴力解法
 * 可以直接先排序，但最少 O(nlog2n)
 * 正式解答：使用 STL 的 set 和哈希码
*/

// 排序版
bool containsDuplicate2(vector<int>& nums)
{
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i < len; ++i) if(nums[i-1] == nums[i]) return true;
        return false;
}

// 自制简易哈希码，有时比 STL 快
bool containsDuplicate1(vector<int>& nums)
{
        int len = nums.size();
        int temp;
        vector<int> tempArr[len];
        for(int i = 0; i < len; ++i)
        {
                temp = nums[i] % len;
                if(temp < 0) temp += len;
                if(tempArr[temp].empty())
                        tempArr[temp].push_back(nums[i]);
                else { // 非空列
                        for(int n : tempArr[temp]) if(nums[i] == n) return true;
                        tempArr[temp].push_back(nums[i]);
                }
        }
        return false;
}

// STL set
bool containsDuplicate(vector<int>& nums)
{
        unordered_set<int> st;
        for(auto num : nums) {
                if(st.find(num) == st.end()) st.insert(num);
                else return true;
        }
        return false;
}
int main(void)
{
        vector<int> nums = {3, 1};
        cout << containsDuplicate2(nums);

        return 0;
}
