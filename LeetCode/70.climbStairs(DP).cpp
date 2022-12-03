/*
 * 70. 爬楼梯
*/
#include <iostream>
#include <vector>

using namespace std;

// 一步一阶或二阶，问上到 n 阶多少种办法
// 思路：最后上到 n 阶的一步只有一阶或二阶两种可能
// 一步一步往前，形成一个二叉树解，但此时出现了很多重复子问题
// dp 数组存子问题解：元素，走上的方法；下标，子问题序号
// 递推公式 dp[i] = dp[i-1] + dp[i-2]
int climbStairs(int n)
{
        // 注意边界特殊条件，否则报 heap overflow
        if (n <= 2) return n;

        vector<int> res(n);
        res[0] = 1; // 初始化，1 阶只有一种可能
        res[1] = 2; // 2 阶两种可能

        for (int i = 2; i < n; ++i)
        {
                res[i] = res[i-1] + res[i-2];
        }

        return res[n-1];
}

int main(void)
{
        int n;
        cin >> n;
        cout << climbStairs(n) << endl;

        return 0;
}

