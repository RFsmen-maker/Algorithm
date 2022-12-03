/*
 * 120. 三角形最小路径和
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 简化、优化代码
int minimumTotal(vector<vector<int>>& triangle)
{
        vector<int> mini = triangle[triangle.size() - 1]; // 空间优化，状态压缩
        for ( int i = triangle.size() - 2 ; i >= 0 ; --i ) // 分号、右左括号前后都有空格
                for ( int j = 0 ; i < triangle[i].size() ; ++j ) // 只有一行循环体省略大括号
                        mini[j] = triangle[i][j] + min(mini[j], mini[j+1]); // 中括号中的算式符号左右没有空格
        return mini[0];
}

// 直接动态规划，从底层开始最优化
int minimumTotal_DP(vector<vector<int>>& triangle)
{
        int levels = triangle.size() - 1;

        // 定义状态，从底层开始，到当前层的最小路径
        vector<vector<int>> dp;

        // 初始化
        for (int i = 0; i <= levels; ++i) // 分配空间
        {
                vector<int> temp(i+1);
                dp.push_back(temp);
        }
        for (int i = levels; i >= 0; --i) dp[levels][i] = triangle[levels][i]; // 底层初值填充

        // 开始迭代状态方程：dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + arr
        for (int i = levels - 1; i >= 0; --i)
        {
                for (int j = i; j >= 0; --j)
                {
                        dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
                }
        }

        return dp[0][0];
}

int main(void)
{
        vector<vector<int>> triangle[] = {
                {{2},{3,4},{6,5,7},{4,1,8,3}},
                {{-10}}
                };
        for (auto &i : triangle) cout << minimumTotal(i) << endl;

        return 0;
}

