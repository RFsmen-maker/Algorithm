/*
 * 322. 零钱兑换
 */
#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int>& coins, int amount)
{
        // 1. 定义状态：dp[i]，凑到 i 块钱的最少硬币个数
        vector<int> dp(amount + 1, amount+1);

        // 初始化
        dp[0] = 0; // 不用凑钱

        // 2. 最后一个刚好凑成的选项只有这么几个 coin，转移方程：dp[i] = min{dp[i - coins[j]]} + 1;
        int len = coins.size();
        for (int i = 1; i <= amount; ++i) {
                for (int j = 0; j < len; ++j) {
                        if (coins[j] <= i) {
                                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                        }
                }
        }

        // 最终要求的就是 dp[amount]，如果值仍然是 amount+1，说明凑不成
        return dp[amount] == (amount + 1) ? -1 : dp[amount];
}

int main(void)
{
        vector<int> coins = {1, 2, 5};
        cout << coinChange(coins, 11);

        return 0;
}
