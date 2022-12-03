/*
 * 18770-ex 1.5 差值最大
 * 一个长度为N的整数序列，找出两个数x和y使x-y的值最大。
 * 要求在序列中x必须在y的右侧。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int &i : arr) cin >> i;

        // 双指针法，left 停留在最小处，right 一直右移，刷新差值
        int sub = 0, left = 0, right = 1;
        while (right < n) {
                sub = max(sub, arr[right] - arr[left]);
                if (arr[right] < arr[left]) left = right;
                right++;
        }
        cout << sub;

        return 0;
}

int try1(void)
{
        int n;
        cin >> n;
        if (n <= 1) {
                cout << 0;
                return 0;
        }

        vector<int> arr(n);
        for (int &i : arr) cin >> i;

        int x, y, max;
        x = 1;
        y = 0; // 即 minIndex
        max = arr[x] - arr[y];
        for (int i = 1; i < n; ++i)
        {
                int temp = arr[i] - arr[y];
                if (temp > max) max = temp;
                if (arr[i] < arr[y]) y = i;
        }
        cout << max;

        return 0;
}
