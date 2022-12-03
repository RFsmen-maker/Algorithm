/*
 * 19081. 树上摘樱桃
 */
#include <iostream>
#include <vector>

using namespace std;

int m, n; // 结点、边数

struct Node {
        int left, right;
};

int dfs(vector<Node> T, int cur, int &amount) {
        if (T[cur].left == 0 && T[cur].right == 0) return 1; // 没有左右子树，即最低层叶子

        if (T[cur].left == 0 && T[cur].right != 0) {
                dfs(T, T[cur].right, amount); // 只有右子树
                return 0;
        }
        else if (T[cur].left != 0 && T[cur].right == 0) {
                dfs(T, T[cur].left, amount); // 只有左子树
                return 0;
        }
        else { // 左右子树都有
                        int judge = dfs(T, T[cur].left, amount) + dfs(T, T[cur].right, amount); // 左右结点都是叶子
                        if (judge == 2) amount++;
                        return 0;
        }
}

int main(void)
{
        cin >> m >> n;
        vector<Node> T(m+1, {0, 0}); // 数组快速建树，注意要偏移
        string dump;
        int x, y; // 根、孩子
        for (int i = 0; i < n; ++i) {
                cin >> x >> dump >> y;
                if (T[x].left == 0) T[x].left = y;
                else T[x].right = y;
        }

        int amount = 0;
        dfs(T, 1, amount); // 注意别弄错第一层

        cout << amount;

        return 0;
}

