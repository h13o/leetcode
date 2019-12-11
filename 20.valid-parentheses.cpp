/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.67%)
 * Likes:    3713
 * Dislikes: 182
 * Total Accepted:    775.4K
 * Total Submissions: 2.1M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: "{[]}"
 * Output: true
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> cs; // char_stack
        for (auto c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                cs.push(c);
                continue;
            }
            else if (!cs.empty() && (c == ')' && cs.top() == '(' || c == '}' && cs.top() == '{' || c == ']' && cs.top() == '['))
            {
                cs.pop();
            }
            else
                return false;
        }
        return cs.empty() ? true : false;
    }
};
// @lc code=end
