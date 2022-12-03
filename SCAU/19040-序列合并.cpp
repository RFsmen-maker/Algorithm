/*
 * 19040. 序列合并
 * times : 2
 */
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int n;

// 听过讲解改正，默认输入的两个序列为增序
void priQMethod(vector<int> &arr1, vector<int> &arr2)
{
        priority_queue<int> q; // 默认大顶堆，其会自动维护增序
        for (int i : arr2) q.push(arr1[0] + i); // 初始化，并且以此作为维护的数量限制

        int temp;
        for (int i = 1; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        temp = arr1[i] + arr2[j];
                        if (temp < q.top()) {
                                q.pop();
                                q.push(temp);
                        }
                        else break; // 后面的和只可能更大
                }
        }
        vector<int> arr(n);
        for (int i = n-1; i >= 0; --i) {
                arr[i] = q.top();
                q.pop();
        }
        for (int i : arr) cout << i << ' ';
}

int main(void)
{
        ios::sync_with_stdio(false);
        cin >> n;
        vector<int> arr[2];
        int temp;
        for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < n; ++j) {
                        cin >> temp;
                        arr[i].push_back(temp);
                }
        }

        sort(arr[0].begin(), arr[0].end()); // 主动排序
        sort(arr[1].begin(), arr[1].end());
        priQMethod(arr[0], arr[1]);

        return 0;
}
