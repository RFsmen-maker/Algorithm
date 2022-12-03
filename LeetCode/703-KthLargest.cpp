/*
* 703. KthLargest
* 优先队列问题
* 数据里中第 K 大的元素
* 把遍历到的前 K 个元素放入小头优先队列
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class KthLargest {
private: // 优先队列在 <queue> 内
        priority_queue<int, vector<int>, greater<int>> q; // 使用小顶堆
        unsigned int k;

public:
    KthLargest(int k, vector<int>& nums) {
            this->k = k;
            for (auto& n : nums) {
                    this->add(n);
            }
    }

    int add(int val) {
        this->q.push(val);
        if (this->q.size() > this->k) {
                this->q.pop();
        }
        return q.top();
    }
};

int main(void)
{
         vector<int> nums = {4, 5, 8, 2};

        KthLargest* obj = new KthLargest(3, nums);
        cout << "Add 3, 5, 10, 9, 4 ..." << endl
                << obj->add(3) << endl << obj->add(5) << endl
                << obj->add(10) << endl << obj->add(9) << endl
                << obj->add(4) << endl;

        return 0;
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
