#include <iostream>
#include <algorithm>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

// 两数之和

// 官方优化解法：使用哈希表
vector<int> twoSum1(vector<int>& nums, int target)
{
        int len = nums.size();
        vector<int> dest(2);
        unordered_map<int, int> hashMap(len-1);
        hashMap.emplace(nums[0], 0);
        for(int i = 0; i < len; ++i)
        {
                if(hashMap.find(target - nums[i]) != hashMap.end()) {
                        dest[0] = hashMap.at(target - nums[i]);
                        dest[1] = i;
                }
                hashMap.emplace(nums[i], i);
        }

        return dest;
}

// 暴力解法
vector<int> twoSum(vector<int>& nums, int target)
{
        int len = nums.size();
        vector<int> dest(2);
        for(int i = 0; i < len-1; ++i)
        {
                for(int j = i+1; j < len; ++j)
                {
                        if(nums[i] + nums[j] == target) {
                                dest[0] = i, dest[1] = j;
                                return dest;
                        }
                }
        }

        return dest;
}

int main(void)
{
        int p;
        cout << "测试案例？" << endl;
        cin >> p;
        int target[] = {9, 6, 6};
        vector<int> nums[] = {
                {2, 7, 11, 15},
                {3, 2, 4},
                {3, 3}};
        vector<int> res = twoSum1(nums[p], target[p]);
        cout << "res : " << res[0] << ' ' << res[1] << endl;

        return 0;
}
