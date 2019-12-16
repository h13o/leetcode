/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower/description/
 *
 * algorithms
 * Easy (40.86%)
 * Likes:    295
 * Dislikes: 1414
 * Total Accepted:    126.8K
 * Total Submissions: 310K
 * Testcase Example:  '10\n6'
 *
 * We are playing the Guess Game. The game is as follows:
 *
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you guess wrong, I'll tell you whether the number is higher or
 * lower.
 *
 * You call a pre-defined API guess(int num) which returns 3 possible results
 * (-1, 1, or 0):
 *
 *
 * -1 : My number is lower
 * ⁠1 : My number is higher
 * ⁠0 : Congrats! You got it!
 *
 *
 * Example :
 *
 *
 *
 * Input: n = 10, pick = 6
 * Output: 6
 *
 *
 *
 */

// @lc code=start
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution
{
public:
    int guessNumber(int n)
    {
        int l{0}, r{n}, m;
        while (r - l > 1)
        {
            m = l + (r - l) / 2;
            if (guess(m) == 0)
                return m;
            if (guess(m) == 1)
                l = m;
            if (guess(m) == -1)
                r = m;
        }
        return r;
    }
};
// @lc code=end
