/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (46.03%)
 * Likes:    1785
 * Dislikes: 82
 * Total Accepted:    122.4K
 * Total Submissions: 265.9K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 *
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 *
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.
 *
 *
 * Example 1:
 *
 * Input: nums is [1, 1, 1, 1, 1], S is 3.
 * Output: 5
 * Explanation:
 *
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 *
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 *
 *
 *
 * Note:
 *
 * The length of the given array is positive and will not exceed 20.
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 *
 *
 */

// @lc code=start
class Solution
{
    vector<vector<int>> dp = vector<vector<int>>(21, vector<int>(2010));

public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        dp[0][1005] = 1;
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < 2010; j++)
            {
                if (dp[i][j] == 0)
                    continue;
                if (j + nums[i] < 2010)
                    dp[i + 1][j + nums[i]] += dp[i][j];
                if (0 <= j - nums[i])
                    dp[i + 1][j - nums[i]] += dp[i][j];
            }
        }
        if (S > 1000)
            return 0;
        return dp[nums.size()][S + 1005];
    }
};
// @lc code=end

// Memory Limit Exceeded
// class Solution
// {
//     int count{};
//     int TS;

// public:
//     int findTargetSumWays(vector<int> &nums, int S)
//     {
//         TS = S;
//         helper(nums, 0, 0);
//         return count;
//     }
//     void helper(vector<int> nums, int idx, int sum)
//     {
//         if (idx == nums.size())
//         {
//             if (sum == TS)
//                 count++;
//             return;
//         }
//         helper(nums, idx + 1, sum + nums[idx]);
//         helper(nums, idx + 1, sum - nums[idx]);
//     }
// };
