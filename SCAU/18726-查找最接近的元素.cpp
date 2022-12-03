/*
 * 18726. 查找最接近的元素
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
        int q;
        cin >> q;

        // 找第一个大于等于给定值的元素下标，二分查找，右第一个，优先扩大右界
        int key, left, right, mid;
        for (int i = 0; i < q; ++i) {
                cin >> key;
                left = -1, right = n;
                while (left + 1 != right) {
                        mid = (left + right) / 2;
                        if (arr[mid] >= key) right = mid;// 中点更大时扩右界
                        else left = mid;
                }
                cout << right + 1 << endl;
        }

        return 0;
}
