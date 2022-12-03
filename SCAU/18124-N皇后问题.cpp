/*
 * 18124. N 皇后问题
 * 22 模拟考第十题
 */
#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> &_map, int curRow, int pos) {
        for (int i = 0; i < curRow; ++i) { // 测试第一行到当前行的上一行的各个点
                if (_map[i] == pos || _map[i] + (curRow - i) == pos || _map[i] - (curRow - i) == pos) return false;
        }
        return true;
}
void szQueen(vector<int> &_map, int sz, int curRow, int &amount) { //
        if (curRow == sz) { // 找到一个合法的放法
                amount++;
                return;
        }
        for (int i = 0; i < sz; ++i) {
                if (check(_map, curRow, i)) { // 测试一行中的某个放置位置是否合法
                        _map[curRow] = i;
                        szQueen(_map, sz, curRow + 1, amount); // 当前点通过测试立即看下一行
                }
        }
}
void countValid(int sz, int &amount) // 计算 N * N 的棋盘上，N 个皇后的正确放法数
{
        for (int i = 0; i < sz; ++i) { // 指定第一行的每个位置放置皇后作为初始值
                vector<int> _map(sz, -1);
                _map[0] = i; // 指定第一行放置位置
                szQueen(_map, sz, 1, amount);
        }
}
// N 皇后问题，输入 n 个测例，计算放法
int main(void)
{
        int n;
        cin >> n;
        vector<int> res(14, -1);
        int sz, amount;
        for (int i = 0; i < n; ++i) {
                cin >> sz;
                amount = 0;
                if (res[sz] == -1) {
                        countValid(sz, amount);
                        res[sz] = amount;
                }
                cout << res[sz] << endl;
        }

        return 0;
}
