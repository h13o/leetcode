/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> nm;
        helper(node, nm);
        return nm[node];
    }
    void helper(Node *node, unordered_map<Node *, Node *> &nm)
    {
        Node *cn = new Node();
        nm[node] = cn;
        cn->val = node->val;
        for (auto nbr : node->neighbors)
        {
            if (nm.find(nbr) == nm.end())
                helper(nbr, nm);
            cn->neighbors.push_back(nm[nbr]);
        }
    }
};
// @lc code=end
