/*
 * ex2.8 递归实现全排列
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permute_BFS(void);

// 还需要一个从根节点到任意结点的列表存每一个序列
// 递归里通过循环产生分支
// 需要知道第几层，已经选了哪些数，使用表查，以空间换时间
// 状态：每一个结点表示了求解问题的不同阶段
// 回溯的过程称为状态重置
// 两种思路，DFS 与 BFS
void permute_DFS(vector<vector<int>> &res, vector<int> &nums, int len, int cur, vector<int> seCase, vector<bool> visited) {
        if (cur == len) {
                res.push_back(seCase);
                return; // 取得一个完整序列
        }

        for (int i = 0; i < len; ++i)
        {
                if (visited[i]) {
                        continue;
                }
                seCase.push_back(nums[i]);
                visited[i] = true;
                permute_DFS(res, nums, len, cur+1, seCase, visited);
                visited[i] = false;
                seCase.pop_back(); // 之前做了什么要补回来再去其他分支
        }
}
vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        int len = nums.size();
        vector<int> seCase;
        vector<bool> visited(len, false);
        permute_DFS(res, nums, len, 0, seCase, visited);

        return res;
}

// 没有思路，去 leetcode 看看先
int main(void)
{
        vector<int> nums = {1, 2, 3, 4};
        auto res = permute(nums);
        for (auto &i : res) {
                for (auto &j : i) {
                        cout << j << ' ';
                }
                cout << endl;
        }

        return 0;
}

