/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (39.28%)
 * Likes:    1263
 * Dislikes: 399
 * Total Accepted:    379.2K
 * Total Submissions: 965.3K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given the below binary tree and sum = 22,
 *
 *
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \      \
 * 7    2      1
 *
 *
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool helper(TreeNode *node, int v)
    {
        if (!node)
            return false;
        int nv{v - node->val}; // nv = new_value
        if (nv == 0 && !node->right && !node->left)
            return true;
        if (helper(node->left, nv))
            return true;
        if (helper(node->right, nv))
            return true;
        return false;
    }
    bool hasPathSum(TreeNode *root, int sum)
    {
        return helper(root, sum);
    }
};
// @lc code=end
