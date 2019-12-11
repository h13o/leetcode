/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (43.59%)
 * Likes:    1909
 * Dislikes: 160
 * Total Accepted:    225.8K
 * Total Submissions: 517.6K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * Example 1:
 *
 *
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 *
 * Example 2:
 *
 *
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> ans(n);
        vector<int> sqs;
        queue<int> que;
        for (int i = 1; i <= (int)sqrt(n); i++)
        {
            sqs.push_back(i * i);
            ans[i * i - 1] = 1;
            if (i * i == n)
                return 1;
            que.push(i * i - 1);
        }
        while (!que.empty())
        {
            int index = que.front();
            que.pop();
            for (auto i : sqs){
                if (index+i < n && ans[index +i] == 0){
                    ans[index+i] = ans[index] + 1;
                    if (index + i == n-1) return ans.back();
                    que.push(index+i);
                }
            }
        }
        return ans.back();
    }
};
// @lc code=end
