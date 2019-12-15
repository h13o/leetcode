/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (32.48%)
 * Likes:    972
 * Dislikes: 1609
 * Total Accepted:    450.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 *
 * Example 1:
 *
 *
 * Input: 4
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since
 * the decimal part is truncated, 2 is returned.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        long long ok{0}, ng{65536}, m;
        while (ng - ok > 1)
        {
            m = (ok + ng) / 2;
            m *m <= x ? ok = m : ng = m;
        }
        return ok;
    }
};
// @lc code=end
