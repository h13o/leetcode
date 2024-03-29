/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (38.87%)
 * Likes:    2021
 * Dislikes: 291
 * Total Accepted:    499.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given a linked list, determine if it has a cycle in it.
 *
 * To represent a cycle in the given linked list, we use an integer pos which
 * represents the position (0-indexed) in the linked list where tail connects
 * to. If pos is -1, then there is no cycle in the linked list.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * second node.
 *
 *
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2], pos = 0
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * first node.
 *
 *
 *
 *
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1], pos = -1
 * Output: false
 * Explanation: There is no cycle in the linked list.
 *
 *
 *
 *
 *
 *
 *
 * Follow up:
 *
 * Can you solve it using O(1) (i.e. constant) memory?
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
    bool hasCycle(ListNode *head)
    {
        ListNode *wker(head), *rner(head);
        while (true)
        {
            if (!rner || !rner->next)
                return false;
            rner = rner->next->next;
            wker = wker->next;
            if (rner == wker)
                break;
        }
        return true;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     bool hasCycle(ListNode *head)
//     {
//         ListNode *n1{head}, *n2{head};
//         int times{0};
//         while (++times)
//         {
//             for (int i = 0; i < times; i++)
//             {
//                 if (!n2)
//                     return false;
//                 n2 = n2->next;
//                 if (n2 == n1)
//                     return true;
//             }
//             n1 = n2;
//         }
//         return true;
//     }
// };
