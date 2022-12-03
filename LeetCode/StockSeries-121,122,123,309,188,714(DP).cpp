/*
 * 股票系列问题：121, 122, 123, 309, 188, 714
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 188. 指定交易次数 k
int maxProfit_K(int k, vector<int> &prices)
{

}

// 714. 无限次，加入手续费规则
int maxProfit_Inf(vector<int> &prices, int fee)
{

}

// 309. T+1 交易模式，一天卖了之后无法第二天买，但是买卖次数不限
int maxProfit_Cooldown(vector<int> &prices)
{
        int len = prices.size();
        if (len < 2) return 0;

        // 状态定义：最大收益，是否持有，是否冷却中
        int dp[len][2][2];

        // 初始化
        int ans = INT_MIN;
        dp[0][0][0] = 0; // 第一天啥也没干
        dp[0][1][0] = -prices[0]; // 第一天买入了
        dp[0][0][1] = 0; // 第一天作死买了又卖
        // dp[0][1][1] = INT_MIN; // 不可能第一天买卖了之后又能卖

        for(int i = 1; i < len; ++i)
        {
                // 现在不持有，也不在冷冻期，可能昨天刚卖，也可能早就卖了
                dp[i][0][0] = max(dp[i-1][0][1], dp[i-1][0][0]);
                // 现在在冷冻期，天刚卖
                dp[i][0][1] = dp[i-1][1][0] + prices[i];
                // 现在持有中，可能今天或者更早就买了
                dp[i][1][0] = max(dp[i-1][0][0] - prices[i], dp[i-1][1][0]);
                // 还在冷冻期就买入，不可能
                // dp[i][1][1] =

                // 最后一定是没持有股票才可能赚最多
                ans = max({dp[i][0][0], dp[i][0][1], ans});
        }

        return ans;
}

// 123. 买卖限制两次的最大收益
int maxProfit_TwiceDP(vector<int> &prices)
{
        int len = prices.size();
        if (len < 2) return 0;

        // 定义状态：dp[i, j, k]，第 i+1 天最大收益，是否持有股票，已经交易次数
        int dp[len][2][3];

        // 初始化
        int ans = INT_MIN;
        dp[0][0][0] = 0; // 第一天什么也不做
        dp[0][1][1] = dp[0][1][0] = -prices[0]; // 第一天买入了股票
        dp[0][0][1] = dp[0][0][2] = 0; // 第一天不可能有交易收益

        for (int i = 1; i < len; ++i)
        {
                // 不持有股票
                // 不持有，又没交易过，说明一直没有买股票
                dp[i][0][0] = dp[i-1][0][0];
                // 是早就完成的交易，或者今天刚卖，完成第一次交易
                dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][0] + prices[i]);
                // 交易了两次，早就完成了，或者今天刚卖第二次
                dp[i][0][2] = max(dp[i-1][0][2], dp[i-1][1][1] + prices[i]);
                // 没交易过，又持有股票，买了以后没卖过，今天刚买或者早就买了
                dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][0][0] - prices[i]);
                // 交易了一次，现在还持有，早就买了或者今天刚买
                dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][1] - prices[i]);
                // dp[i][1][2] = INT_MIN; // 由限制条件，不存在这种情况

                ans = max(dp[i][0][1], dp[i][0][2]);
        }
        // 最后一定是不持有股票的时候收益最大，不考虑做空

        return ans;
}

// 122. 买卖无数次的最大收益
// 贪心
int maxProfit_InfGreedy(vector<int>& prices)
{
        int len = prices.size();
        if(len < 2) return 0;

        int sum = 0;

        for(int i = 1; i < len; ++i)
        {
                if(prices[i] > prices[i-1]) sum += (prices[i] - prices[i-1]);
        }

        return sum;
}
// DP
int maxProfit_InfDP(vector<int>& prices)
{
        int len = prices.size();
        if (len < 2) return 0; // 只有一天没收益

        // 状态定义：mp[i, j]：最大收益，i 天数，j 是否持有股票
        int mp[len][2];

        // 初始化
        int res = INT_MIN;
        mp[0][0] = 0; // 没有买入股票
        mp[0][1] = -prices[0]; // 第一天就买入股票
        for (int i = 1; i < len; ++i)
        {
                mp[i][0] = max(mp[i-1][0], mp[i-1][1] + prices[i]); // 当天不持有，不动或者今天刚卖出
                mp[i][1] = max(mp[i-1][1], mp[i-1][0] - prices[i]); // 当天持有，上一天已经持有或今天刚买入

                res = max({mp[i][0], mp[i][0], res});
        }

        return res;
}

// 121. 只买卖一次的最大收益，即求最大差值
int maxProfit_Once(vector<int> &prices)
{
        int len = prices.size();
        if (len < 2) return 0;

        int maxSub, minPri;
        minPri = prices[0];
        maxSub = 0;
        for (int i = 1; i < len; ++i)
        {
                if (prices[i] < minPri) minPri = prices[i];
                maxSub = max(maxSub, prices[i] - minPri);
        }

        return maxSub;
}

int main(void)
{
        vector<int> nums[] = {
                {7, 1, 5, 3, 6, 5},
                {7, 6, 4, 3, 1},
                {3,3,5,0,0,3,1,4},
                {1, 2, 3, 4, 5},
                {7,6,4,3,1},
                {1, 2, 3, 0, 2},
                {1}
        };
        cout << maxProfit_Cooldown(nums[6]) << endl;


        return 0;
}
