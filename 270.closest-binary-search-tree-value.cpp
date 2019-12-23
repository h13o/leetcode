/*
 * @lc app=leetcode id=270 lang=cpp
 *
 * [270] Closest Binary Search Tree Value
 *
 * https://leetcode.com/problems/closest-binary-search-tree-value/description/
 *
 * algorithms
 * Easy (45.48%)
 * Likes:    529
 * Dislikes: 38
 * Total Accepted:    106.1K
 * Total Submissions: 232.6K
 * Testcase Example:  '[4,2,5,1,3]\n3.714286'
 *
 * Given a non-empty binary search tree and a target value, find the value in
 * the BST that is closest to the target.
 *
 * Note:
 *
 *
 * Given target value is a floating point.
 * You are guaranteed to have only one unique value in the BST that is closest
 * to the target.
 *
 *
 * Example:
 *
 *
 * Input: root = [4,2,5,1,3], target = 3.714286
 *
 * ⁠   4
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \
 * 1   3
 *
 * Output: 4
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
    int closestValue(TreeNode *root, double target)
    {
        int ans{root->val};
        while (root)
        {
            if (abs(ans - target) > abs(root->val - target))
                ans = root->val;
            if (root->val < target)
                root = root->right;
            else if (root->val == target)
                return ans;
            else
                root = root->left;
        }
        return ans;
    }
};
// @lc code=end
