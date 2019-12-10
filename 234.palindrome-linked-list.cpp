/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (37.45%)
 * Likes:    2152
 * Dislikes: 299
 * Total Accepted:    324.8K
 * Total Submissions: 867.1K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Example 1:
 *
 *
 * Input: 1->2
 * Output: false
 *
 * Example 2:
 *
 *
 * Input: 1->2->2->1
 * Output: true
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;
        if (!head->next->next)
        {
            if (head->val == head->next->val)
                return true;
            else
                return false;
        }
        ListNode *r{head}, *w{head}; //r= runner, w= walker
        bool even{};
        while (r->next && r->next->next)
        {
            w = w->next;
            r = r->next->next;
            if (r->next && !r->next->next)
                even = true;
        }
        ListNode *fe, *ss; // fe =first_end, ss = second_start;
        fe = even ? w->next : w;
        ss = w->next;
        w = head;
        ListNode *pw{NULL}, *nw;
        while (w != fe)
        {
            nw = w->next;
            w->next = pw;
            pw = w;
            w = nw;
        }
        while (pw)
        {
            if (pw->val != ss->val)
                return false;
            pw = pw->next;
            ss = ss->next;
        }
        return true;
    }
};
// @lc code=end
