/*
 * 18710. 统计不同数字的个数二
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
        int n;
        cin >> n;

        // 自定义小数组哈希表
        vector<bool> table(200001, false);
        int temp, count = 0;
        for (int i = 0; i < n; ++i) {
                cin >> temp;
                if (!table[temp]) {
                        table[temp] = true;
                        count++;
                }
        }

        cout << count;


        return 0;
}

