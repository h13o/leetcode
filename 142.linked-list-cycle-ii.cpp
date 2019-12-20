/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (34.33%)
 * Likes:    1914
 * Dislikes: 154
 * Total Accepted:    258.6K
 * Total Submissions: 751.3K
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 *
 * To represent a cycle in the given linked list, we use an integer pos which
 * represents the position (0-indexed) in the linked list where tail connects
 * to. If pos is -1, then there is no cycle in the linked list.
 *
 * Note: Do not modify the linked list.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * second node.
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * first node.
 *
 *
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 *
 *
 *
 *
 *
 *
 * Follow-up:
 * Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *rner{head}, *wker{head};
        while (true)
        {
            if (!rner || !rner->next)
                return nullptr;
            rner = rner->next->next;
            wker = wker->next;
            if (rner == wker)
                break;
        }
        rner = head;
        while (rner != wker)
        {
            rner = rner->next;
            wker = wker->next;
        }
        return rner;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     ListNode *detectCycle(ListNode *head)
//     {
//         ListNode *rner{head}, *wker{head};
//         bool check_loop{};
//         int count{};
//         while (true)
//         {
//             if (!rner || !rner->next)
//                 return nullptr;
//             if (check_loop)
//                 count++;
//             rner = rner->next->next;
//             wker = wker->next;
//             if (rner == wker)
//             {
//                 if (check_loop)
//                     break;
//                 else
//                     check_loop = true;
//             }
//         }
//         wker = head;
//         while (true)
//         {
//             ListNode *temp = wker;
//             for (int i = 0; i < count; i++)
//             {
//                 temp = temp->next;
//             }
//             if (wker == temp)
//                 return wker;
//             wker = wker->next;
//         }
//     }
// };
