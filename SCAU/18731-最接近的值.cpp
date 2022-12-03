/*
 * 18731. 最接近的值
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(void)
{
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int &i : arr) cin >> i;

        vector<int> res;
        res.push_back(arr[0]); // 第一个数的接近值为它自身
        set<int> T;
        T.insert(arr[0]);

        // 红黑树动态维护一个增序序列
        for (int i = 1; i < n; ++i) {
                auto it = T.find(arr[i]);
                if (it == T.end()) {
                        T.insert(arr[i]);
                        it = T.find(arr[i]);
                        if (it == T.begin()) res.push_back(*(++it)); // 这个数插入后在头，最接近数肯定是下一个
                        else {
                                auto tempIt = it;
                                tempIt++;
                                if (tempIt == T.end()) res.push_back(*(--it)); // 这个数插入后在最后，最接近数肯定是上一个
                                else { // 这个数插入后不在头尾，需要比较前后两个数
                                        it--;
                                        int left = abs(*it - arr[i]), right = abs(*tempIt - arr[i]);
                                        if (left < right) res.push_back(*it);
                                        else res.push_back(*tempIt);
                                }
                        }
                }
                else res.push_back(arr[i]); // 左边找到了这个数
        }
        for (int i : res) cout << i << ' ';
        cout << endl;

        return 0;
}
