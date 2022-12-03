/*
 * 01 背包问题：N 个物品，按照重量顺序给出价值
 * 再给出一个背包容量，求背包能装的最大的价值量的重量与价值
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Stuff;

// 展示 DP 数组
void showDP(const vector<vector<int>> dp)
{
        int row = dp.size();
        int col = dp[0].size();
        cout << "DP sheet: " << endl;
        for (int i = 0; i < row; ++i)
        {
                for (int j = 0; j < col; ++j)
                {
                        cout << dp[i][j] << ' ';
                }
                cout << endl;
        }
}

// 以前遇到这种问题的思路：计算出所有物品的单位重量价值，排序，从大到小遍历决定拿不拿
// 暴力解法：每种物品只有拿与不拿两种选择，得到一个二叉树的全部可能遍历的暴力解法
// 考虑到存在背包容量限制，因此有及时剪枝比较简单
// 动态规划：有两种解法，二维与一维 DP 数组
// dp[i][j]：元素，价值；i，任意放 0 ~ i 下标的物品；j，剩余容量
// 递推公式：不放物品，dp[i-1][j]；放物品，dp[i-1][j-weight[i]] + value[i]
// 形成最优化数组 dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
Stuff _01Backpack_1(vector<Stuff> stuff, int capacity)
{
        int amount = stuff.size(); // 物品个数

        // 元素，最大价值；i，0 ~ i 物品；j，剩余重量
        vector<vector<int>> dp;
        dp.resize(amount, vector<int>(capacity+1));

        // 初始化
        int weight = stuff[0].first;
        int value = stuff[0].second;
        for (int i = 0; i < amount; ++i) dp[i][0] = 0; // 剩余重量为 0，不放
        for (int i = 1; i <= capacity; ++i) // 尝试放下第一个物品
        {
                if (weight <= i) dp[0][i] = value; // 放得下
                else dp[0][i] = 0; // 放不下
        }

        // 开始递推
        for (int i = 1; i < amount; ++i) // 外物品
        {
                weight = stuff[i].first;
                value = stuff[i].second;
                for (int j = 1; j <= capacity; ++j) // 内背包剩余容量
                {
                        // 放不下
                        if (j < weight) dp[i][j] = dp[i-1][j];
                        // 可能放下，但要选择：
                        // 如果可以放下这个，再看看放下这个后能放的最多的，跟没放这个对比
                        // 放下这个后剩下的空间，不可能是负的因为 j >= weight
                        else dp[i][j] = max(dp[i-1][j], value + dp[i-1][j - weight]);
                }
        }

        showDP(dp);

        return Stuff(0, dp[amount-1][capacity]);
}
// 一维解法：dp[j]：元素，最大价值；j，容量
// 循环次数仍然是一样的，但是空间压缩成了一维
// dp[j] = max(dp[j], d[j - weight[i]] + value[i])
// 先遍历背包时需要倒序，以保证旧值不被修改而使用
Stuff _01Backpack_2(vector<Stuff> stuff, int capacity)
{
        int amount = stuff.size();
        vector<int> dp(capacity+1);

        // 初始化，仍然只管第一个物品
        int weight = stuff[0].first;
        int value = stuff[0].second;
        for (int i = 0; i <= capacity; ++i)
        {
                if (i >= weight) dp[i] = value;
                else dp[i] = 0;
        }

        // test
        for (int i : dp) cout << i << ' ';
        cout << endl;

        // 第一个物品已经过过了
        for (int i = 1; i < amount; ++i)
        {
                weight = stuff[i].first;
                value = stuff[i].second;
                for (int j = 0; j <= capacity; ++j)
                {
                        if (j < weight) dp[j] = dp[j];
                        else dp[j] = max(dp[j], dp[j - weight] + value);
                }
                // test
                for (int j : dp) cout << j << ' ';
                cout << endl;
        }

        return Stuff(0, dp[capacity]);
}

int main(void)
{
        vector<Stuff> stuff = {Stuff(1, 15), Stuff(3, 20), Stuff(4, 30)};
        Stuff res = _01Backpack_2(stuff, 4);
        cout << "take weight : " << res.first << " value : " << res.second << endl;

        return 0;
}

