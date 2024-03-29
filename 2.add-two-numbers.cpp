/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (32.31%)
 * Likes:    6585
 * Dislikes: 1713
 * Total Accepted:    1.1M
 * Total Submissions: 3.5M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example:
 *
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 *
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return rec(l1, l2, false);
    }
    ListNode *rec(ListNode *l1, ListNode *l2, bool carried)
    {
        if (!l1 && !l2 && !carried)
            return nullptr;
        int val{carried};
        if (l1)
        {
            val += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            val += l2->val;
            l2 = l2->next;
        }
        ListNode *temp = new ListNode(val % 10);
        temp->next = rec(l1, l2, val > 9);
        return temp;
    }
};
// @lc code=end
