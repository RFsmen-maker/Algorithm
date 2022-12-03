/*
 * 二叉树通用问题集：102, 104, 111
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cmath>

#define null 0

using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 102. 迭代遍历二叉树，问题在于：怎么判断第几层？
// T = O(n), S = (n)
// 使用两个队列进行交换吞吐，官方解：使用分界结点 dummyNode S(n) 更小
vector<vector<int>> levelOrder_BFS(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> res;
        queue<TreeNode*> q[2]; // 两个队列互相交换地用，每次到交换，说明进入下一层
        int exchange = 0;
        auto cur = root;
        q[0].push(cur);
        while (!q[0].empty() || !q[1].empty())
        {
                vector<int> curStage;

                while (!q[exchange].empty())
                {
                        cur = q[exchange].front();
                        curStage.push_back(cur->val);

                        if (cur->left != nullptr) q[abs(1 - exchange)].push(cur->left);
                        if (cur->right != nullptr) q[abs(1 - exchange)].push(cur->right);

                        q[exchange].pop();
                }

                exchange = abs(1 - exchange);
                res.push_back(curStage);
        }

        return res;
}
// 尝试递归解法，即 DFS，需要使用另外一个函数
void helper(vector<vector<int>> &res, TreeNode* T, int level) {
        if (T == nullptr) return ;

        if (level == static_cast<int>(res.size())) {
                vector<int> temp;
                res.push_back(temp);
        }

        res[level].push_back(T->val);
        helper(res, T->left, level + 1);
        helper(res, T->right, level + 1);
}
vector<vector<int>> levelOrder_DFS(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> res;

        helper(res, root, 0);

        return res;
}

// 先序遍历：用于测试
void rootFirstTraverse(TreeNode *T)
{
        if (T == nullptr) return;
        else cout << T->val << endl;
        rootFirstTraverse(T->left);
        rootFirstTraverse(T->right);
}

// 建树
void BuildTree(TreeNode **T, vector<int> input, int lev)
{
        int len = input.size();
        if (lev <= len && input[lev-1] != null) {
                *T = (TreeNode*)malloc(sizeof(TreeNode));
        } else {
                *T = nullptr;
                return ;
        }

        // 构建测试检验
        // cout << "input[" << lev-1 << "] = " << input[lev-1] << endl;
        (*T)->val = input[lev - 1];
        BuildTree(&(*T)->left, input, lev * 2);
        BuildTree(&(*T)->right, input, lev * 2 + 1);
}

// 104. 二叉树的最大深度，循环迭代版，类似层次遍历，借用队列，使用 dummy 结点
int maxDepth(TreeNode *root)
{
        if (root == nullptr) return 0;

        int count = 0;
        queue<TreeNode *> q;
        TreeNode *dummy = new TreeNode(-1); // 分隔点
        TreeNode *cur;

        q.push(root);
        q.push(dummy);
        cur = root;
        while (!q.empty() && q.front() != dummy)
        {
                cur = q.front();
                while (cur != dummy)
                {
                        if (cur->left != nullptr) q.push(cur->left);
                        if (cur->right != nullptr) q.push(cur->right);
                        q.pop();
                        cur = q.front();
                }
                q.push(dummy);
                q.pop();
                count++;
        }
        delete dummy;

        return count;
}

// 111. 二叉树的最小深度，递归 DFS
int minDepth(TreeNode *root)
{
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1; // 叶子
        if (root->left && root->right) return min(minDepth(root->left) + 1, minDepth(root->right) + 1); // 两边都有
        auto &remain = root->left ? root->left : root->right; // 只管一边
        return minDepth(remain) + 1;
}

int main(void)
{
        vector<int> input = {3, 9, 20, null, null, 15, 7};

        // 建二叉树
        TreeNode *T = nullptr;
        BuildTree(&T, input, 1);

        // 先根遍历测试二叉树
        // rootFirstTraverse(T);

        // 层次遍历
        vector<vector<int>> output = levelOrder_DFS(T);

        // 输出测试
        for (vector<int> lev : output)
        {
                int len = lev.size();
                for (int i =0; i < len; ++i)
                {
                        cout << lev[i] << ' ';
                }
                cout << endl;
        }

        return 0;
}
