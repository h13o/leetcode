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
        if (!root)
            return "[]";
        string ans{"["};
        queue<TreeNode *> que;
        que.push(root);
        while (true)
        {
            bool null_check{true};
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = que.front();
                que.pop();
                if (temp && (temp->right || temp->left))
                {
                    null_check = false;
                    que.push(temp->left);
                    que.push(temp->right);
                }
                else
                {
                    que.push(nullptr);
                    que.push(nullptr);
                }
                ans += temp ? to_string(temp->val) : "null";
                if (!null_check || i != size - 1)
                    ans += ",";
            }
            if (null_check)
                break;
        }
        ans += "]";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *
    deserialize(string data)
    {
        if (data == "[]")
            return nullptr;
        int idx{}, layer{};
        int comma{count(data.begin(), data.end(), ',')};
        vector<TreeNode *> vec;
        while (comma >= layer * 2 - 1)
            layer++;
        while (++idx)
        {
            if (data[idx] == 'n')
            {
                vec.push_back(nullptr);
                idx += 4;
                continue;
            }
            int num = 0;
            while (data[idx] != ',' && data[idx] != ']')
            {
                num *= 10;
                num += (int)data[idx] - (int)'0';
                idx++;
            }
            TreeNode *temp = new TreeNode(num);
            vec.push_back(temp);
            if (data[idx] == ']')
                break;
        }
        for (int i = 0; i < vec.size(); i++)
        {
            if (i == 0 && !vec[(i - 1) / 2])
                continue;
            if (i % 2)
            {
                vec[(i - 1) / 2]->left = vec[i];
            }
            else
            {
                vec[(i - 1) / 2]->right = vec[i];
            }
        }
        return vec[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
