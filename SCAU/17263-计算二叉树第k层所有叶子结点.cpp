/*
 * 17263. 计算二叉树的第 k 层中所有叶子结点个数
 */
#include <iostream>
#include <vector>

using namespace std;

typedef struct BiTNode {
        char data;
        BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void CreateBiTree(BiTree &T) // 快速中序递归建树，注意要传入引用
{
        char ch;
        ch = getchar();
        if (ch == '#') {
                T = nullptr;
                return;
        }

        T = new BiTNode{ch, nullptr, nullptr};
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
}

void dfs(BiTree T, int cur, int k, int &amount) {
        if (cur == k) {
                if (T->lchild == nullptr && T->rchild == nullptr) amount++;
                return;
        }

        if (T->lchild != nullptr) dfs(T->lchild, cur+1, k, amount);
        if (T->rchild != nullptr) dfs(T->rchild, cur+1, k, amount);
}

int main(void)
{
        BiTree T;
        CreateBiTree(T);
        int k;
        cin >> k;

        int amount = 0;
        dfs(T, 1, k, amount);
        cout << amount;

        return 0;
}
