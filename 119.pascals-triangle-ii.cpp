/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (46.08%)
 * Likes:    588
 * Dislikes: 182
 * Total Accepted:    238.8K
 * Total Submissions: 517.6K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 *
 * Note that the row index starts from 0.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 3
 * Output: [1,3,3,1]
 *
 *
 * Follow up:
 *
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans(rowIndex + 1);
        ans[0] = 1;
        for (int i = 1; i <= rowIndex; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                ans[j + 1] += ans[j];
            }
        }
        return ans;
    }
};
// @lc code=end

// vector<int> getRow(int rowIndex)
// {
//     if (rowIndex == 0)
//         return {1};
//     vector<int> prev{getRow(rowIndex - 1)}, curr(rowIndex + 1);
//     curr[0] = curr[rowIndex] = 1;
//     for (int i = 1; i < rowIndex; i++)
//         curr[i] = prev[i - 1] + prev[i];
//     return curr;
// }
