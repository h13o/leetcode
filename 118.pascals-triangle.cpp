/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (48.98%)
 * Likes:    948
 * Dislikes: 85
 * Total Accepted:    311.4K
 * Total Submissions: 634.8K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 0)
            return {};
        if (numRows == 1)
            return {{1}};
        auto vv = generate(numRows - 1);
        vector<int> vec(numRows);
        vec[0] = 1;
        vec[numRows - 1] = 1;
        for (int i = 1; i < numRows - 1; i++)
            vec[i] = vv[numRows - 2][i - 1] + vv[numRows - 2][i];
        vv.push_back(vec);
        return vv;
    }
};
// @lc code=end
