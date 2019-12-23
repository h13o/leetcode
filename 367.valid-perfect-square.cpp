/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (40.62%)
 * Likes:    569
 * Dislikes: 128
 * Total Accepted:    136K
 * Total Submissions: 334.4K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 *
 * Note: Do not use any built-in library function such as sqrt.
 *
 * Example 1:
 *
 *
 *
 * Input: 16
 * Output: true
 *
 *
 *
 * Example 2:
 *
 *
 * Input: 14
 * Output: false
 *
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 1)
            return true;
        int l{0}, r{num}, m;
        while (r - l > 1)
        {
            m = l + (r - l) / 2;
            if (num % m == 0 && num / m == m)
                return true;
            else if (num / m >= m)
                l = m;
            else
                r = m;
        }
        return false;
    }
};
// @lc code=end
