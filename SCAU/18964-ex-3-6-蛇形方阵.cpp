/*
 * 18964. 蛇形方阵
 */
#include <iostream>
#include <vector>

using namespace std;

// 模拟出墙、当前前进方向，随时分支选择
int main(void)
{
        int n;
        cin >> n;
        vector<int> emp(n, 0);
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) arr.push_back(emp);

        const int fin = n * n;
        const int dir[4][2] = {{0, +1}, {+1, 0}, {0, -1}, {-1, 0}}; // 右、下、左、上
        const int RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3;

        int wall[4] = {n-1, n-1, 0, 0};
        int cur = 1, row = 0, col = 0, go = 0;
        arr[0][0] = 1;
        while (cur != fin) {
                cur++;
                row += dir[go][0], col += dir[go][1];
                arr[row][col] = cur;
                if (go == RIGHT && col == wall[RIGHT]) {
                        go = DOWN, wall[UP]++;
                }
                else if (go == DOWN && row == wall[DOWN]) {
                        go = LEFT, wall[RIGHT]--;
                }
                else if (go == LEFT && col == wall[LEFT]) {
                        go = UP, wall[DOWN]--;
                }
                else if (go == UP && row == wall[UP]) { // go == UP && row == wall[UP]
                        go = RIGHT, wall[LEFT]++;
                }
        }

        for (auto it : arr) {
                for (int i : it) printf("%3d", i);
                cout << endl;
        }

        return 0;
}
