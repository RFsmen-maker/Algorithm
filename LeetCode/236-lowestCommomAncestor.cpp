/*
 * 236. 二叉的最近公共祖先
*/
#include <iostream>

using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 存储父结点法，使用哈希表
unordered_map<int, TreeNode*> fa;
unordered_map<int, bool> vis;
void dfs1(TreeNode *root)
{
        if (root->left != nullptr) {
                fa[root->left->val] = root;
                dfs(root->left);
        }
        if (root->right != nullptr) {
                fa[root->right->val] = root;
                dfs(root->right);
        }
}
TreeNode *lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode *q)
{
        fa[root->val] == nullptr;
        dfs(root); // 把所有结点遍历一遍，把他们的父结点存进哈希表
        while (p != nullptr)
        {
                vis[p->val] = true;
                p = fa[p->val];
        }
        while (q != nullptr)
        {
                if (vis[q->val]) return q;
                q = fa[q->val];
        }
        return nullptr;
}

// 参考官方解法的递归
TreeNode *ans;
bool dfs(TreeNode *root, TreeNode* p, TreeNode* q)
{
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        // 左右子树中存在 p 和 q ，或 root 本身是 p 或 q 并且 左子树或右子树有 q 或 p
        if ((lson && rson) || ((root == p || root == q) && (lson || rson))) ans = root;
        return lson || rson || (root == p || root == q);
}
TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q);
{
        dfs(root, p, q);
        return ans;
}

// 参考极客时间，进行递归遍历
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
        // 找到了 p 或者 q 或者到了叶子的情况
        if (root == nullptr || root == p || root == q) return root; // 过滤空树，
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return left == nullptr ? right : right == nullptr ? left : root;
}

int main(void)
{


        return 0;
}
