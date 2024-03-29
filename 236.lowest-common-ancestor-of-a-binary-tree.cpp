/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (41.18%)
 * Likes:    2621
 * Dislikes: 150
 * Total Accepted:    360.5K
 * Total Submissions: 873.5K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 *
 * Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
 * of itself according to the LCA definition.
 *
 *
 *
 *
 * Note:
 *
 *
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the binary tree.
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return nullptr;
        TreeNode *left{lowestCommonAncestor(root->left, p, q)};
        TreeNode *right{lowestCommonAncestor(root->right, p, q)};
        if (left && right)
            return root;
        if (root == p || root == q)
            return root;
        if (left)
            return left;
        if (right)
            return right;
        return nullptr;
    }
};
// @lc code=end

// class Solution
// {
//     TreeNode *ans{nullptr};

// public:
//     TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
//     {
//         rec(root, p, q);
//         return ans;
//     }
//     pair<bool, bool> rec(TreeNode *node, TreeNode *p, TreeNode *q)
//     {
//         if (!node)
//             return make_pair(false, false);
//         auto l = rec(node->left, p, q);
//         auto r = rec(node->right, p, q);
//         bool pe{l.first || r.first}, qe{l.second || r.second};
//         if (pe || node == p)
//             pe = true;
//         if (qe || node == q)
//             qe = true;
//         if (!ans && pe && qe)
//             ans = node;
//         return make_pair(pe, qe);
//     }
// };
