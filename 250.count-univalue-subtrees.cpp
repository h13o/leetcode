/*
 * @lc app=leetcode id=250 lang=cpp
 *
 * [250] Count Univalue Subtrees
 *
 * https://leetcode.com/problems/count-univalue-subtrees/description/
 *
 * algorithms
 * Medium (50.66%)
 * Likes:    382
 * Dislikes: 89
 * Total Accepted:    50K
 * Total Submissions: 98.7K
 * Testcase Example:  '[5,1,5,5,5,null,5]'
 *
 * Given a binary tree, count the number of uni-value subtrees.
 *
 * A Uni-value subtree means all nodes of the subtree have the same value.
 *
 * Example :
 *
 *
 * Input:  root = [5,1,5,5,5,null,5]
 *
 * ⁠             5
 * ⁠            / \
 * ⁠           1   5
 * ⁠          / \   \
 * ⁠         5   5   5
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
    bool rec(TreeNode *node, int &count)
    {
        if (!node)
            return true;
        bool l = rec(node->left, count);
        bool r = rec(node->right, count);
        if (!l || !r)
            return false;
        if ((!node->right || node->right->val == node->val) && (!node->left || node->left->val == node->val))
        {
            count++;
            return true;
        }
        return false;
    }
    int countUnivalSubtrees(TreeNode *root)
    {
        int count{};
        rec(root, count);
        return count;
    }
};
// @lc code=end
