// 18054 输出不同的数

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void treeMethod(vector<int> &arr)
{
        vector<int> res;
        set<int> tree; // 通过红黑树记录出现过的数字
        for (int i = 0; i < 10; ++i)
        {
                if (tree.find(arr[i]) == tree.end()) {
                        res.push_back(arr[i]); // 没出现过的进入数组
                        tree.insert(arr[i]); // 并且记录
                }
        }
        for (int i : res) cout << i << endl;
}

void hashMethod(vector<int> &arr)
{
        // 直接使用一个大数组记录是否已经存在
        const long long offset = 50000; // 防止出现负数元素的情况
        vector<bool> table(100000, false);
        vector<int> res;
        for (int i = 0; i < 10; ++i) {
                if (!table[arr[i] + offset]) {
                        table[arr[i] + offset] = true;
                        res.push_back(arr[i]);
                }
        }
        for (int i : res) cout << i << endl;
}

int main(void)
{
        // 指定了是 10 个整数
        vector<int> arr(10);
        for (int &i : arr) cin >> i;

        // treeMethod(arr); // 红黑树容器
        hashMethod(arr); // 数组作哈希表

        return 0;
}

