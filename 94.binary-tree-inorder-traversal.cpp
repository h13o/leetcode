/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (59.67%)
 * Likes:    2190
 * Dislikes: 96
 * Total Accepted:    577.6K
 * Total Submissions: 967.9K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * Output: [1,3,2]
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> v;

public:
    void helper(TreeNode *root)
    {
        if (!root)
            return;
        helper(root->left);
        v.push_back(root->val);
        helper(root->right);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        helper(root);
        return v;
    }
};
// @lc code=end
