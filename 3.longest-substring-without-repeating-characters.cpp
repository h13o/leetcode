/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (29.21%)
 * Likes:    7151
 * Dislikes: 423
 * Total Accepted:    1.2M
 * Total Submissions: 4.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution
{

public:
    int lengthOfLongestSubstring(string s)
    {
    }
};
// @lc code=end

// class Solution
// {
//     unordered_map<char, int> map;

// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         int ans{}, max_ans{}, idx{};
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (map.find(s[i]) != map.end())
//             {
//                 max_ans = max(max_ans, ans);
//                 idx = max(idx, map[s[i]]);
//                 ans = i - idx - 1;
//             }
//             ans++;
//             map[s[i]] = i;
//         }
//         return max(max_ans, ans);
//     }
// };
