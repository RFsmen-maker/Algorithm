/*
 * 1076. K 尾相等数
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void recordMethod(size_t k)
{
        // M 扩出来，N 回头找出来
        vector<int> record(1000, 0);

        // 初始化，先把 K^M 扩到 1000 以上
        size_t n, m = 1;
        while (pow(k, m) < 1000) m++;
        size_t M = static_cast<size_t>(pow(k, m)) % 1000;

        while (1) // 一直下去，直到找到为止
        {
                if (record[M] == 0) {
                        record[M] = m;
                }
                else {
                        n = record[M];
                        break; // 找到了
                }
                M = k * M % 1000;
                m++;
        }
        // cout << "n : " << n << ", m : " << m << endl;
        cout << m + n;
}

// 存在 M > N, K^M >= 1000, K^N >= 1000，末尾三位相等
// 求 M + N 最小值
int main(void)
{
        size_t k; // 1 < K < 999999999
        cin >> k;

        // 使用数组进行记录，每次得到尾数，查找是否已存在在之前计算过的一次中，预计 T = O(m+n)
        recordMethod(k);

        return 0;
}
