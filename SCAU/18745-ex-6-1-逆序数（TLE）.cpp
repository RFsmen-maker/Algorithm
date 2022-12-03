/*
 * 18746. 逆序数
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n;
size_t c = 0;

void bubble(vector<int> &arr)
{
        // 冒泡排序：O(n^2)，统计冒泡操作次数，显然会超时
        bool flag;
        for (int i = 0; i < n - 1; ++i) {
                flag = true;
                for (int j = 0; j < n - i - 1; ++j) {
                        if (arr[j] > arr[j+1]) {
                                swap(arr[j], arr[j+1]);
                                c++;
                                flag = false;
                        }
                }
                if (flag) break;
        }
        cout << c;
}

void mapAsTree(vector<int> &arr)
{
        // 从前往后遍历，统计在当前元素之前，比这个元素大的元素的个数
        // 直接使用 map，仍然超时？
        map<int, int> T;
        for (int i = 0; i < n; ++i) {
                auto it = T.find(arr[i]);
                if (it != T.end()) { // 已存在这个数，找到它并增加
                        (*it).second++;
                }
                else { // 没有这个数，插入它
                        T.insert(pair<int, int>(arr[i], 1));
                }
//                cout << "arr : " << arr[i] << endl;
//                cout << "tree : " << endl;
//                for (auto t : T) cout << t.first << ' ' << t.second << endl;
                // 找到前面比这个数大的数的个数，统计起来
                it = T.find(arr[i]);
                it++;
                while (it != T.end()) {
                        c += (*it).second;
                        it++;
                }
                // cout << "c : " << c << endl;
        }
        cout << c;
}

void mergeMethod(vector<int> &arr)
{

}

int main(void)
{
        ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        cin >> n;
        vector<int> arr(n);
        for (int &i : arr) cin >> i;

        bubble(arr); // 冒泡排序，超时
        // mapAsTree(arr); // 红黑树，超时
        // mergeMethod(arr); // 归并排序


        return 0;
}
