/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (45.05%)
 * Likes:    2920
 * Dislikes: 66
 * Total Accepted:    505.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 *
 *
 *
 *
 * But the following [1,2,2,null,3,null,3] is not:
 *
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 *
 *
 *
 *
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        queue<pair<TreeNode *, TreeNode *>> q; //queue
        q.push(make_pair(root->left, root->right));
        while (!q.empty())
        {
            auto qf = q.front();
            q.pop();
            if (!qf.first && !qf.second)
                continue;
            if (!qf.first || !qf.second || qf.first->val != qf.second->val)
                return false;
            q.push(make_pair(qf.first->left, qf.second->right));
            q.push(make_pair(qf.first->right, qf.second->left));
        }
        return true;
    }
};
// @lc code=end

// Dec 8th , 2019
// class Solution
// {
// public:
//     bool helper(TreeNode *r1, TreeNode *r2)
//     {
//         if (!r1 && !r2)
//             return true;
//         if (!r1 || !r2)
//             return false;
//         if (r1->val != r2->val)
//             return false;
//         if (helper(r1->left, r2->right) && helper(r1->right, r2->left))
//             return true;
//         return false;
//     }
//     bool isSymmetric(TreeNode *root)
//     {
//         if (!root)
//             return true;
//         return helper(root->left, root->right);
//     }
// };
// Dec 6th, 2019 Passed
// class Solution
// {
//     vector<vector<int>> data;

// public:
//     void helper(TreeNode *root, int level)
//     {
//         if (level == data.size())
//             data.push_back(vector<int>());
//         if (root)
//             data[level].push_back(root->val);
//         else
//         {
//             data[level].push_back(INT_MIN);
//             return;
//         }
//         helper(root->left, level + 1);
//         helper(root->right, level + 1);
//     }
//     bool isSymmetric(TreeNode *root)
//     {
//         helper(root, 0);
//         for (auto layer : data)
//         {
//             int l{0}, r{layer.size() - 1};
//             while (l < r)
//             {
//                 if (layer[l++] != layer[r--])
//                     return false;
//             }
//         }
//         return true;
//     }
// };
