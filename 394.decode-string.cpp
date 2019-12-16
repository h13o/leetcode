/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (47.31%)
 * Likes:    2180
 * Dislikes: 116
 * Total Accepted:    150.5K
 * Total Submissions: 317.8K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 *
 * Examples:
 *
 *
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 *
 *
 *
 *
 */

// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        int num{};
        string str;
        int i = 0;
        while (i < s.size())
        {
            if (isdigit(s[i]))
            {
                num *= 10;
                num += (int)s[i++] - (int)'0';
                continue;
            }
            if (s[i] == '[')
            {
                int idx{i + 1}, inner{1};
                while (i++)
                {
                    if (s[i] == '[')
                        inner++;
                    if (s[i] == ']')
                        inner--;
                    if (!inner)
                        break;
                }
                while (num)
                {
                    num--;
                    str += decodeString(s.substr(idx, i - idx));
                }
                i++;
                continue;
            }
            str += s[i++];
        }
        return str;
    }
};
// @lc code=end
