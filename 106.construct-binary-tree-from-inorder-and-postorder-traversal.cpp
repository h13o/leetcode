/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (42.06%)
 * Likes:    1135
 * Dislikes: 25
 * Total Accepted:    180.8K
 * Total Submissions: 429.2K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 *
 * Return the following binary tree:
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int idx = postorder.size() - 1;
        return rec(inorder, postorder, idx, 0, postorder.size());
    }
    TreeNode *rec(vector<int> &inorder, vector<int> &postorder, int &idx, int is, int ie)
    {
        if (ie - is == 0)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[idx--]);
        if (ie - is == 1)
            return root;
        for (int i = is; i < ie; i++)
        {
            if (root->val == inorder[i])
            {
                root->right = rec(inorder, postorder, idx, i + 1, ie);
                root->left = rec(inorder, postorder, idx, is, i);
            }
        }
        return root;
    }
};
// @lc code=end
