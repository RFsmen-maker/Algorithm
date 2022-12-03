/*
 * 72. 编辑距离
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2)
{
        // 1. 定义状态：dp[i][j]，word1 前 i 字符 -> word2 前 j 字符所需最少步数
        int m = word1.size(), n = word2.size();
        int dp[m+1][n+1];

        // 初始化，如果一方为 0，说明把另一个全部删除，操作次数即为长度
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int i = 0; i <= n; ++i) dp[0][i] = i;

        // 2. 转移方程：dp[i][j] =
        // a. word[i] == word[j]：dp[i-1][j-1]
        // b. word[i] != word[j]：三种操作之一：
        //      insert -> dp[i-1, j] 增加一个字符到 word1；delete -> dp[i, j-1] word1 删除一个字符
        //      replace -> dp[i-1, j-1] 直接替换一方
        for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                        dp[i][j] = min({dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1), dp[i-1][j] + 1, dp[i][j-1] + 1});
                }
        }

        return dp[m][n];
}

int main(void)
{
        string word1 = "word1";
        string word2 = "word2";
        cout << minDistance(word1, word2);

        return 0;
}
