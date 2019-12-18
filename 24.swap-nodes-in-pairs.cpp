/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (47.32%)
 * Likes:    1590
 * Dislikes: 137
 * Total Accepted:    384K
 * Total Submissions: 810.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 *
 * Example:
 *
 *
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *next = head->next;
        head->next = next->next;
        next->next = head;
        head = next;
        head->next->next = swapPairs(head->next->next);
        return head;
    }
};
// @lc code=end

// ListNode *swapPairs(ListNode *head)
// {
//     if (!head || !head->next)
//         return head;
//     ListNode *temp = head->next;
//     head->next = head->next->next;
//     temp->next = head;
//     head = temp;
//     head->next->next = swapPairs(head->next->next);
//     return head;
// }
