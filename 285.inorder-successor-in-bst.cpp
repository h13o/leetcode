/*
 * @lc app=leetcode id=285 lang=cpp
 *
 * [285] Inorder Successor in BST
 *
 * https://leetcode.com/problems/inorder-successor-in-bst/description/
 *
 * algorithms
 * Medium (37.27%)
 * Likes:    883
 * Dislikes: 55
 * Total Accepted:    126.8K
 * Total Submissions: 339.3K
 * Testcase Example:  '[2,1,3]\n1'
 *
 * Given a binary search tree and a node in it, find the in-order successor of
 * that node in the BST.
 *
 * The successor of a node p is the node with the smallest key greater than
 * p.val.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [2,1,3], p = 1
 * Output: 2
 * Explanation: 1's in-order successor node is 2. Note that both p and the
 * return value is of TreeNode type.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,null,1], p = 6
 * Output: null
 * Explanation: There is no in-order successor of the current node, so the
 * answer is null.
 *
 *
 *
 *
 * Note:
 *
 *
 * If the given node has no in-order successor in the tree, return null.
 * It's guaranteed that the values of the tree are unique.
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
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        stack<TreeNode *> stk;
        TreeNode *temp{root}, *prev{nullptr};
        while (!stk.empty() || temp)
        {
            while (temp)
            {
                stk.push(temp);
                temp = temp->left;
            }
            temp = stk.top();
            stk.pop();
            if (prev == p)
                return temp;
            prev = temp;
            temp = temp->right;
        }
        return nullptr;
    }
};
// @lc code=end
