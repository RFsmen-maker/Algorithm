/*
 * 15. 三数之和
 *
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 官方解法：排序 + 双指针
vector<vector<int>> threeSum1(vector<int>& nums)
{
        int len = nums.size();
        sort(nums.begin(), nums.end()); // 先排序
        vector<vector<int>> dest;
        for (int i = 0; i < len; ++i) {
                if (i > 0 && nums[i] == nums[i - 1]) continue; // 过滤相同元素
                int right = len - 1;
                int target = -nums[i];
                for (int j = i + 1; j < len; ++j) {
                        if (j > i + 1 && nums[j] == nums[j - 1]) continue; // 再次过滤相同元素
                        while (j < right && nums[j] + nums[right] > target) --right; // 太大，左移
                        if (j == right) break; // 内部遍历与右指针碰撞
                        if (nums[j] + nums[right] == target) {
                                dest.push_back({nums[i], nums[j], nums[right]});
                        }
                }
        }

        return dest;
}

// 基于两数之和的优化办法，把三数之和加一层循环转换成两数之和
// 这个算法虽然能找出来，但是有重复的三元组，需要再加一到过滤算法，已完成
vector<vector<int>> threeSum(vector<int>& nums)
{
        if (nums.size() < 3) {
                return {};
        }

        vector<vector<int>> dest;
        unordered_map<int, int> hashMap;
        int target, targetKey;
        for (vector<int>::iterator it = nums.begin(); (it+2) != nums.end(); ++it)
        {
                hashMap.clear();
                target = -(*it);
                for (auto iit = it+1; iit != nums.end(); ++iit)
                {
                        targetKey = target - (*iit);
                        if (hashMap.find(targetKey) != hashMap.end()) {
                                dest.push_back({(*it), (*iit), targetKey});
                        }
                        auto exist = hashMap.find(*iit);
                        if (exist == hashMap.end()) {
                                hashMap.emplace((*iit), 1);
                        } else {
                                (exist->second)++;
                        }
                }
        }
        cout << "origin: " << endl;
        for (auto p = dest.begin(); p != dest.end(); ++p)
        {
                sort(p->begin(), p->end());
                cout << (*p)[0] << ' ' << (*p)[1] << ' ' << (*p)[2] << endl;
        }

        // 问题来了，怎么过滤掉这么多重复的三元组
        unordered_multimap<int, int> filter;
        for (auto it = dest.begin(); it != dest.end();)
        {
                auto exist = filter.find((*it)[0]);
                if (exist == filter.end()) { // 没找着，入表！下一个
                        filter.emplace((*it)[0], (*it)[1]);
                        ++it;
                } else { // 找到第一个键，还要确认第二个值
                        auto pt = filter.equal_range((*it)[0]);
                        bool flag = true;
                        for (auto p = pt.first; p != pt.second; ++p)
                        {
                                if (p->first == (*it)[0] && p->second == (*it)[1]) {
                                        flag = false;
                                }
                        }
                        if (flag) {
                                filter.emplace((*it)[0], (*it)[1]);
                                ++it;
                        } else {
                                it = dest.erase(it);
                        }
                }
        }

        return dest;
}

void test(void)
{
        unordered_map<int, int> hashMap;
        hashMap.emplace(1, 1);
        cout << (hashMap.find(1))->first << endl;
        cout << (hashMap.find(1))->second << endl;
//        // 无法加入相同 key
//        hashMap.emplace(10, 2);
//        cout << (hashMap.find(10))->first << endl;
//        cout << (hashMap.find(10))->second << endl;
        // 尝试查找再来修改，可以
        auto it = hashMap.find(1);
        if (it != hashMap.end()) {
                it->second += 1;
        }
        cout << (hashMap.find(1))->first << endl;
        cout << (hashMap.find(1))->second << endl;
        hashMap.erase(1);
        it = hashMap.find(1);
        if (it == hashMap.end()) {
                cout << "key: 1 has been deleted." << endl;
        }

        unordered_multimap<int, int> test;
        test.emplace(1, 1);
        test.emplace(1, 2);
        auto pt = test.equal_range(1);
        for (auto it = pt.first; it != pt.second; ++it)
        {
                cout << it->first << " : " << it->second << endl;
        }

        vector<int> testV = {1, 2, 3, 4, 5};
        auto delit = testV.begin()+1;
        delit = testV.erase(delit);
        cout << "delit : " << *delit << endl;
}

int main(void)
{
        vector<int> src = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
        vector<vector<int>> temp = threeSum1(src);
        cout << "result: " << endl;
        for (auto it = temp.begin(); it != temp.end(); ++it)
        {
                for (auto iit = it->begin(); iit != it->end(); ++iit)
                {
                        cout << (*iit) << ' ';
                }
                cout << endl;
        }

        //test();
        return 0;
}
