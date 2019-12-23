/*
 * @lc app=leetcode id=272 lang=cpp
 *
 * [272] Closest Binary Search Tree Value II
 *
 * https://leetcode.com/problems/closest-binary-search-tree-value-ii/description/
 *
 * algorithms
 * Hard (47.74%)
 * Likes:    481
 * Dislikes: 17
 * Total Accepted:    47K
 * Total Submissions: 98.1K
 * Testcase Example:  '[4,2,5,1,3]\n3.714286\n2'
 *
 * Given a non-empty binary search tree and a target value, find k values in
 * the BST that are closest to the target.
 *
 * Note:
 *
 *
 * Given target value is a floating point.
 * You may assume k is always valid, that is: k ≤ total nodes.
 * You are guaranteed to have only one unique set of k values in the BST that
 * are closest to the target.
 *
 *
 * Example:
 *
 *
 * Input: root = [4,2,5,1,3], target = 3.714286, and k = 2
 *
 * ⁠   4
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \
 * 1   3
 *
 * Output: [4,3]
 *
 * Follow up:
 * Assume that the BST is balanced, could you solve it in less than O(n)
 * runtime (where n = total nodes)?
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
    map<double, int> mp;

public:
    vector<int> closestKValues(TreeNode *root, double target, int k)
    {
        helper(root, target, k);
        vector<int> ans;
        for (auto it = mp.begin(); it != mp.end(); it++)
            ans.push_back(it->second);
        return ans;
    }
    void helper(TreeNode *root, double target, int k)
    {
        if (!root)
            return;
        if (mp.size() < k)
            mp[abs(root->val - target)] = root->val;
        else if (mp.lower_bound(abs(root->val - target)) != mp.end())
        {
            auto it = mp.end();
            it--;
            cout << it->first << it->second << endl;
            mp.erase(it);
            mp[abs(root->val - target)] = root->val;
        }
        if (mp.size() < k)
        {
            helper(root->left, target, k);
            helper(root->right, target, k);
        }
        else
            root->val > target ? helper(root->left, target, k) : helper(root->right, target, k);
    }
};
// @lc code=end
