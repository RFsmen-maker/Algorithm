/*
 * 98. 验证二叉搜索树
*/

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 不要死缠烂打浪费时间！
// 官方递归方法
bool helper(TreeNode* root, long long lower, long long upper)
{
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
                return false;
        }
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
}
bool isValidBST(TreeNode* root)
{
        return helper(root, LONG_MIN, LONG_MAX);
}


// 中序遍历方法
bool isValidBST1(TreeNode* root)
{

}

//// 递归方法：参考视频
//bool recurBST1(TreeNode * root, int min, int max)
//{
//        if (root == nullptr) return true;
//        if (root->left && root->val <= min) return false;
//        if (root->right && root->val >= max) return false;
//
//        return recurBST1(root->left, min, root->val)
//                && recurBST1(root->right, root->val, max);
//}
//bool isValidBST1(TreeNode* root)
//{
//        return recurBST1(root, root->left->val, root->right->val);
//}

// 递归判断左子树小于根小于右子树
// 要注意一个实例：[5,4,6,null,null,3,7]，根的右子树存在一个左子树比根小
// 这里只判定了局部的 左 < 根 < 右
// 因此需要加入多几个值进行判定，左边取大值，右边取最小值
// 这里采用同时更新最大和最小值，以应对左右转弯的情况
// 这种思路已经化简为繁了，放弃

//
bool recurBST(TreeNode *root, TreeNode *minLeft, TreeNode *maxRight)
{
     if (root == nullptr) return true;
     if (minLeft != nullptr && root->val <= minLeft->val) return false;
     if (maxRight != nullptr && root->val >= maxRight->val) return false;

     return recurBST(root->left, minLeft, root)
        && recurBST(root->right, root, maxRight);
}
bool isValidBST(TreeNode* root)
{
        return recurBST(root, root->left, root->right);
}

// 通过数组构造二叉树
TreeNode *buildBinaryTree(vector<int> &arr)
{
        if (arr.empty()) {
                return nullptr;
        }

        TreeNode* bTree = nullptr;


        return bTree;
}

// 中序遍历二叉树
void midTraverseBinaryTree(TreeNode *root, vector<int> &dest)
{
        if (root == nullptr) {
                dest = {};
                return ;
        }

}

// 清理建好的二叉树
void clearBinaryTree(TreeNode *root)
{
        if (root->left) clearBinaryTree(root->left);
        if (root->right) clearBinaryTree(root->right);
        free(root);
}

int main(void)
{
        vector<int> temp = {2, 1, 3};

        return 0;
}
