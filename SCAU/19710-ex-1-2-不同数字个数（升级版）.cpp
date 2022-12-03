/*
 * 19710-ex 1.2 统计不同数字的个数
 * times : 2
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n; // 0 <= n <= 20000

// 数组作哈希表，T = O(n)
void hashMethod(void)
{
        vector<bool> flag(200001, true); // 输入数据 0 <= ai <= 200000

        int temp, count = 0;
        for (int i = 0; i < n; ++i) {
                cin >> temp;
                if (flag[temp]) {
                        flag[temp] = false;
                        count++;
                }
        }
        cout << count;
}

// 直接用树秒杀，但是其实 T = O(nlogn)，做了多余的排序
void treeMethod(void)
{
        set<int> myTree;
        int temp;
        for (auto i = 0; i < n; ++i)
        {
                cin >> temp;
                myTree.insert(temp);
        }
        cout << myTree.size();
}

int main(void)
{
        cin >> n;
        hashMethod();

        return 0;
}
