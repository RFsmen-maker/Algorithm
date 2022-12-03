/*
 * 18714-ex2.5 迷宫问题
 * times : 2
 * 就考虑两种办法：DFS 递归，BFS 队列迭代
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
bool flag = false;

// 偏移：下、右、上、左
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// 另一种回溯方法，一个地图、一个访问记录，参考博客：使用递归的 DFS
void dfs(vector<vector<char>> &_map, vector<vector<bool>> &visit, int x, int y)
{
        if (x == n && y == m) { // 到达目的地
                 flag = true;
                 return;
        }

        for (int i = 0; i < 4; ++i) { // 四个方向各自深入
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (_map[tx][ty] != '1' && visit[tx][ty] == false) {
                        visit[tx][ty] = true;
                        dfs(_map, visit, tx, ty);
                }
        }
}
bool findPath_DFS(vector<vector<char>> &_map, vector<vector<bool>> &visit)
{
        dfs(_map, visit, 1, 1);
        if (flag) return true;
        else return false;
}

// 参考博客，进行偏移，使用队列进行迭代的 BFS
bool findPath_BFS(vector<vector<char>> &_map, vector<vector<bool>> &visit)
{
        queue<pair<int, int>> axi;

        axi.push(pair<int, int>(1, 1));
        while (!axi.empty())
        {
                if (axi.front().first == n && axi.front().second == m) { // 到达目的地
                        flag = true;
                        break;
                }
                for (int i = 0; i < 4; ++i) { // 四个方向走，下、右、上、左
                        int tx = axi.front().first + dx[i], ty = axi.front().second + dy[i];
                        if (_map[tx][ty] != '1' && visit[tx][ty] == false) { // 不是墙且没去过，入队等待遍历
                                visit[tx][ty] = true;
                                axi.push(pair<int, int>(tx, ty));
                        }
                }
                axi.pop();
        }
        return flag;
}

int main(void)
{
        // 构造地图并初始化
        cin >> n >> m;
        vector<vector<char>> _map(n+2);
        vector<vector<bool>> visit(n+2);
        vector<char> empMap(m + 2, '0');
        vector<bool> empVis(m + 2, false);
        for (auto &it : _map) it = empMap;
        for (auto &it : visit) it = empVis;
        for (int i = 0; i < n+2; ++i) _map[i][0] = '1', _map[i][m+1] = '1'; // 左右墙
        for (int i = 0; i < m+2; ++i) _map[0][i] = _map[n+1][i] = '1'; // 上下墙
        for (int i = 1; i < n+1; ++i) for (int j = 1; j < m+1; ++j) cin >> _map[i][j]; // 读入地图

        if(findPath_DFS(_map, visit)) cout << "yes" << endl;
        else cout << "no" << endl;

        return 0;
}
