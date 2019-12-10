/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (51.13%)
 * Likes:    1995
 * Dislikes: 55
 * Total Accepted:    473K
 * Total Submissions: 925K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 *
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 *
 * return its level order traversal as:
 *
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<pair<TreeNode *, int>> node_queue;
        if (!root)
            return ans;
        node_queue.push(make_pair(root, 0));
        while (!node_queue.empty())
        {
            pair<TreeNode *, int> node_pair{node_queue.front()};
            node_queue.pop();
            if (node_pair.second == ans.size())
                ans.push_back(vector<int>());
            ans[node_pair.second].push_back(node_pair.first->val);
            if (node_pair.first->left)
                node_queue.push(make_pair(node_pair.first->left, node_pair.second + 1));
            if (node_pair.first->right)
                node_queue.push(make_pair(node_pair.first->right, node_pair.second + 1));
        }
        return ans;
    }
};
// @lc code=end
