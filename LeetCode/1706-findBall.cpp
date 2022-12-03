/*
 * 1706. 球会落何处
*/

#include <iostream>
#include <vector>

using namespace std;

// 官方解法：更短更精悍
vector<int> _findBall(vector<vector<int>>& grid)
{
        int n = grid[0].size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
                int col = i; // 球初始列
                for (auto &row : grid) {
                        int dir = row[col];
                        col += dir; // 移动球
                        if (col < 0 || col == n || row[col] != dir) { // 到达侧边或 \/
                                col = -1;
                                break;
                        }
                }
                ans[j] = col;
        }
        return ans;
}

vector<int> findBall(vector<vector<int>>& grid)
{
        vector<int> res;
        const int depth = grid.size();
        const int leftWall = -1;
        const int rightWall = grid[0].size();
        int x, y; // 当前所在位置，x 列下标，y 行下标
        for (int i = 0; i < rightWall; ++i) // 从每列顶上开始放球
        {
                x = i;
                y = 0; // 所在层数
                // m x n 网格，1 : 向右 \, -1 : 向左 /
                // 卡住：\/, \|, |/；通过：y == depth
                while (y < depth)
                {
                        if (grid[y][x] == 1) { // 导向右边
                                if (x + 1 < rightWall && grid[y][x+1] == 1) {
                                        y++;
                                        x++;
                                        continue;
                                } else {
                                        break;
                                }
                        } else { // 导向左边
                                if (x - 1 > leftWall && grid[y][x-1] == -1) {
                                        y++;
                                        x--;
                                        continue;
                                } else {
                                        break;
                                }
                        }
                }
                if (y >= depth) {
                        res.push_back(x);
                } else {
                        res.push_back(-1);
                }
        }

        return res;
}

int main(void)
{
        vector<vector<int>> grid = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
        vector<int> temp = findBall(grid);
        for (int i : temp) cout << i << endl;

        return 0;
}
