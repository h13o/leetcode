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
        int max_square{};
        while (n >= pow(max_square + 1, 2))
            max_square++;
        int min_count{INT_MAX};
        for (int i = 1; i <= max_square; i++)
        {
            int temp{n};
            int count{};
            for (int j = i; j > 0; j--)
            {
                int jj = j * j;
                if (temp - jj >= 0)
                {
                    int times{temp / jj};
                    temp -= jj * times;
                    count += times;
                }
            }
            min_count = min(min_count, count);
        }
        return min_count;
    }
};
// @lc code=end
