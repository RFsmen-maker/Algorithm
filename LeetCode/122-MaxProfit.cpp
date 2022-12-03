#include <iostream>
#include <vector>

using namespace std;

// DP：转股票系列

// 贪心算法
int maxProfit_Greedy(vector<int>& prices) {
        if(prices.empty() || prices.size() < 2) return 0;

        int cur = 0, sum = 0;

        for(int i = 1; i < prices.size(); ++i)
        {
                if(prices[i] > prices[i-1]) sum += (prices[i] - prices[i-1]);
        }

        return sum;
}

int main(void)
{
        vector<int> arr = {7, 1, 5, 3, 6, 4};
        cout << maxProfit_Greedy(arr);

        return 0;
}
