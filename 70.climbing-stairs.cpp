/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (45.59%)
 * Likes:    2980
 * Dislikes: 101
 * Total Accepted:    523.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * Note: Given n will be a positive integer.
 *
 * Example 1:
 *
 *
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 *
 *
 * Example 2:
 *
 *
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 4)
            return n;
        int curr{3}, prev{2}, temp;
        for (int i = 3; i < n; i++)
        {
            temp = curr;
            curr += prev;
            prev = temp;
        }
        return curr;
    }
};
// @lc code=end

// class Solution
// {
//     unordered_map<int, int> memo;

// public:
//     int climbStairs(int n)
//     {
//         if (n <= 2)
//             return n;
//         if (memo.find(n) != memo.end())
//             return memo[n];
//         memo[n] = climbStairs(n - 2) + climbStairs(n - 1);
//         return memo[n];
//     }
// };
