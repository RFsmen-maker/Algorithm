/*
* 239. max sliding window
* 最大滑动窗口，返回窗口每个位置的最大值集合数组
* k 为滑动窗口长度
* 注意 k < nums.size()
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

// 解法 3：双端队列，维护左大右小，新元素更大就清空队列
vector<int> maxSlidingWindow3(vector<int>& nums, int k)
{
        if(nums.empty()) return {};

        int len = nums.size();
        vector<int> dest;
        deque<int> window;

        for (int i = 0; i < len; ++i)
        {
                if (i >= k && window.front() <= i - k) window.pop_front();
                // 新元素更大，把前面的清理光
                while (!window.empty() && nums[window.back()] <= nums[i]) window.pop_back();
                window.push_back(i);
                if (i >= k - 1) dest.push_back(nums[window.front()]);
        }

        return dest;
}

// 解法 2：优先队列，暂时没有按照下标删除元素的办法
// 官方解法：使用 container<pair<type, type>> 同时保存下标和值
//  使用 .emplace 成员函数同时存入下标，first 为值，second 为下标
vector<int> maxSlidingWindow2(vector<int>& nums, int k)
{
        int n = nums.size();
        priority_queue<pair<int, int>> window;
        for (int i = 0; i < k; ++i) window.emplace(nums[i], i);

        vector<int> dest = {window.top().first}; // 需要先入第一个答案
        for (int i = k; i < n; ++i) {
            window.emplace(nums[i], i);
            while (window.top().second <= i - k) window.pop();
            dest.push_back(window.top().first);
        }

        return dest;
}


// 解法 1：排序方法，喜闻乐见的超时
vector<int> maxSlidingWindow1(vector<int>& nums, int k)
{
        if(nums.empty()) return {};

        vector<int> dest;
        unsigned int left, right;
        left = 0;
        right = k;
        while(right < nums.size()+1)
        {
                vector<int> window(nums.begin() + left, nums.begin() + right);
                sort(window.begin(), window.end());
                dest.push_back(window[k-1]);
                left++;
                right++;
        }

        return dest;
}

int main(void)
{
        vector<int> nums = {1, 3, 1, 2, 0, 5};
        int k = 3;
        vector<int> temp = maxSlidingWindow2(nums, k);
        for(auto n : temp) cout << n << endl;

        return 0;
}
