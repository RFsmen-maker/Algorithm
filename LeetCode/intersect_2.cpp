#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 双指针版本，先排序后遍历
vector<int> intersect2(vector<int>& nums1, vector<int>& nums2)
{
        vector<int> dest;
        int len1 = nums1.size();
        int len2 = nums2.size();

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        // 也可以用迭代器 vector<int> iterator it1 = nums1.begin() ...
        for(int n1 = 0, n2 = 0; n1 < len1 && n2 < len2; )
        {
                if(nums1[n1] == nums2[n2]) {
                        dest.push_back(nums1[n1]);
                        ++n1, ++n2;
                }
                else nums1[n1] < nums2[n2] ? n1++ : n2++;
        }

        return dest;
}

// 哈希表，map 版本
static unordered_map<int, int> conMap(vector<int> &nums)
{
        unordered_map<int, int> tempMap;
        for(auto num : nums)
        {
                auto pItem = tempMap.find(num);
                if(pItem != tempMap.end()) {
                        int temp = (*pItem).second;
                        (*pItem).second = temp + 1;
                }
                else tempMap.insert(pair<int, int>(num, 1));
        }
        return tempMap;
}

vector<int> intersect1(vector<int>& nums1, vector<int>& nums2)
{
        vector<int> dest;

        auto map1 = conMap(nums1);
        auto map2 = conMap(nums2);

        for(auto m1 = map1.begin(); m1 != map1.end(); ++m1)
        {
                auto p = map2.find((*m1).first);
                if(p != map2.end()) {
                        int c1 = (*m1).second;
                        int c2 = (*p).second;
                        for(int i = c1 < c2 ? c1 : c2; i > 0; --i)
                                dest.push_back((*p).first);
                }
        }

        return dest;
}

int main(void)
{
        int test;
        cout << "test piece: ";
        cin >> test;
        vector<int> nums[][2] = {
                {{1, 2, 2, 1}, {2, 2}},
                {{4, 9, 5}, {9, 4, 9, 8, 4}},
                };
        auto temp = intersect2(nums[test][0], nums[test][1]);

        for(auto num : temp) cout << num << endl;

        return 0;
}
