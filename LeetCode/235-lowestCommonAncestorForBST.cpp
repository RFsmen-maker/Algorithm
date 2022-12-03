/*
 * 235. 二叉搜索树的最近公共祖先
*/
#include <iostream>

using namespace std;

// 参照评论区，结合二叉搜索树特性的递归版本，
// 是最快的办法，因为没有递归遍历所有结点，而且一旦找到目标就截停递归栈加深
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
        if (root->val == p->val) return p;
        if (root->val == q->val) return q;
        if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        else if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        else return root;
}

// 参照官方解法2
// 目标的结点必定是 p < root < q 或 q < root < p，一旦找到符合这个条件的，直接返回它
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
        auto cur = root;
        while (true)
        {
                if (cur->val < p->val && cur->val < q->val) cur = cur->right;
                else if (cur->val > p->val && cur->val > q->val) cur = cur->left;
                else return cur;
        }
}

// 参照官方解法1
// 利用二叉搜索树的性质，目标比根小，在左边，目标比根大，在右边
// 因此分两次找，把找的路径存起来，再拿回来对比出路径中最后一个相同的
// 存储的路径一定有根节点，因此一定有相同的
vector<TreeNode *> findNode(TreeNode* root, TreeNode* dest)
{
        auto cur = root;
        vector<TreeNode *> path;
        path.push_back(cur);
        while (cur != dest)
        {
                if (cur->val < dest->val) {
                        cur = cur->right;
                } else {
                        cur = cur->left;
                }
                path.push_back(cur);
        }
        return path;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
        if (p == nullptr || q == nullptr) return nullptr;
        vector<TreeNode *> pPath = findNode(root, p);
        vector<TreeNode *> qPath = findNode(root, q);
        TreeNode *destNode = nullptr;
        for (auto pit = pPath.begin(), qit = qPath.begin()
             ; pit != pPath.end() && qit != qPath.end(); pit++, qit++)
        {
                if ((*pit) == (*qit)) {
                        destNode = (*pit);
                }
        }
        return destNode;
}

// 与一般的二叉树同办法
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
        // 先考虑边界情况，同时加入目标条件
        if (root == nullptr || root == q || root = p) return root;
        // 分支
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 向上层提供数据
        return left == nullptr ? right : right == nullptr ? left : root;
}

