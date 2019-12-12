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
        while (find(s.begin(), s.end(), '[') != s.end())
        {
            int left{-1}, l{-1}, multi;
            cout << s << endl;
            for (size_t i = 0; i < s.size(); i++)
            {
                if (s[i] == '[')
                {
                    left = l = i;
                    multi = 0;
                    while (left > 0)
                    {
                        int c = s[--left];
                        int num = c - int('0');
                        cout << num << endl;
                        if (num < 0 && num > 9)
                            break;
                        multi *= 10;
                        multi += num;
                    }
                }
                if (s[i] == ']')
                {
                    string t;
                    if (l - to_string(multi).size())
                        t = s.substr(0, l - to_string(multi).size());
                    for (int k = 0; k < multi; k++)
                        t += s.substr(l + 1, i - (l + 1));
                    t += s.substr(i + 1);
                    cout << t << endl;
                    s = t;
                    break;
                }
            }
        }
        return s;
    }
};
// @lc code=end
