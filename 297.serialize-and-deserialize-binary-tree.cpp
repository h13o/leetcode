/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (43.99%)
 * Likes:    2198
 * Dislikes: 111
 * Total Accepted:    246.8K
 * Total Submissions: 559.7K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 *
 * Example: 
 *
 *
 * You may serialize the following tree:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 *
 * as "[1,2,3,null,null,4,5]"
 *
 *
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 *
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
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
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string str;
        queue<TreeNode *> que;
        que.push(root);
        bool check{root ? true : false};
        int num{1};
        while (check)
        {
            check = false;
            for (int i = 0; i < num; i++)
            {
                TreeNode *temp = que.front();
                que.pop();
                if (!temp)
                {
                    str += "#,";
                    que.push(nullptr);
                    que.push(nullptr);
                }
                else
                {
                    str += to_string(temp->val) + ",";
                    if (temp->left || temp->right)
                        check = true;
                    que.push(temp->left);
                    que.push(temp->right);
                }
            }
            num *= 2;
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;
        int idx{};
        bool neg{};
        queue<TreeNode *> que1, que2;
        while (idx < data.size())
        {
            if (data[idx] == '#')
            {
                que1.push(nullptr);
                idx++;
            }
            else if (data[idx] == '-')
                neg = true;
            else if (isdigit(data[idx]))
            {
                int num{};
                while (isdigit(data[idx]))
                {
                    num = num * 10 + data[idx++] - '0';
                }
                num = neg ? -num : num;
                neg = false;
                que1.push(new TreeNode(num));
            }
            idx++;
        }
        TreeNode *root = que1.front();
        que2.push(que1.front());
        que1.pop();
        while (!que1.empty())
        {
            TreeNode *temp = que2.front();
            que2.pop();
            if (temp)
                temp->left = que1.front();
            que2.push(que1.front());
            que1.pop();
            if (temp)
                temp->right = que1.front();
            que2.push(que1.front());
            que1.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
