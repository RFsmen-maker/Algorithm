/*
 * 52. N 皇后-II
 */
#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> &_map, int row, int pos) {
        for (int i = 0; i < row; ++i) {
                if (_map[i] == pos || _map[i] + row - i == pos || _map[i] - row + i == pos) return false;
        }
        return true;
}

void helper(vector<int> &_map, int len, int row, int &amount) {
        if (row == len) {
                amount++;
                return;
        }
        for (int i = 0; i < len; ++i) {
                _map[row] = i;
                if (check(_map, row, i)) {
                        helper(_map, len, row+1, amount);
                }
        }
}

int totalNQueens(int n) {
        vector<int> _map(n, -1);
        int amount = 0;
        helper(_map, n, 0, amount);
        return amount;
}

int main(void)
{
        cout << totalNQueens(1);

        return 0;
}
