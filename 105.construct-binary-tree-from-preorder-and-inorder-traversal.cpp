/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (44.45%)
 * Likes:    2315
 * Dislikes: 62
 * Total Accepted:    280K
 * Total Submissions: 628.6K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int idx{};
        return rec(preorder, inorder, idx, 0, preorder.size());
    }
    TreeNode *rec(vector<int> &preorder, vector<int> &inorder, int &idx, int st, int ed)
    {
        if (st == ed)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[idx]);
        for (int i = st; i < ed; i++)
        {
            if (inorder[i] == preorder[idx])
            {
                idx++;
                root->left = rec(preorder, inorder, idx, st, i);
                root->right = rec(preorder, inorder, idx, i + 1, ed);
                break;
            }
        }
        return root;
    }
};
// @lc code=end
